
#include "../include/mainwindow.h"

#include <windows.h>
#include<QAction>
#include <QCheckBox>
#include <QInputDialog>
#include <QMdiArea>
#include <QMdiSubWindow>
#include<QMessageBox>
#include<QFileDialog>
#include<QDebug>
#include<QStylePainter>
#include<QTime>
#include <QTimer>

#include "../include/channeldialog.h"
#include "../include/channeltabwidget.h"
#include "../include/demarcate.h"
#include "../include/fftdialog.h"
#include "../include/global.h"
#include "../include/MT_emxAPI.h"
#include "../include/MT_emxutil.h"
#include "../include/myfft_N.h"
#include "../include/sensordialog.h"
#include "../include/triggermodedialog.h"
#include "../ui/ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui_ptr_(new Ui::main_window)
{
    ui_ptr_->setupUi(this);
    setWindowTitle(tr("多通道高速光纤法珀测力系统"));
    // setWindowFlags(Qt::CustomizeWindowHint | Qt::WindowMinMaxButtonsHint);
    // ui_ptr_->action_fft->setEnabled(false);

    ui_ptr_->action_stop->setEnabled(false);
    ui_ptr_->action_save->setEnabled(false);
    ui_ptr_->action_image_save->setEnabled(false);
    save_depth_ = 0;  // 默认每次保存当前的250采样值
    moving_average_count_ = 1;  // 默认滑动平均次数


    USB_device_ = NULL;
    command_end_point_ = NULL;
    in_end_point_ = NULL;
    continuous_collect_timer_ptr_ = NULL;

    check_box_fft_ptr_ = new QCheckBox(QString("FFT"), this);
    ui_ptr_->tool_bar_data_deal->addWidget(check_box_fft_ptr_);

    check_box_moving_average_ptr_ = new QCheckBox(QString("滑动平均"), this);
    ui_ptr_->tool_bar_data_deal->addWidget(check_box_moving_average_ptr_);

    mdi_area_ptr_ = new QMdiArea;
    setCentralWidget(mdi_area_ptr_);
    // qDebug() << mdi_area_ptr_->x() << mdi_area_ptr_->y() << mdi_area_ptr_->width() << mdi_area_ptr_->height();

    continuous_collect_timer_ptr_ = new MMTimer(28);

    connect(ui_ptr_->exit,SIGNAL(triggered()), this, SLOT(OnExit()));
    connect(ui_ptr_->action_instrument_1, SIGNAL(triggered(bool)), this, SLOT(OnActionInstrument1(bool)));
    connect(ui_ptr_->action_instrument_2, SIGNAL(triggered(bool)), this, SLOT(OnActionInstrument2(bool)));
    connect(ui_ptr_->action_instrument_3, SIGNAL(triggered(bool)), this, SLOT(OnActionInstrument3(bool)));
    connect(ui_ptr_->action_instrument_4, SIGNAL(triggered(bool)), this, SLOT(OnActionInstrument4(bool)));
    connect(ui_ptr_->action_instrument_5, SIGNAL(triggered(bool)), this, SLOT(OnActionInstrument5(bool)));

    connect(ui_ptr_->action_channel_1, SIGNAL(triggered(bool)), this, SLOT(OnActionChannel1(bool)));
    connect(ui_ptr_->action_channel_2, SIGNAL(triggered(bool)), this, SLOT(OnActionChannel2(bool)));
    connect(ui_ptr_->action_channel_3, SIGNAL(triggered(bool)), this, SLOT(OnActionChannel3(bool)));
    connect(ui_ptr_->action_channel_4, SIGNAL(triggered(bool)), this, SLOT(OnActionChannel4(bool)));
    connect(ui_ptr_->action_channel_5, SIGNAL(triggered(bool)), this, SLOT(OnActionChannel5(bool)));
    connect(ui_ptr_->action_channel_6, SIGNAL(triggered(bool)), this, SLOT(OnActionChannel6(bool)));

    connect(ui_ptr_->action_trigger_channel_1, SIGNAL(triggered(bool)), this, SLOT(OnActionTriggerChannel1(bool)));
    connect(ui_ptr_->action_trigger_channel_2, SIGNAL(triggered(bool)), this, SLOT(OnActionTriggerChannel2(bool)));
    connect(ui_ptr_->action_trigger_channel_3, SIGNAL(triggered(bool)), this, SLOT(OnActionTriggerChannel3(bool)));
    connect(ui_ptr_->action_trigger_channel_4, SIGNAL(triggered(bool)), this, SLOT(OnActionTriggerChannel4(bool)));
    connect(ui_ptr_->action_trigger_channel_5, SIGNAL(triggered(bool)), this, SLOT(OnActionTriggerChannel5(bool)));
    connect(ui_ptr_->action_trigger_channel_6, SIGNAL(triggered(bool)), this, SLOT(OnActionTriggerChannel6(bool)));

    connect(ui_ptr_->action_select_all, SIGNAL(triggered(bool)), this, SLOT(OnActionSelectAll(bool)));

    connect(ui_ptr_->action_collect, SIGNAL(triggered(bool)), this, SLOT(OnStart()));
    connect(ui_ptr_->action_save, SIGNAL(triggered(bool)), this, SLOT(OnDataSave()));
    connect(ui_ptr_->action_image_save, SIGNAL(triggered(bool)), this, SLOT(OnImageSave()));
    connect(ui_ptr_->action_stop, SIGNAL(triggered(bool)), this, SLOT(OnStop()));
    connect(ui_ptr_->action_save_depth, SIGNAL(triggered(bool)), this, SLOT(OnSaveDepth()));
    connect(ui_ptr_->action_fft, SIGNAL(triggered(bool)), this, SLOT(OnActionFFT(bool)));
    connect(check_box_fft_ptr_, SIGNAL(toggled(bool)), this, SLOT(OnActionFFT(bool)));
    connect(check_box_moving_average_ptr_, SIGNAL(toggled(bool)), this, SLOT(OnActionMovingAverage(bool)));
    connect(ui_ptr_->action_sensor_debug, SIGNAL(triggered(bool)), this, SLOT(OnSensorDebug()));
    connect(continuous_collect_timer_ptr_, SIGNAL(timeout()), this, SLOT(OnContinuousCollect()));

    Init();
}

MainWindow::~MainWindow()
{
    // qDebug() << "main window 析构";
    //if (channel_tab_1_ptr!= NULL)
    //{
    //    // channel_tab_1_ptr_->close();
    //    delete channel_tab_1_ptr;
    //    channel_tab_1_ptr = NULL;
    //}

    //if (channel_tab_2_ptr != NULL)
    //{
    //    delete channel_tab_2_ptr;
    //    channel_tab_2_ptr = NULL;
    //}

    if (!continuous_collect_timer_ptr_)
    {
        delete continuous_collect_timer_ptr_;
        continuous_collect_timer_ptr_ = NULL;
    }

    cavity_channel_1_save_queue_.clear();
    cavity_channel_2_save_queue_.clear();
    cavity_channel_3_save_queue_.clear();
    cavity_channel_4_save_queue_.clear();
    cavity_channel_5_save_queue_.clear();
    cavity_channel_6_save_queue_.clear();

    if (mdi_area_ptr_ != NULL)
    {
        // qDebug() << mdi_area_ptr_->subWindowList().count();
        if (mdi_area_ptr_->subWindowList().count() > 0)
        {
            mdi_area_ptr_->closeAllSubWindows();
        }
        
        delete mdi_area_ptr_;
        mdi_area_ptr_ = NULL;
    }

    delete ui_ptr_;
    ui_ptr_ = NULL;
}

// 计算腔长
void MainWindow::CalculateCavity(int* pixel_array)
{
    // 数据识别
    int identify_index = 0;

    for (int i = 1; i != kChannelDataLength; ++i)
    {
        if (pixel_array[i] != 3001)
        {
            identify_index = i;
            break;
        }
    }

    for (int i = 0; i != kChannelDataLength; ++i)
    {
        // 通道1
        cavity_channel_1_array_[i] = CalculateCavityByPixelNumber(fitting_count_1_, fitting_factor_channel_1_array_, pixel_array[i + identify_index]);

        // 通道2
        cavity_channel_2_array_[i] = CalculateCavityByPixelNumber(fitting_count_2_, fitting_factor_channel_2_array_,
                                                                  pixel_array[i + identify_index + kChannelDataLength]);

        // 通道3
        cavity_channel_3_array_[i] = CalculateCavityByPixelNumber(fitting_count_3_, fitting_factor_channel_3_array_,
                                                                  pixel_array[i +identify_index + 2 * kChannelDataLength]);

        // 通道4
        cavity_channel_4_array_[i] = CalculateCavityByPixelNumber(fitting_count_4_, fitting_factor_channel_4_array_,
                                                                  pixel_array[i + identify_index + 3 * kChannelDataLength]);

        // 通道5
        cavity_channel_5_array_[i] = CalculateCavityByPixelNumber(fitting_count_5_, fitting_factor_channel_5_array_,
                                                                  pixel_array[i + identify_index + 4 * kChannelDataLength]);

        // 通道6
        cavity_channel_6_array_[i] = CalculateCavityByPixelNumber(fitting_count_6_, fitting_factor_channel_6_array_,
                                                                  pixel_array[i + identify_index + 5 * kChannelDataLength]);

        //// 通道1
        //cavity_channel_1_array_[i] = CalculateCavityByPixelNumber(fitting_count_1_, fitting_factor_channel_1_array_, pixel_array[i]) / kMaxPixelNumber;

        //// 通道2
        //cavity_channel_2_array_[i] = CalculateCavityByPixelNumber(fitting_count_2_, fitting_factor_channel_2_array_, pixel_array[i + kChannelDataLength]) / kMaxPixelNumber;

        //// 通道3
        //cavity_channel_3_array_[i] = CalculateCavityByPixelNumber(fitting_count_3_, fitting_factor_channel_3_array_, pixel_array[i + 2 * kChannelDataLength]) / kMaxPixelNumber;

        //// 通道4
        //cavity_channel_4_array_[i] = CalculateCavityByPixelNumber(fitting_count_4_, fitting_factor_channel_4_array_, pixel_array[i + 3 * kChannelDataLength]) / kMaxPixelNumber;

        //// 通道5
        //cavity_channel_5_array_[i] = CalculateCavityByPixelNumber(fitting_count_5_, fitting_factor_channel_5_array_, pixel_array[i + 4 * kChannelDataLength]) / kMaxPixelNumber;

        //// 通道6
        //cavity_channel_6_array_[i] = CalculateCavityByPixelNumber(fitting_count_6_, fitting_factor_channel_6_array_, pixel_array[i + 5 * kChannelDataLength]) / kMaxPixelNumber;

        //// 通道1
        //cavity_channel_1_array_[i] = CalculateCavityByPixelNumber(fitting_count_1_, fitting_factor_channel_1_array_, pixel_array[i]);

        //// 通道2
        //cavity_channel_2_array_[i] = CalculateCavityByPixelNumber(fitting_count_2_, fitting_factor_channel_2_array_, pixel_array[i + kChannelDataLength]);

        //// 通道3
        //cavity_channel_3_array_[i] = CalculateCavityByPixelNumber(fitting_count_3_, fitting_factor_channel_3_array_, pixel_array[i + 2 * kChannelDataLength]);

        //// 通道4
        //cavity_channel_4_array_[i] = CalculateCavityByPixelNumber(fitting_count_4_, fitting_factor_channel_4_array_, pixel_array[i + 3 * kChannelDataLength]);

        //// 通道5
        //cavity_channel_5_array_[i] = CalculateCavityByPixelNumber(fitting_count_5_, fitting_factor_channel_5_array_, pixel_array[i + 4 * kChannelDataLength]);

        //// 通道6
        //cavity_channel_6_array_[i] = CalculateCavityByPixelNumber(fitting_count_6_, fitting_factor_channel_6_array_, pixel_array[i + 5 * kChannelDataLength]);

    }

    if (check_box_moving_average_ptr_->isChecked() && (moving_average_count_ > 2))
    {
        MovingAverage(cavity_channel_1_array_, kChannelDataLength, moving_average_count_);
        MovingAverage(cavity_channel_2_array_, kChannelDataLength, moving_average_count_);
        MovingAverage(cavity_channel_3_array_, kChannelDataLength, moving_average_count_);
        MovingAverage(cavity_channel_4_array_, kChannelDataLength, moving_average_count_);
        MovingAverage(cavity_channel_5_array_, kChannelDataLength, moving_average_count_);
        MovingAverage(cavity_channel_6_array_, kChannelDataLength, moving_average_count_);
    }

    //// 通道5和通道6的最后三个数据有问题，全部替换成第247个数据
    //for (int i = 0; i != 3; ++i)
    //{
    //    cavity_channel_5_array_[247 + i] = cavity_channel_5_array_[246];
    //    cavity_channel_6_array_[247 + i] = cavity_channel_6_array_[246];
    //}

    //// 通道5的数据全部改成400
    //for (int i = 0; i != kChannelDataLength; ++i)
    //{
    //    cavity_channel_5_array_[i] = 400;
    //}

    // 保存队列更新
    for (int i = 0; i != kChannelDataLength; ++i)
    {
        // 通道1
        if (!is_trigger_limit_channel_1_)
        {
            cavity_channel_1_save_queue_.enqueue(cavity_channel_1_array_[i]);
        }
        

        if (save_depth_ > 0)
        {
            if (cavity_channel_1_save_queue_.length() > kChannelSaveDataLengthPerSecond * save_depth_)
            {
                cavity_channel_1_save_queue_.dequeue();
            }
        }
        else
        {
            if (cavity_channel_1_save_queue_.length() > kChannelDataLength)
            {
                cavity_channel_1_save_queue_.dequeue();
            }
        }

        // 通道2
        if (!is_trigger_limit_channel_2_)
        {
            cavity_channel_2_save_queue_.enqueue(cavity_channel_2_array_[i]);
        }

        if (save_depth_ > 0)
        {
            if (cavity_channel_2_save_queue_.length() > kChannelSaveDataLengthPerSecond * save_depth_)
            {
                cavity_channel_2_save_queue_.dequeue();
            }
        }
        else
        {
            if (cavity_channel_2_save_queue_.length() > kChannelDataLength)
            {
                cavity_channel_2_save_queue_.dequeue();
            }
        }


        // 通道3
        if (!is_trigger_limit_channel_3_)
        {
            cavity_channel_3_save_queue_.enqueue(cavity_channel_3_array_[i]);
        }

        if (save_depth_ > 0)
        {
            if (cavity_channel_3_save_queue_.length() > kChannelSaveDataLengthPerSecond * save_depth_)
            {
                cavity_channel_3_save_queue_.dequeue();
            }
        }
        else
        {
            if (cavity_channel_3_save_queue_.length() > kChannelDataLength)
            {
                cavity_channel_3_save_queue_.dequeue();
            }
        }


        // 通道4
        if (!is_trigger_limit_channel_4_)
        {
            cavity_channel_4_save_queue_.enqueue(cavity_channel_4_array_[i]);
        }

        if (save_depth_ > 0)
        {
            if (cavity_channel_4_save_queue_.length() > kChannelSaveDataLengthPerSecond * save_depth_)
            {
                cavity_channel_4_save_queue_.dequeue();
            }
        }
        else
        {
            if (cavity_channel_4_save_queue_.length() > kChannelDataLength)
            {
                cavity_channel_4_save_queue_.dequeue();
            }
        }


        // 通道5
        if (!is_trigger_limit_channel_5_)
        {
            cavity_channel_5_save_queue_.enqueue(cavity_channel_5_array_[i]);
        }

        if (save_depth_ > 0)
        {
            if (cavity_channel_5_save_queue_.length() > kChannelSaveDataLengthPerSecond * save_depth_)
            {
                cavity_channel_5_save_queue_.dequeue();
            }
        }
        else
        {
            if (cavity_channel_5_save_queue_.length() > kChannelDataLength)
            {
                cavity_channel_5_save_queue_.dequeue();
            }
        }


        // 通道6
        if (!is_trigger_limit_channel_6_)
        {
            cavity_channel_6_save_queue_.enqueue(cavity_channel_6_array_[i]);
        }

        if (save_depth_ > 0)
        {
            if (cavity_channel_6_save_queue_.length() > kChannelSaveDataLengthPerSecond * save_depth_)
            {
                cavity_channel_6_save_queue_.dequeue();
            }
        }
        else
        {
            if (cavity_channel_6_save_queue_.length() > kChannelDataLength)
            {
                cavity_channel_6_save_queue_.dequeue();
            }
        }
    }
}


// 计算力
void MainWindow::CalculatePower(int* pixel_array)
{
    for (int i = 0; i != kChannelDataLength; ++i)
    {
        // 通道1
        cavity_channel_1_array_[i] = CalculatePowerByPixelNumber(fitting_count_1_, fitting_factor_channel_1_array_, pixel_array[i]);

        // 通道2
        cavity_channel_2_array_[i] = CalculatePowerByPixelNumber(fitting_count_2_, fitting_factor_channel_2_array_, pixel_array[i + kChannelDataLength]);

        // 通道3
        cavity_channel_3_array_[i] = CalculatePowerByPixelNumber(fitting_count_3_, fitting_factor_channel_3_array_, pixel_array[i + 2 * kChannelDataLength]);

        // 通道4
        cavity_channel_4_array_[i] = CalculatePowerByPixelNumber(fitting_count_4_, fitting_factor_channel_4_array_, pixel_array[i + 3 * kChannelDataLength]);

        // 通道5
        cavity_channel_5_array_[i] = CalculatePowerByPixelNumber(fitting_count_5_, fitting_factor_channel_5_array_, pixel_array[i + 6 * kChannelDataLength]);

        // 通道6
        cavity_channel_6_array_[i] = CalculatePowerByPixelNumber(fitting_count_6_, fitting_factor_channel_6_array_, pixel_array[i + 5 * kChannelDataLength]);

    }

    if (check_box_moving_average_ptr_->isChecked() && (moving_average_count_ > 2))
    {
        MovingAverage(cavity_channel_1_array_, kChannelDataLength, moving_average_count_);
        MovingAverage(cavity_channel_2_array_, kChannelDataLength, moving_average_count_);
        MovingAverage(cavity_channel_3_array_, kChannelDataLength, moving_average_count_);
        MovingAverage(cavity_channel_4_array_, kChannelDataLength, moving_average_count_);
        MovingAverage(cavity_channel_5_array_, kChannelDataLength, moving_average_count_);
        MovingAverage(cavity_channel_6_array_, kChannelDataLength, moving_average_count_);
    }

    // 通道5和通道6的最后三个数据有问题，全部替换成第247个数据
    for (int i = 0; i != 3; ++i)
    {
        cavity_channel_5_array_[247 + i] = cavity_channel_5_array_[246];
        cavity_channel_6_array_[247 + i] = cavity_channel_6_array_[246];
    }

    //// 通道5的数据全部改成400
    //for (int i = 0; i != kChannelDataLength; ++i)
    //{
    //    cavity_channel_5_array_[i] = 400;
    //}

    // 保存队列更新
    for (int i = 0; i != kChannelDataLength; ++i)
    {
        // 通道1
        if (!is_trigger_limit_channel_1_)
        {
            cavity_channel_1_save_queue_.enqueue(cavity_channel_1_array_[i]);
        }


        if (save_depth_ > 0)
        {
            if (cavity_channel_1_save_queue_.length() > kChannelSaveDataLengthPerSecond * save_depth_)
            {
                cavity_channel_1_save_queue_.dequeue();
            }
        }
        else
        {
            if (cavity_channel_1_save_queue_.length() > kChannelDataLength)
            {
                cavity_channel_1_save_queue_.dequeue();
            }
        }

        // 通道2
        if (!is_trigger_limit_channel_2_)
        {
            cavity_channel_2_save_queue_.enqueue(cavity_channel_2_array_[i]);
        }

        if (save_depth_ > 0)
        {
            if (cavity_channel_2_save_queue_.length() > kChannelSaveDataLengthPerSecond * save_depth_)
            {
                cavity_channel_2_save_queue_.dequeue();
            }
        }
        else
        {
            if (cavity_channel_2_save_queue_.length() > kChannelDataLength)
            {
                cavity_channel_2_save_queue_.dequeue();
            }
        }


        // 通道3
        if (!is_trigger_limit_channel_3_)
        {
            cavity_channel_3_save_queue_.enqueue(cavity_channel_3_array_[i]);
        }

        if (save_depth_ > 0)
        {
            if (cavity_channel_3_save_queue_.length() > kChannelSaveDataLengthPerSecond * save_depth_)
            {
                cavity_channel_3_save_queue_.dequeue();
            }
        }
        else
        {
            if (cavity_channel_3_save_queue_.length() > kChannelDataLength)
            {
                cavity_channel_3_save_queue_.dequeue();
            }
        }


        // 通道4
        if (!is_trigger_limit_channel_4_)
        {
            cavity_channel_4_save_queue_.enqueue(cavity_channel_4_array_[i]);
        }

        if (save_depth_ > 0)
        {
            if (cavity_channel_4_save_queue_.length() > kChannelSaveDataLengthPerSecond * save_depth_)
            {
                cavity_channel_4_save_queue_.dequeue();
            }
        }
        else
        {
            if (cavity_channel_4_save_queue_.length() > kChannelDataLength)
            {
                cavity_channel_4_save_queue_.dequeue();
            }
        }


        // 通道5
        if (!is_trigger_limit_channel_5_)
        {
            cavity_channel_5_save_queue_.enqueue(cavity_channel_5_array_[i]);
        }

        if (save_depth_ > 0)
        {
            if (cavity_channel_5_save_queue_.length() > kChannelSaveDataLengthPerSecond * save_depth_)
            {
                cavity_channel_5_save_queue_.dequeue();
            }
        }
        else
        {
            if (cavity_channel_5_save_queue_.length() > kChannelDataLength)
            {
                cavity_channel_5_save_queue_.dequeue();
            }
        }


        // 通道6
        if (!is_trigger_limit_channel_6_)
        {
            cavity_channel_6_save_queue_.enqueue(cavity_channel_6_array_[i]);
        }

        if (save_depth_ > 0)
        {
            if (cavity_channel_6_save_queue_.length() > kChannelSaveDataLengthPerSecond * save_depth_)
            {
                cavity_channel_6_save_queue_.dequeue();
            }
        }
        else
        {
            if (cavity_channel_6_save_queue_.length() > kChannelDataLength)
            {
                cavity_channel_6_save_queue_.dequeue();
            }
        }
    }
}

bool MainWindow::SetSkin()
{
    QString file_name = QString("../source/main_window_skin.qss");
    QFile file(file_name);

    if (QFile::exists(file_name) && file.open(QIODevice::ReadOnly))
    {
        QString temp;
        QTextStream in(&file);
        while (!in.atEnd())
        {
            temp.append(in.readLine());
        }
        file.close();
        setStyleSheet(temp);

        return true;
    }

    return false;
}

void MainWindow::resizeEvent(QResizeEvent *event)
{
    // 通道1
    if (ui_ptr_->action_channel_1->isChecked())
    {
        foreach (QMdiSubWindow* window, mdi_area_ptr_->subWindowList())
        {
            ChannelTabWidget* channel_tab_widget_ptr = qobject_cast<ChannelTabWidget*>(window->widget());

            if (channel_tab_widget_ptr->GetChannelNumber() == CHANNEL_1)
            {
                int width = static_cast<int>(mdi_area_ptr_->geometry().width() / 3);
                int height = static_cast<int>((mdi_area_ptr_->geometry().height()) / 2);
                int x = 0;
                int y = 0;
                window->setGeometry(x, y, width, height);
                break;
            }
        }
    }

    // 通道2
    if (ui_ptr_->action_channel_2->isChecked())
    {
        foreach (QMdiSubWindow* window, mdi_area_ptr_->subWindowList())
        {
            ChannelTabWidget* channel_tab_widget_ptr = qobject_cast<ChannelTabWidget*>(window->widget());

            if (channel_tab_widget_ptr->GetChannelNumber() == CHANNEL_2)
            {
                int width = static_cast<int>(mdi_area_ptr_->geometry().width() / 3);
                int height = static_cast<int>((mdi_area_ptr_->geometry().height()) / 2);
                int x = width;
                int y = 0;
                window->setGeometry(x, y, width, height);
                break;
            }
        }
    }

    // 通道3
    if (ui_ptr_->action_channel_3->isChecked())
    {
        foreach (QMdiSubWindow* window, mdi_area_ptr_->subWindowList())
        {
            ChannelTabWidget* channel_tab_widget_ptr = qobject_cast<ChannelTabWidget*>(window->widget());

            if (channel_tab_widget_ptr->GetChannelNumber() == CHANNEL_3)
            {
                int width = static_cast<int>(mdi_area_ptr_->geometry().width() / 3);
                int height = static_cast<int>((mdi_area_ptr_->geometry().height()) / 2);
                int x = width * 2;
                int y = 0;
                window->setGeometry(x, y, width, height);
                break;
            }
        }
    }

    // 通道4
    if (ui_ptr_->action_channel_4->isChecked())
    {
        foreach (QMdiSubWindow* window, mdi_area_ptr_->subWindowList())
        {
            ChannelTabWidget* channel_tab_widget_ptr = qobject_cast<ChannelTabWidget*>(window->widget());

            if (channel_tab_widget_ptr->GetChannelNumber() == CHANNEL_4)
            {
                int width = static_cast<int>(mdi_area_ptr_->geometry().width() / 3);
                int height = static_cast<int>((mdi_area_ptr_->geometry().height()) / 2);
                int x = 0;
                int y = height;
                window->setGeometry(x, y, width, height);
                break;
            }
        }
    }

    // 通道5
    if (ui_ptr_->action_channel_5->isChecked())
    {
        foreach (QMdiSubWindow* window, mdi_area_ptr_->subWindowList())
        {
            ChannelTabWidget* channel_tab_widget_ptr = qobject_cast<ChannelTabWidget*>(window->widget());

            if (channel_tab_widget_ptr->GetChannelNumber() == CHANNEL_5)
            {
                int width = static_cast<int>(mdi_area_ptr_->geometry().width() / 3);
                int height = static_cast<int>((mdi_area_ptr_->geometry().height()) / 2);
                int x = width;
                int y = height;
                window->setGeometry(x, y, width, height);
                break;
            }
        }
    }

    // 通道6
    if (ui_ptr_->action_channel_6->isChecked())
    {
        foreach (QMdiSubWindow* window, mdi_area_ptr_->subWindowList())
        {
            ChannelTabWidget* channel_tab_widget_ptr = qobject_cast<ChannelTabWidget*>(window->widget());

            if (channel_tab_widget_ptr->GetChannelNumber() == CHANNEL_6)
            {
                int width = static_cast<int>(mdi_area_ptr_->geometry().width() / 3);
                int height = static_cast<int>((mdi_area_ptr_->geometry().height()) / 2);
                int x = width * 2;
                int y = height;
                window->setGeometry(x, y, width, height);
                break;
            }
        }
    }

    // qDebug() << "resize event触发";
}

//void MainWindow::paintEvent(QPaintEvent *event)
//{
//    qDebug() << "paint event触发";
//}

//void MainWindow::open()
//{
//    QString fileName = QFileDialog::getOpenFileName(this,tr("打开数据"),tr("../data"),tr("Data Files(*.csv *.txt)"));
//    if(!fileName.isEmpty())
//        {
//            // loaddata(fileName,data_array_);
//        }
//    else
//        {
//            QMessageBox::information(NULL,tr("Warning"),tr("你没有选择任何文件"));
//        }
//}

//void MainWindow::save()
//{
//    QString fileName = QFileDialog::getSaveFileName(this,tr("保存数据"),tr("../data"),tr("Data Files(*.txt)"));
//    if(!fileName.isEmpty())
//        {
//            QFile file(fileName);
//            file.open(QIODevice::ReadWrite|QIODevice::Text);
//            QString str;
//            for(int i=0;i<kDataLength;i++)
//            {
//                str+=data_time_array_[i]+tr(",")+QString::number(data_array_[i],'f',4)+QString("\n");
//                //str+=data_time_array_[i]+tr("\n");
//            }
//            QTextStream out(&file);
//            out<<str;
//        }
//    else
//        {
//            QMessageBox::information(NULL,tr("Warning"),tr("你没有选择任何文件"));
//        }
//}

// 通道1
void MainWindow::OnActionChannel1(bool is_checked)
{
    if (is_checked)
    {
        // 读取标定文件
        // ReadDemarcateFile(INSTRUMENT_1, CHANNEL_1);

        InstrumentNumber instrument_number;
        if (ui_ptr_->action_instrument_1->isChecked())
        {
            instrument_number = INSTRUMENT_1;
        } else if (ui_ptr_->action_instrument_2->isChecked())
        {
            instrument_number = INSTRUMENT_2;
        } else if (ui_ptr_->action_instrument_3->isChecked())
        {
            instrument_number = INSTRUMENT_3;
        } else if (ui_ptr_->action_instrument_4->isChecked())
        {
            instrument_number = INSTRUMENT_4;
        } else if (ui_ptr_->action_instrument_5->isChecked())
        {
            instrument_number = INSTRUMENT_5;
        }

        ChannelDialog* channel_dialog_1_ptr = new ChannelDialog;
        channel_dialog_1_ptr->SetIsChannelDemarcate(IsChannelDemarcate(instrument_number, CHANNEL_1));

         //float y_min_value = CalculateCavityByPixelNumber(fitting_count_1_, fitting_factor_channel_1_array_, 0);  // 像元0对应最小值
         //float y_max_value = CalculateCavityByPixelNumber(fitting_count_1_, fitting_factor_channel_1_array_, 2047);  // 像元2047对应最大值
        //float y_max_value = 1;
        //float y_min_value = 0;

        float y_max_value;
        float y_min_value;

        if (!IsChannelDemarcate(instrument_number, CHANNEL_1))
        {
            y_max_value = 2047;
            y_min_value = 0;
        }
        else
        {
            y_max_value = 1000;
            y_min_value = -100;
        }

        channel_dialog_1_ptr->SetYMaxAndMinValue(y_max_value, y_min_value);
        channel_dialog_1_ptr->SetData(cavity_channel_1_array_);

        ChannelTabWidget* channel_tab_1_ptr = new ChannelTabWidget(NULL, CHANNEL_1);
        channel_tab_1_ptr->setWindowTitle(QString("通道1"));
        connect(channel_tab_1_ptr, SIGNAL(cancelChannel(ChannelNumber)), this, SLOT(OnCancelChannel(ChannelNumber)));
        channel_tab_1_ptr->addTab(channel_dialog_1_ptr, QString("原始数据"));

        if (ui_ptr_->action_fft->isChecked())
        {
            FFTDialog* fft_dialog_1_ptr = new FFTDialog;
            channel_tab_1_ptr->addTab(fft_dialog_1_ptr, QString("FFT变换"));
        }

        // channel_tab_1_ptr->setGeometry(0, 60, 400, 300);
        QMdiSubWindow* sub_window = mdi_area_ptr_->addSubWindow(channel_tab_1_ptr);
        sub_window->setAttribute(Qt::WA_DeleteOnClose);
        int width = static_cast<int>(mdi_area_ptr_->geometry().width() / 3);
        int height = static_cast<int>((mdi_area_ptr_->geometry().height()) / 2);
        int x = 0;
        int y = 0;
        sub_window->setGeometry(x, y, width, height);
        // sub_window->setGeometry(0, 0, 400, 300);

        // qDebug() << "sub window width" << sub_window->width();
        // qDebug() << "sub window height" << sub_window->height();
        sub_window->show();
        channel_dialog_1_ptr->SetData(cavity_channel_1_array_);


        // channel_tab_1_ptr->setGeometry(0, 60, 450, 350);
        // channel_tab_1_ptr->show();


        // ChannelDialog channel_dialog;

        // channel_tab_1_ptr_->clear();
        

        // channel_tab_1_ptr_->setWindowFlags(Qt::WindowMinMaxButtonsHint);



        // qDebug() << x << y << width << height;

        // channel_tab_1_ptr_->setGeometry(x, y, width, height);
        
        // channel_tab_1_ptr_->setGeometry(x, y, width, height);
        
    }
    else
    {
        ui_ptr_->action_select_all->setChecked(false);
        foreach (QMdiSubWindow* window, mdi_area_ptr_->subWindowList())
        {
            ChannelTabWidget* channel_tab_widget_ptr = qobject_cast<ChannelTabWidget*>(window->widget());

            if (channel_tab_widget_ptr->GetChannelNumber() == CHANNEL_1)
            {
                mdi_area_ptr_->removeSubWindow(channel_tab_widget_ptr);
                window->close();
                break;
            }
        }
    }

}

// 通道2
void MainWindow::OnActionChannel2(bool is_checked)
{
    if (is_checked)
    {
        InstrumentNumber instrument_number;
        if (ui_ptr_->action_instrument_1->isChecked())
        {
            instrument_number = INSTRUMENT_1;
        } else if (ui_ptr_->action_instrument_2->isChecked())
        {
            instrument_number = INSTRUMENT_2;
        } else if (ui_ptr_->action_instrument_3->isChecked())
        {
            instrument_number = INSTRUMENT_3;
        } else if (ui_ptr_->action_instrument_4->isChecked())
        {
            instrument_number = INSTRUMENT_4;
        } else if (ui_ptr_->action_instrument_5->isChecked())
        {
            instrument_number = INSTRUMENT_5;
        }


        ChannelDialog* channel_dialog_2_ptr = new ChannelDialog;
        channel_dialog_2_ptr->SetIsChannelDemarcate(IsChannelDemarcate(instrument_number, CHANNEL_2));

        //float y_min_value = CalculatePowerByPixelNumber(fitting_count_2_, fitting_factor_channel_2_array_, 0);  // 像元0对应最小值
        //float y_max_value = CalculatePowerByPixelNumber(fitting_count_2_, fitting_factor_channel_2_array_, 2047);  // 像元2047对应最大值
        ////float y_max_value = 1;
        //float y_min_value = 0;
        // channel_dialog_2_ptr->SetYMaxAndMinValue(y_max_value, y_min_value);
        //float y_max_value = 2047;
        //float y_min_value = 0;

        //float y_max_value = 1000;
        //float y_min_value = -100;

        float y_max_value;
        float y_min_value;

        if (!IsChannelDemarcate(instrument_number, CHANNEL_2))
        {
            y_max_value = 2047;
            y_min_value = 0;
        }
        else
        {
            y_max_value = 1000;
            y_min_value = -100;
        }

        channel_dialog_2_ptr->SetYMaxAndMinValue(y_max_value, y_min_value);
        channel_dialog_2_ptr->SetData(cavity_channel_2_array_);
        ChannelTabWidget* channel_tab_2_ptr = new ChannelTabWidget(NULL, CHANNEL_2);
        connect(channel_tab_2_ptr, SIGNAL(cancelChannel(ChannelNumber)), this, SLOT(OnCancelChannel(ChannelNumber)));
        channel_tab_2_ptr->setWindowTitle(QString("通道2"));
        channel_tab_2_ptr->clear();
        channel_tab_2_ptr->addTab(channel_dialog_2_ptr, QString("原始数据"));

        if (ui_ptr_->action_fft->isChecked())
        {
            FFTDialog* fft_dialog_2_ptr = new FFTDialog;
            channel_tab_2_ptr->addTab(fft_dialog_2_ptr, QString("FFT变换"));
        }

        QMdiSubWindow* sub_window = mdi_area_ptr_->addSubWindow(channel_tab_2_ptr);
        sub_window->setAttribute(Qt::WA_DeleteOnClose);
        int width = static_cast<int>(mdi_area_ptr_->geometry().width() / 3);
        int height = static_cast<int>((mdi_area_ptr_->geometry().height()) / 2);
        int x = width;
        int y = 0;
        sub_window->setGeometry(x, y, width, height);
        sub_window->show();
    }
    else
    {
        ui_ptr_->action_select_all->setChecked(false);
        foreach (QMdiSubWindow* window, mdi_area_ptr_->subWindowList())
        {
            ChannelTabWidget* channel_tab_widget_ptr = qobject_cast<ChannelTabWidget*>(window->widget());

            if (channel_tab_widget_ptr->GetChannelNumber() == CHANNEL_2)
            {
                mdi_area_ptr_->removeSubWindow(channel_tab_widget_ptr);
                window->close();
                break;
            }
        }
    }
}

// 通道3
void MainWindow::OnActionChannel3(bool is_checked)
{
    if (is_checked)
    {
        InstrumentNumber instrument_number;
        if (ui_ptr_->action_instrument_1->isChecked())
        {
            instrument_number = INSTRUMENT_1;
        } else if (ui_ptr_->action_instrument_2->isChecked())
        {
            instrument_number = INSTRUMENT_2;
        } else if (ui_ptr_->action_instrument_3->isChecked())
        {
            instrument_number = INSTRUMENT_3;
        } else if (ui_ptr_->action_instrument_4->isChecked())
        {
            instrument_number = INSTRUMENT_4;
        } else if (ui_ptr_->action_instrument_5->isChecked())
        {
            instrument_number = INSTRUMENT_5;
        }



        ChannelDialog* channel_dialog_3_ptr = new ChannelDialog;
        channel_dialog_3_ptr->SetIsChannelDemarcate(IsChannelDemarcate(instrument_number, CHANNEL_3));

        //float y_min_value = CalculateCavityByPixelNumber(fitting_count_3_, fitting_factor_channel_3_array_, 0);  // 像元0对应最小值
        //float y_max_value = CalculateCavityByPixelNumber(fitting_count_3_, fitting_factor_channel_3_array_, 2047);  // 像元2047对应最大值
        //float y_max_value = 1;
        //float y_min_value = 0;
        //channel_dialog_3_ptr->SetYMaxAndMinValue(y_max_value, y_min_value);
        //float y_max_value = 2047;
        //float y_min_value = 0;

        //float y_max_value = 1000;
        //float y_min_value = -100;

        float y_max_value;
        float y_min_value;

        if (!IsChannelDemarcate(instrument_number, CHANNEL_3))
        {
            y_max_value = 2047;
            y_min_value = 0;
        }
        else
        {
            y_max_value = 1000;
            y_min_value = -100;
        }

        channel_dialog_3_ptr->SetYMaxAndMinValue(y_max_value, y_min_value);
        channel_dialog_3_ptr->SetData(cavity_channel_3_array_);
        ChannelTabWidget* channel_tab_3_ptr = new ChannelTabWidget(NULL, CHANNEL_3);
        connect(channel_tab_3_ptr, SIGNAL(cancelChannel(ChannelNumber)), this, SLOT(OnCancelChannel(ChannelNumber)));
        channel_tab_3_ptr->setWindowTitle(QString("通道3"));
        channel_tab_3_ptr->clear();
        channel_tab_3_ptr->addTab(channel_dialog_3_ptr, QString("原始数据"));

        if (ui_ptr_->action_fft->isChecked())
        {
            FFTDialog* fft_dialog_3_ptr = new FFTDialog;
            channel_tab_3_ptr->addTab(fft_dialog_3_ptr, QString("FFT变换"));
        }

        QMdiSubWindow* sub_window = mdi_area_ptr_->addSubWindow(channel_tab_3_ptr);
        sub_window->setAttribute(Qt::WA_DeleteOnClose);
        int width = static_cast<int>(mdi_area_ptr_->geometry().width() / 3);
        int height = static_cast<int>((mdi_area_ptr_->geometry().height()) / 2);
        int x = width * 2;
        int y = 0;
        sub_window->setGeometry(x, y, width, height);
        sub_window->show();
    }
    else
    {
        ui_ptr_->action_select_all->setChecked(false);
        foreach (QMdiSubWindow* window, mdi_area_ptr_->subWindowList())
        {
            ChannelTabWidget* channel_tab_widget_ptr = qobject_cast<ChannelTabWidget*>(window->widget());

            if (channel_tab_widget_ptr->GetChannelNumber() == CHANNEL_3)
            {
                mdi_area_ptr_->removeSubWindow(channel_tab_widget_ptr);
                window->close();
                break;
            }
        }
    }
}

// 通道4
void MainWindow::OnActionChannel4(bool is_checked)
{
    if (is_checked)
    {
        InstrumentNumber instrument_number;
        if (ui_ptr_->action_instrument_1->isChecked())
        {
            instrument_number = INSTRUMENT_1;
        } else if (ui_ptr_->action_instrument_2->isChecked())
        {
            instrument_number = INSTRUMENT_2;
        } else if (ui_ptr_->action_instrument_3->isChecked())
        {
            instrument_number = INSTRUMENT_3;
        } else if (ui_ptr_->action_instrument_4->isChecked())
        {
            instrument_number = INSTRUMENT_4;
        } else if (ui_ptr_->action_instrument_5->isChecked())
        {
            instrument_number = INSTRUMENT_5;
        }

        ChannelDialog* channel_dialog_4_ptr = new ChannelDialog;
        channel_dialog_4_ptr->SetIsChannelDemarcate(IsChannelDemarcate(instrument_number, CHANNEL_4));

        //float y_min_value = CalculateCavityByPixelNumber(fitting_count_4_, fitting_factor_channel_4_array_, 0);  // 像元0对应最小值
        //float y_max_value = CalculateCavityByPixelNumber(fitting_count_4_, fitting_factor_channel_4_array_, 2047);  // 像元2047对应最大值
        //float y_max_value = 1;
        //float y_min_value = 0;
        //channel_dialog_4_ptr->SetYMaxAndMinValue(y_max_value, y_min_value);
        //float y_max_value = 2047;
        //float y_min_value = 0;

        //float y_max_value = 1000;
        //float y_min_value = -100;

        float y_max_value;
        float y_min_value;

        if (!IsChannelDemarcate(instrument_number, CHANNEL_4))
        {
            y_max_value = 2047;
            y_min_value = 0;
        }
        else
        {
            y_max_value = 1000;
            y_min_value = -100;
        }

        channel_dialog_4_ptr->SetYMaxAndMinValue(y_max_value, y_min_value);
        channel_dialog_4_ptr->SetData(cavity_channel_4_array_);
        ChannelTabWidget* channel_tab_4_ptr = new ChannelTabWidget(NULL, CHANNEL_4);
        connect(channel_tab_4_ptr, SIGNAL(cancelChannel(ChannelNumber)), this, SLOT(OnCancelChannel(ChannelNumber)));
        channel_tab_4_ptr->setWindowTitle(QString("通道4"));
        channel_tab_4_ptr->clear();
        channel_tab_4_ptr->addTab(channel_dialog_4_ptr, QString("原始数据"));

        if (ui_ptr_->action_fft->isChecked())
        {
            FFTDialog* fft_dialog_4_ptr = new FFTDialog;
            channel_tab_4_ptr->addTab(fft_dialog_4_ptr, QString("FFT变换"));
        }

        QMdiSubWindow* sub_window = mdi_area_ptr_->addSubWindow(channel_tab_4_ptr);
        sub_window->setAttribute(Qt::WA_DeleteOnClose);
        int width = static_cast<int>(mdi_area_ptr_->geometry().width() / 3);
        int height = static_cast<int>((mdi_area_ptr_->geometry().height()) / 2);
        int x = 0;
        int y = height;
        sub_window->setGeometry(x, y, width, height);
        sub_window->show();
    }
    else
    {
        ui_ptr_->action_select_all->setChecked(false);
        foreach (QMdiSubWindow* window, mdi_area_ptr_->subWindowList())
        {
            ChannelTabWidget* channel_tab_widget_ptr = qobject_cast<ChannelTabWidget*>(window->widget());

            if (channel_tab_widget_ptr->GetChannelNumber() == CHANNEL_4)
            {
                mdi_area_ptr_->removeSubWindow(channel_tab_widget_ptr);
                window->close();
                break;
            }
        }
    }
}

// 通道5
void MainWindow::OnActionChannel5(bool is_checked)
{
    if (is_checked)
    {
        InstrumentNumber instrument_number;
        if (ui_ptr_->action_instrument_1->isChecked())
        {
            instrument_number = INSTRUMENT_1;
        } else if (ui_ptr_->action_instrument_2->isChecked())
        {
            instrument_number = INSTRUMENT_2;
        } else if (ui_ptr_->action_instrument_3->isChecked())
        {
            instrument_number = INSTRUMENT_3;
        } else if (ui_ptr_->action_instrument_4->isChecked())
        {
            instrument_number = INSTRUMENT_4;
        } else if (ui_ptr_->action_instrument_5->isChecked())
        {
            instrument_number = INSTRUMENT_5;
        }

        ChannelDialog* channel_dialog_5_ptr = new ChannelDialog;
        channel_dialog_5_ptr->SetIsChannelDemarcate(IsChannelDemarcate(instrument_number, CHANNEL_5));
        //float y_min_value = CalculateCavityByPixelNumber(fitting_count_5_, fitting_factor_channel_5_array_, 0);  // 像元0对应最小值
        //float y_max_value = CalculateCavityByPixelNumber(fitting_count_5_, fitting_factor_channel_5_array_, 2047);  // 像元2047对应最大值

        //float y_max_value = 1;
        //float y_min_value = 0;
        //channel_dialog_5_ptr->SetYMaxAndMinValue(y_max_value, y_min_value);
        //float y_max_value = 2047;
        //float y_min_value = 0;

        //float y_max_value = 1000;
        //float y_min_value = -100;

        float y_max_value;
        float y_min_value;

        if (!IsChannelDemarcate(instrument_number, CHANNEL_5))
        {
            y_max_value = 2047;
            y_min_value = 0;
        }
        else
        {
            y_max_value = 1000;
            y_min_value = -100;
        }

        channel_dialog_5_ptr->SetYMaxAndMinValue(y_max_value, y_min_value);
        channel_dialog_5_ptr->SetData(cavity_channel_5_array_);
        ChannelTabWidget* channel_tab_5_ptr = new ChannelTabWidget(NULL, CHANNEL_5);
        connect(channel_tab_5_ptr, SIGNAL(cancelChannel(ChannelNumber)), this, SLOT(OnCancelChannel(ChannelNumber)));
        channel_tab_5_ptr->setWindowTitle(QString("通道5"));
        channel_tab_5_ptr->clear();
        channel_tab_5_ptr->addTab(channel_dialog_5_ptr, QString("原始数据"));

        if (ui_ptr_->action_fft->isChecked())
        {
            FFTDialog* fft_dialog_5_ptr = new FFTDialog;
            channel_tab_5_ptr->addTab(fft_dialog_5_ptr, QString("FFT变换"));
        }

        QMdiSubWindow* sub_window = mdi_area_ptr_->addSubWindow(channel_tab_5_ptr);
        sub_window->setAttribute(Qt::WA_DeleteOnClose);
        int width = static_cast<int>(mdi_area_ptr_->geometry().width() / 3);
        int height = static_cast<int>((mdi_area_ptr_->geometry().height()) / 2);
        int x = width;
        int y = height;
        sub_window->setGeometry(x, y, width, height);
        sub_window->show();
    }
    else
    {
        ui_ptr_->action_select_all->setChecked(false);
        foreach (QMdiSubWindow* window, mdi_area_ptr_->subWindowList())
        {
            ChannelTabWidget* channel_tab_widget_ptr = qobject_cast<ChannelTabWidget*>(window->widget());

            if (channel_tab_widget_ptr->GetChannelNumber() == CHANNEL_5)
            {
                mdi_area_ptr_->removeSubWindow(channel_tab_widget_ptr);
                window->close();
                break;
            }
        }
    }
}

// 通道5
void MainWindow::OnActionChannel6(bool is_checked)
{
    if (is_checked)
    {
        InstrumentNumber instrument_number;
        if (ui_ptr_->action_instrument_1->isChecked())
        {
            instrument_number = INSTRUMENT_1;
        } else if (ui_ptr_->action_instrument_2->isChecked())
        {
            instrument_number = INSTRUMENT_2;
        } else if (ui_ptr_->action_instrument_3->isChecked())
        {
            instrument_number = INSTRUMENT_3;
        } else if (ui_ptr_->action_instrument_4->isChecked())
        {
            instrument_number = INSTRUMENT_4;
        } else if (ui_ptr_->action_instrument_5->isChecked())
        {
            instrument_number = INSTRUMENT_5;
        }

        ChannelDialog* channel_dialog_6_ptr = new ChannelDialog;
        channel_dialog_6_ptr->SetIsChannelDemarcate(IsChannelDemarcate(instrument_number, CHANNEL_6));
        //float y_min_value = CalculateCavityByPixelNumber(fitting_count_6_, fitting_factor_channel_6_array_, 0);  // 像元0对应最小值
        //float y_max_value = CalculateCavityByPixelNumber(fitting_count_6_, fitting_factor_channel_6_array_, 2047);  // 像元2047对应最大值

        //float y_max_value = 1;
        //float y_min_value = 0;
        //channel_dialog_6_ptr->SetYMaxAndMinValue(y_max_value, y_min_value);
        //float y_max_value = 2047;
        //float y_min_value = 0;

        //float y_max_value = 1000;
        //float y_min_value = -100;

        float y_max_value;
        float y_min_value;

        if (!IsChannelDemarcate(instrument_number, CHANNEL_6))
        {
            y_max_value = 2047;
            y_min_value = 0;
        }
        else
        {
            y_max_value = 1000;
            y_min_value = -100;
        }

        channel_dialog_6_ptr->SetYMaxAndMinValue(y_max_value, y_min_value);
        channel_dialog_6_ptr->SetData(cavity_channel_6_array_);
        ChannelTabWidget* channel_tab_6_ptr = new ChannelTabWidget(NULL, CHANNEL_6);
        connect(channel_tab_6_ptr, SIGNAL(cancelChannel(ChannelNumber)), this, SLOT(OnCancelChannel(ChannelNumber)));
        channel_tab_6_ptr->setWindowTitle(QString("通道6"));
        channel_tab_6_ptr->clear();
        channel_tab_6_ptr->addTab(channel_dialog_6_ptr, QString("原始数据"));

        if (ui_ptr_->action_fft->isChecked())
        {
            FFTDialog* fft_dialog_6_ptr = new FFTDialog;
            channel_tab_6_ptr->addTab(fft_dialog_6_ptr, QString("FFT变换"));
        }

        QMdiSubWindow* sub_window = mdi_area_ptr_->addSubWindow(channel_tab_6_ptr);
        sub_window->setAttribute(Qt::WA_DeleteOnClose);
        int width = static_cast<int>(mdi_area_ptr_->geometry().width() / 3);
        int height = static_cast<int>((mdi_area_ptr_->geometry().height()) / 2);
        int x = width * 2;
        int y = height;
        sub_window->setGeometry(x, y, width, height);
        sub_window->show();
    }
    else
    {
        ui_ptr_->action_select_all->setChecked(false);
        foreach (QMdiSubWindow* window, mdi_area_ptr_->subWindowList())
        {
            ChannelTabWidget* channel_tab_widget_ptr = qobject_cast<ChannelTabWidget*>(window->widget());

            if (channel_tab_widget_ptr->GetChannelNumber() == CHANNEL_6)
            {
                mdi_area_ptr_->removeSubWindow(channel_tab_widget_ptr);
                window->close();
                break;
            }
        }
    }
}

// FFT变换
void MainWindow::OnActionFFT(bool is_checked)
{
    if (is_checked)
    {
        ui_ptr_->action_fft->setChecked(true);
        check_box_fft_ptr_->setChecked(true);

        // 通道1
        if (ui_ptr_->action_channel_1->isChecked())
        {
            foreach (QMdiSubWindow* window, mdi_area_ptr_->subWindowList())
            {
                ChannelTabWidget* channel_tab_widget_ptr = qobject_cast<ChannelTabWidget*>(window->widget());

                if (channel_tab_widget_ptr->GetChannelNumber() == CHANNEL_1)
                {
                    bool is_fft = true;
                    if (channel_tab_widget_ptr->count() > 1)
                    {
                        for (int i = 1; i != channel_tab_widget_ptr->count(); ++i)
                        {
                            if (channel_tab_widget_ptr->tabText(i) == QString("FFT变换"))
                            {
                                is_fft = false;
                                break;
                            }
                        }

                        if (is_fft)
                        {
                            FFTDialog* fft_dialog_1_ptr = new FFTDialog;
                            channel_tab_widget_ptr->addTab(fft_dialog_1_ptr, QString("FFT变换"));
                        }
                    }
                    else
                    {
                        FFTDialog* fft_dialog_1_ptr = new FFTDialog;
                        channel_tab_widget_ptr->addTab(fft_dialog_1_ptr, QString("FFT变换"));
                    }

                    break;
                }
            }
            // fft_dialog_1_ptr_->show();
        }

        // 通道2
        if (ui_ptr_->action_channel_2->isChecked())
        {
            foreach (QMdiSubWindow* window, mdi_area_ptr_->subWindowList())
            {
                ChannelTabWidget* channel_tab_widget_ptr = qobject_cast<ChannelTabWidget*>(window->widget());
                if (channel_tab_widget_ptr->GetChannelNumber() == CHANNEL_2)
                {
                    bool is_fft = true;
                    if (channel_tab_widget_ptr->count() > 1)
                    {
                        for (int i = 1; i != channel_tab_widget_ptr->count(); ++i)
                        {
                            if (channel_tab_widget_ptr->tabText(i) == QString("FFT变换"))
                            {
                                is_fft = false;
                                break;
                            }
                        }

                        if (is_fft)
                        {
                            FFTDialog* fft_dialog_2_ptr = new FFTDialog;
                            channel_tab_widget_ptr->addTab(fft_dialog_2_ptr, QString("FFT变换"));
                        }
                    }
                    else
                    {
                        FFTDialog* fft_dialog_2_ptr = new FFTDialog;
                        channel_tab_widget_ptr->addTab(fft_dialog_2_ptr, QString("FFT变换"));
                    }

                    break;
                }
            }
        }

        // 通道3
        if (ui_ptr_->action_channel_3->isChecked())
        {
            foreach (QMdiSubWindow* window, mdi_area_ptr_->subWindowList())
            {
                ChannelTabWidget* channel_tab_widget_ptr = qobject_cast<ChannelTabWidget*>(window->widget());
                if (channel_tab_widget_ptr->GetChannelNumber() == CHANNEL_3)
                {
                    bool is_fft = true;
                    if (channel_tab_widget_ptr->count() > 1)
                    {
                        for (int i = 1; i != channel_tab_widget_ptr->count(); ++i)
                        {
                            if (channel_tab_widget_ptr->tabText(i) == QString("FFT变换"))
                            {
                                is_fft = false;
                                break;
                            }
                        }

                        if (is_fft)
                        {
                            FFTDialog* fft_dialog_3_ptr = new FFTDialog;
                            channel_tab_widget_ptr->addTab(fft_dialog_3_ptr, QString("FFT变换"));
                        }
                    }
                    else
                    {
                        FFTDialog* fft_dialog_3_ptr = new FFTDialog;
                        channel_tab_widget_ptr->addTab(fft_dialog_3_ptr, QString("FFT变换"));
                    }

                    break;
                }
            }
        }

        // 通道4
        if (ui_ptr_->action_channel_4->isChecked())
        {
            foreach (QMdiSubWindow* window, mdi_area_ptr_->subWindowList())
            {
                ChannelTabWidget* channel_tab_widget_ptr = qobject_cast<ChannelTabWidget*>(window->widget());
                if (channel_tab_widget_ptr->GetChannelNumber() == CHANNEL_4)
                {
                    bool is_fft = true;
                    if (channel_tab_widget_ptr->count() > 1)
                    {
                        for (int i = 1; i != channel_tab_widget_ptr->count(); ++i)
                        {
                            if (channel_tab_widget_ptr->tabText(i) == QString("FFT变换"))
                            {
                                is_fft = false;
                                break;
                            }
                        }

                        if (is_fft)
                        {
                            FFTDialog* fft_dialog_4_ptr = new FFTDialog;
                            channel_tab_widget_ptr->addTab(fft_dialog_4_ptr, QString("FFT变换"));
                        }
                    }
                    else
                    {
                        FFTDialog* fft_dialog_4_ptr = new FFTDialog;
                        channel_tab_widget_ptr->addTab(fft_dialog_4_ptr, QString("FFT变换"));
                    }

                    break;
                }
            }
        }

        // 通道5
        if (ui_ptr_->action_channel_5->isChecked())
        {
            foreach (QMdiSubWindow* window, mdi_area_ptr_->subWindowList())
            {
                ChannelTabWidget* channel_tab_widget_ptr = qobject_cast<ChannelTabWidget*>(window->widget());
                if (channel_tab_widget_ptr->GetChannelNumber() == CHANNEL_5)
                {
                    bool is_fft = true;
                    if (channel_tab_widget_ptr->count() > 1)
                    {
                        for (int i = 1; i != channel_tab_widget_ptr->count(); ++i)
                        {
                            if (channel_tab_widget_ptr->tabText(i) == QString("FFT变换"))
                            {
                                is_fft = false;
                                break;
                            }
                        }

                        if (is_fft)
                        {
                            FFTDialog* fft_dialog_5_ptr = new FFTDialog;
                            channel_tab_widget_ptr->addTab(fft_dialog_5_ptr, QString("FFT变换"));
                        }
                    }
                    else
                    {
                        FFTDialog* fft_dialog_5_ptr = new FFTDialog;
                        channel_tab_widget_ptr->addTab(fft_dialog_5_ptr, QString("FFT变换"));
                    }

                    break;
                }
            }
        }

        // 通道6
        if (ui_ptr_->action_channel_6->isChecked())
        {
            foreach (QMdiSubWindow* window, mdi_area_ptr_->subWindowList())
            {
                ChannelTabWidget* channel_tab_widget_ptr = qobject_cast<ChannelTabWidget*>(window->widget());
                if (channel_tab_widget_ptr->GetChannelNumber() == CHANNEL_6)
                {
                    bool is_fft = true;
                    if (channel_tab_widget_ptr->count() > 1)
                    {
                        for (int i = 1; i != channel_tab_widget_ptr->count(); ++i)
                        {
                            if (channel_tab_widget_ptr->tabText(i) == QString("FFT变换"))
                            {
                                is_fft = false;
                                break;
                            }
                        }

                        if (is_fft)
                        {
                            FFTDialog* fft_dialog_6_ptr = new FFTDialog;
                            channel_tab_widget_ptr->addTab(fft_dialog_6_ptr, QString("FFT变换"));
                        }
                    }
                    else
                    {
                        FFTDialog* fft_dialog_6_ptr = new FFTDialog;
                        channel_tab_widget_ptr->addTab(fft_dialog_6_ptr, QString("FFT变换"));
                    }

                    break;
                }
            }
        }
    }
    else
    {
        ui_ptr_->action_fft->setChecked(false);
        check_box_fft_ptr_->setChecked(false);

        // 通道1
        if (ui_ptr_->action_channel_1->isChecked())
        {
            foreach (QMdiSubWindow* window, mdi_area_ptr_->subWindowList())
            {
                ChannelTabWidget* channel_tab_widget_ptr = qobject_cast<ChannelTabWidget*>(window->widget());

                if (channel_tab_widget_ptr->GetChannelNumber() == CHANNEL_1)
                {
                    if (channel_tab_widget_ptr->count() > 1)
                    {
                        for (int i = 1; i != channel_tab_widget_ptr->count(); ++i)
                        {
                            if (channel_tab_widget_ptr->tabText(i) == QString("FFT变换"))
                            {
                                channel_tab_widget_ptr->removeTab(i);
                                break;
                            }
                        }
                    }
                }
            }
        }

        // 通道2
        if (ui_ptr_->action_channel_2->isChecked())
        {
            foreach (QMdiSubWindow* window, mdi_area_ptr_->subWindowList())
            {
                ChannelTabWidget* channel_tab_widget_ptr = qobject_cast<ChannelTabWidget*>(window->widget());

                if (channel_tab_widget_ptr->GetChannelNumber() == CHANNEL_2)
                {
                    if (channel_tab_widget_ptr->count() > 1)
                    {
                        for (int i = 1; i != channel_tab_widget_ptr->count(); ++i)
                        {
                            if (channel_tab_widget_ptr->tabText(i) == QString("FFT变换"))
                            {
                                channel_tab_widget_ptr->removeTab(i);
                                break;
                            }
                        }
                    }
                }
            }
        }

        // 通道3
        if (ui_ptr_->action_channel_3->isChecked())
        {
            foreach (QMdiSubWindow* window, mdi_area_ptr_->subWindowList())
            {
                ChannelTabWidget* channel_tab_widget_ptr = qobject_cast<ChannelTabWidget*>(window->widget());

                if (channel_tab_widget_ptr->GetChannelNumber() == CHANNEL_3)
                {
                    if (channel_tab_widget_ptr->count() > 1)
                    {
                        for (int i = 1; i != channel_tab_widget_ptr->count(); ++i)
                        {
                            if (channel_tab_widget_ptr->tabText(i) == QString("FFT变换"))
                            {
                                channel_tab_widget_ptr->removeTab(i);
                                break;
                            }
                        }
                    }
                }
            }
        }

        // 通道4
        if (ui_ptr_->action_channel_4->isChecked())
        {
            foreach (QMdiSubWindow* window, mdi_area_ptr_->subWindowList())
            {
                ChannelTabWidget* channel_tab_widget_ptr = qobject_cast<ChannelTabWidget*>(window->widget());

                if (channel_tab_widget_ptr->GetChannelNumber() == CHANNEL_4)
                {
                    if (channel_tab_widget_ptr->count() > 1)
                    {
                        for (int i = 1; i != channel_tab_widget_ptr->count(); ++i)
                        {
                            if (channel_tab_widget_ptr->tabText(i) == QString("FFT变换"))
                            {
                                channel_tab_widget_ptr->removeTab(i);
                                break;
                            }
                        }
                    }
                }
            }
        }

        // 通道5
        if (ui_ptr_->action_channel_5->isChecked())
        {
            foreach (QMdiSubWindow* window, mdi_area_ptr_->subWindowList())
            {
                ChannelTabWidget* channel_tab_widget_ptr = qobject_cast<ChannelTabWidget*>(window->widget());

                if (channel_tab_widget_ptr->GetChannelNumber() == CHANNEL_5)
                {
                    if (channel_tab_widget_ptr->count() > 1)
                    {
                        for (int i = 1; i != channel_tab_widget_ptr->count(); ++i)
                        {
                            if (channel_tab_widget_ptr->tabText(i) == QString("FFT变换"))
                            {
                                channel_tab_widget_ptr->removeTab(i);
                                break;
                            }
                        }
                    }
                }
            }
        }

        // 通道6
        if (ui_ptr_->action_channel_6->isChecked())
        {
            foreach (QMdiSubWindow* window, mdi_area_ptr_->subWindowList())
            {
                ChannelTabWidget* channel_tab_widget_ptr = qobject_cast<ChannelTabWidget*>(window->widget());

                if (channel_tab_widget_ptr->GetChannelNumber() == CHANNEL_6)
                {
                    if (channel_tab_widget_ptr->count() > 1)
                    {
                        for (int i = 1; i != channel_tab_widget_ptr->count(); ++i)
                        {
                            if (channel_tab_widget_ptr->tabText(i) == QString("FFT变换"))
                            {
                                channel_tab_widget_ptr->removeTab(i);
                                break;
                            }
                        }
                    }
                }
            }
        }
    }


    //if (channel_tab_1_ptr_->hasFocus())
    //{
    //    QMessageBox::warning(NULL, QString("提示"), QString("通道1获得焦点"));
    //}
    //else if (channel_tab_2_ptr_->hasFocus())
    //{
    //    QMessageBox::warning(NULL, QString("提示"), QString("通道2获得焦点"));
    //}
    //else if (hasFocus())
    //{
    //}
    //{
    //    qDebug() << "主对话框获得焦点";
    //}
}

void MainWindow::OnActionInstrument1(bool is_checked)
{
    if (is_checked)
    {
        //if (!IsInstrumentDemarcate(INSTRUMENT_1))
        //{
        //    ui_ptr_->action_instrument_1->setChecked(false);
        //    return;
        //}

        //if (!ReadDemarcateFile(INSTRUMENT_1))
        //{
        //    ui_ptr_->action_instrument_1->setChecked(false);
        //    return;
        //}

        if (IsInstrumentDemarcate(INSTRUMENT_1))
        {
            ReadDemarcateFile(INSTRUMENT_1);
        }

        ui_ptr_->action_instrument_2->setEnabled(false);
        ui_ptr_->action_instrument_3->setEnabled(false);
        ui_ptr_->action_instrument_4->setEnabled(false);
        ui_ptr_->action_instrument_5->setEnabled(false);
    }
    else
    {
        // 取消选择仪器，数据要重新初始化
        Init();
        ui_ptr_->action_save->setEnabled(false);
        ui_ptr_->action_image_save->setEnabled(false);
        ui_ptr_->action_instrument_2->setEnabled(true);
        ui_ptr_->action_instrument_3->setEnabled(true);
        ui_ptr_->action_instrument_4->setEnabled(true);
        ui_ptr_->action_instrument_5->setEnabled(true);
    }


}

void MainWindow::OnActionInstrument2(bool is_checked)
{
    if (is_checked)
    {
        ui_ptr_->action_instrument_1->setEnabled(false);
        ui_ptr_->action_instrument_3->setEnabled(false);
        ui_ptr_->action_instrument_4->setEnabled(false);
        ui_ptr_->action_instrument_5->setEnabled(false);
    }
    else
    {
        Init();
        ui_ptr_->action_instrument_1->setEnabled(true);
        ui_ptr_->action_instrument_3->setEnabled(true);
        ui_ptr_->action_instrument_4->setEnabled(true);
        ui_ptr_->action_instrument_5->setEnabled(true);
    }
}

void MainWindow::OnActionInstrument3(bool is_checked)
{
    if (is_checked)
    {
        ui_ptr_->action_instrument_1->setEnabled(false);
        ui_ptr_->action_instrument_2->setEnabled(false);
        ui_ptr_->action_instrument_4->setEnabled(false);
        ui_ptr_->action_instrument_5->setEnabled(false);
    }
    else
    {
        ui_ptr_->action_instrument_1->setEnabled(true);
        ui_ptr_->action_instrument_2->setEnabled(true);
        ui_ptr_->action_instrument_4->setEnabled(true);
        ui_ptr_->action_instrument_5->setEnabled(true);
    }
}

void MainWindow::OnActionInstrument4(bool is_checked)
{
    if (is_checked)
    {
        ui_ptr_->action_instrument_1->setEnabled(false);
        ui_ptr_->action_instrument_2->setEnabled(false);
        ui_ptr_->action_instrument_3->setEnabled(false);
        ui_ptr_->action_instrument_5->setEnabled(false);
    }
    else
    {
        ui_ptr_->action_instrument_1->setEnabled(true);
        ui_ptr_->action_instrument_2->setEnabled(true);
        ui_ptr_->action_instrument_3->setEnabled(true);
        ui_ptr_->action_instrument_5->setEnabled(true);
    }
}

void MainWindow::OnActionInstrument5(bool is_checked)
{
    if (is_checked)
    {
        ui_ptr_->action_instrument_1->setEnabled(false);
        ui_ptr_->action_instrument_2->setEnabled(false);
        ui_ptr_->action_instrument_3->setEnabled(false);
        ui_ptr_->action_instrument_4->setEnabled(false);
    }
    else
    {
        ui_ptr_->action_instrument_1->setEnabled(true);
        ui_ptr_->action_instrument_2->setEnabled(true);
        ui_ptr_->action_instrument_3->setEnabled(true);
        ui_ptr_->action_instrument_4->setEnabled(true);
    }
}

// 选择滑动平均
void MainWindow::OnActionMovingAverage(bool is_checked)
{
    if (is_checked)
    {
        bool ok;
        moving_average_count_ = QInputDialog::getInt(NULL, QString("滑动平均"), QString("请输入滑动平均次数"), 1, 1, kChannelDataLength, 1, &ok);

        if (!ok)
        {
            moving_average_count_ = 1;
        }

        //QInputDialog average_count_dialog;
        //average_count_dialog.setInputMode(QInputDialog::IntInput);
        //if (average_count_dialog.exec() == QDialog::Rejected)
        //{
        //    return;
        //}

        //qDebug() << average_count_dialog.intValue();
    }
}

// 选择全部通道
void MainWindow::OnActionSelectAll(bool is_checked)
{
    if (is_checked)
    {
        if (!ui_ptr_->action_channel_1->isChecked())
        {
            ui_ptr_->action_channel_1->setChecked(true);
            OnActionChannel1(true);
        }

        if (!ui_ptr_->action_channel_2->isChecked())
        {
            ui_ptr_->action_channel_2->setChecked(true);
            OnActionChannel2(true);
        }

        if (!ui_ptr_->action_channel_3->isChecked())
        {
            ui_ptr_->action_channel_3->setChecked(true);
            OnActionChannel3(true);
        }

        if (!ui_ptr_->action_channel_4->isChecked())
        {
            ui_ptr_->action_channel_4->setChecked(true);
            OnActionChannel4(true);
        }

        if (!ui_ptr_->action_channel_5->isChecked())
        {
            ui_ptr_->action_channel_5->setChecked(true);
            OnActionChannel5(true);
        }

        if (!ui_ptr_->action_channel_6->isChecked())
        {
            ui_ptr_->action_channel_6->setChecked(true);
            OnActionChannel6(true);
        }
    }
    else
    {
        ui_ptr_->action_channel_1->setChecked(false);
        OnActionChannel1(false);

        ui_ptr_->action_channel_2->setChecked(false);
        OnActionChannel2(false);

        ui_ptr_->action_channel_3->setChecked(false);
        OnActionChannel3(false);

        ui_ptr_->action_channel_4->setChecked(false);
        OnActionChannel4(false);

        ui_ptr_->action_channel_5->setChecked(false);
        OnActionChannel5(false);

        ui_ptr_->action_channel_6->setChecked(false);
        OnActionChannel6(false);
    }
}

// 通道1触发设置
void MainWindow::OnActionTriggerChannel1(bool is_checked)
{
    TriggerModeDialog trigger_mode_dialog;
    if (trigger_mode_dialog.exec() == QDialog::Rejected)
    {
        return;
    }
    trigger_mode_channel_1_ = trigger_mode_dialog.trigger_mode_;

    bool ok;
    limit_cavity_channel_1_ = static_cast<float>(QInputDialog::getDouble(NULL, QString("通道1限值"), QString("请输入通道1限值"),
                                                                                                     limit_cavity_channel_1_, -100, 1000, 1, &ok));

    if (!ok)
    {
        limit_cavity_channel_1_ = kMaxPixelNumber;
    }
}

// 通道2触发设置
void MainWindow::OnActionTriggerChannel2(bool is_checked)
{
    TriggerModeDialog trigger_mode_dialog;
    if (trigger_mode_dialog.exec() == QDialog::Rejected)
    {
        return;
    }
    trigger_mode_channel_2_ = trigger_mode_dialog.trigger_mode_;

    bool ok;
    limit_cavity_channel_2_ = static_cast<float>(QInputDialog::getDouble(NULL, QString("通道2限值"), QString("请输入通道2限值"),
                                                                                   limit_cavity_channel_2_, -100, 1000, 1, &ok));

    if (!ok)
    {
        limit_cavity_channel_2_ = kMaxPixelNumber;
    }
}

// 通道3 触发设置
void MainWindow::OnActionTriggerChannel3(bool is_checked)
{
    TriggerModeDialog trigger_mode_dialog;
    if (trigger_mode_dialog.exec() == QDialog::Rejected)
    {
        return;
    }
    trigger_mode_channel_3_ = trigger_mode_dialog.trigger_mode_;

    bool ok;
    limit_cavity_channel_3_ = static_cast<float>(QInputDialog::getDouble(NULL, QString("通道3限值"), QString("请输入通道3限值"),
                                                                                                     limit_cavity_channel_3_, -100, 1000, 1, &ok));

    if (!ok)
    {
        limit_cavity_channel_3_ = kMaxPixelNumber;
    }
}

// 通道4触发设置
void MainWindow::OnActionTriggerChannel4(bool is_checked)
{
    TriggerModeDialog trigger_mode_dialog;
    if (trigger_mode_dialog.exec() == QDialog::Rejected)
    {
        return;
    }
    trigger_mode_channel_4_ = trigger_mode_dialog.trigger_mode_;

    bool ok;
    limit_cavity_channel_4_ = static_cast<float>(QInputDialog::getDouble(NULL, QString("通道4限值"), QString("请输入通道4限值"), limit_cavity_channel_4_, 
                                                                                                                                  -100, 1000, 1, &ok));

    if (!ok)
    {
        limit_cavity_channel_4_ = kMaxPixelNumber;
    }
}

// 通道5触发设置
void MainWindow::OnActionTriggerChannel5(bool is_checked)
{
    TriggerModeDialog trigger_mode_dialog;
    if (trigger_mode_dialog.exec() == QDialog::Rejected)
    {
        return;
    }
    trigger_mode_channel_5_ = trigger_mode_dialog.trigger_mode_;

    bool ok;
    limit_cavity_channel_5_ = static_cast<float>(QInputDialog::getDouble(NULL, QString("通道5限值"), QString("请输入通道5限值"), limit_cavity_channel_5_, 
                                                                                                                                 -100, 1000, 1, &ok));

    if (!ok)
    {
        limit_cavity_channel_5_ = kMaxPixelNumber;
    }
}

// 通道6触发设置
void MainWindow::OnActionTriggerChannel6(bool is_checked)
{
    TriggerModeDialog trigger_mode_dialog;
    if (trigger_mode_dialog.exec() == QDialog::Rejected)
    {
        return;
    }
    trigger_mode_channel_6_ = trigger_mode_dialog.trigger_mode_;

    bool ok;
    limit_cavity_channel_6_ = static_cast<float>(QInputDialog::getDouble(NULL, QString("通道6限值"), QString("请输入通道6限值"), limit_cavity_channel_6_, 
                                                                                                                                 -100, 1000, 1, &ok));

    if (!ok)
    {
        limit_cavity_channel_6_ = kMaxPixelNumber;
    }
}

void MainWindow::OnCancelChannel(ChannelNumber channel_number)
{
    if (channel_number == CHANNEL_1)
    {
        ui_ptr_->action_channel_1->setChecked(false);
    }

    if (channel_number == CHANNEL_2)
    {
        ui_ptr_->action_channel_2->setChecked(false);
    }

    if (channel_number == CHANNEL_3)
    {
        ui_ptr_->action_channel_3->setChecked(false);
    }

    if (channel_number == CHANNEL_4)
    {
        ui_ptr_->action_channel_4->setChecked(false);
    }

    if (channel_number == CHANNEL_5)
    {
        ui_ptr_->action_channel_5->setChecked(false);
    }

    if (channel_number == CHANNEL_6)
    {
        ui_ptr_->action_channel_6->setChecked(false);
    }

    //if (tab_widget == channel_tab_1_ptr_)
    //{
    //    ui_ptr_->action_channel_1->setChecked(false);
    //}
    //else if (tab_widget == channel_tab_2_ptr_)
    //{
    //    ui_ptr_->action_channel_2->setChecked(false);
    //}
}

void MainWindow::OnContinuousCollect()
{
    ReadUSB();
   // //qDebug()<<QTime::currentTime()<<"first";
   // Sleep(25);
   //// qDebug()<<QTime::currentTime()<<"second";

   // QTime timer=QTime::currentTime();
   // QString time=timer.toString("hh:mm:ss.zzz");
   // //qDebug()<<time.size();

   // QByteArray read_data;
   // unsigned char receive_char[5];
   // //qDebug()<<time<<"read length:"<<read_data.size();
   ///*for(int i = 0; i != read_data.size(); ++i)
   //{
   //    receive_char[i] = read_data[i];
   //    qDebug()<<receive_char[i];
   //}*/

   // //  if (read_data.size() == 5)
   //  // {
   //       for (int i = 0; i != read_data.size(); ++i)
   //       {
   //           receive_char[i] = read_data[i];
   //           //qDebug()<<receive_char[i];
   //       }
   //      new_cavity_length=static_cast<float>(receive_char[3]* 256 + receive_char[ 2]);
   //      new_cavity_length=0.0047*new_cavity_length+5.160;
   //      qDebug()<< time<<"new_cavity_length:"<<new_cavity_length;
   //      //qDebug()<<new_cavity_length;
   //      //qDebug() << "char0"<< (unsigned int)(receive_char[0]);
   //      //qDebug() <<"char1"<<  (unsigned int)(receive_char[1]);
   //     //qDebug() << "char2"<< (unsigned int)(receive_char[2]);
   //     //qDebug() << "char3"<< (unsigned int)(receive_char[3]);
   //      //qDebug() <<"char4"<<  (unsigned int)(receive_char[4]);
   //  // }

   // Updata_cavity_length(new_cavity_length,data_array_);
   // Updata_time_(time,data_time_array_);
   // //RealTimeSave(RealTimeData);
   // RefreshPixmap();
}

// 数据保存
void MainWindow::OnDataSave()
{
    QString path_name = SAVE_PATH;
    QString instrument_name = QString::null;

    if (ui_ptr_->action_instrument_1->isChecked())
    {
        instrument_name = QString("仪器1");
    } else if (ui_ptr_->action_instrument_2->isChecked())
    {
        instrument_name = QString("仪器2");
    } else if (ui_ptr_->action_instrument_3->isChecked())
    {
        instrument_name = QString("仪器3");
    } else if (ui_ptr_->action_instrument_4->isChecked())
    {
        instrument_name = QString("仪器4");
    } else if (ui_ptr_->action_instrument_5->isChecked())
    {
        instrument_name = QString("仪器5");
    }

    // 通道1
    QString file_name_1 = path_name + instrument_name + QString("通道1.csv");

    QFileInfo file_info(file_name_1);

    QFile file(file_name_1);

    if (QFile::exists(file_name_1))
    {
        QFile::remove(file_name_1);
    }

    if (!file.open(QIODevice::WriteOnly))
    {
        QMessageBox::critical(NULL, QString("错误提示"), QString("保存数据文件%1失败").arg(file_info.fileName()));
        return;
    }

    QTextStream write_stream(&file);

    for (int i = 0; i != cavity_channel_1_save_queue_.length(); ++i)
    {
        write_stream << cavity_channel_1_save_queue_[i] << "\n";
    }
    file.close();
    write_stream.reset();

    // 通道2
    QString file_name_2 = path_name + instrument_name + QString("通道2.csv");

    file_info.setFile(file_name_2);

    file.setFileName(file_name_2);

    if (QFile::exists(file_name_2))
    {
        QFile::remove(file_name_2);
    }

    if (!file.open(QIODevice::WriteOnly))
    {
        QMessageBox::critical(NULL, QString("错误提示"), QString("保存数据文件%1失败").arg(file_info.fileName()));
        return;
    }

    write_stream.setDevice(&file);

    for (int i = 0; i != cavity_channel_2_save_queue_.length(); ++i)
    {
        write_stream << cavity_channel_2_save_queue_[i] << "\n";
    }
    file.close();
    write_stream.reset();

    // 通道3
    QString file_name_3 = path_name + instrument_name + QString("通道3.csv");

    file_info.setFile(file_name_3);

    file.setFileName(file_name_3);

    if (QFile::exists(file_name_3))
    {
        QFile::remove(file_name_3);
    }

    if (!file.open(QIODevice::WriteOnly))
    {
        QMessageBox::critical(NULL, QString("错误提示"), QString("保存数据文件%1失败").arg(file_info.fileName()));
        return;
    }

    write_stream.setDevice(&file);

    for (int i = 0; i != cavity_channel_3_save_queue_.length(); ++i)
    {
        write_stream << cavity_channel_3_save_queue_[i] << "\n";
    }
    file.close();
    write_stream.reset();

    // 通道4
    QString file_name_4 = path_name + instrument_name + QString("通道4.csv");

    file_info.setFile(file_name_4);

    file.setFileName(file_name_4);

    if (QFile::exists(file_name_4))
    {
        QFile::remove(file_name_4);
    }

    if (!file.open(QIODevice::WriteOnly))
    {
        QMessageBox::critical(NULL, QString("错误提示"), QString("保存数据文件%1失败").arg(file_info.fileName()));
        return;
    }

    write_stream.setDevice(&file);

    for (int i = 0; i != cavity_channel_4_save_queue_.length(); ++i)
    {
        write_stream << cavity_channel_4_save_queue_[i] << "\n";
    }
    file.close();
    write_stream.reset();

    // 通道5
    QString file_name_5 = path_name + instrument_name + QString("通道5.csv");

    file_info.setFile(file_name_5);

    file.setFileName(file_name_5);

    if (QFile::exists(file_name_5))
    {
        QFile::remove(file_name_5);
    }

    if (!file.open(QIODevice::WriteOnly))
    {
        QMessageBox::critical(NULL, QString("错误提示"), QString("保存数据文件%1失败").arg(file_info.fileName()));
        return;
    }

    write_stream.setDevice(&file);

    for (int i = 0; i != cavity_channel_5_save_queue_.length(); ++i)
    {
        write_stream << cavity_channel_5_save_queue_[i] << "\n";
    }
    file.close();
    write_stream.reset();

    // 通道6
    QString file_name_6 = path_name + instrument_name + QString("通道6.csv");

    file_info.setFile(file_name_6);

    file.setFileName(file_name_6);

    if (QFile::exists(file_name_6))
    {
        QFile::remove(file_name_6);
    }

    if (!file.open(QIODevice::WriteOnly))
    {
        QMessageBox::critical(NULL, QString("错误提示"), QString("保存数据文件%1失败").arg(file_info.fileName()));
        return;
    }

    write_stream.setDevice(&file);

    for (int i = 0; i != cavity_channel_6_save_queue_.length(); ++i)
    {
        write_stream << cavity_channel_6_save_queue_[i] << "\n";
    }
    file.close();
    write_stream.reset();

    // 原始数据
    QString raw_file_name = QString("原始数据.csv");
    file_info.setFile(raw_file_name);
    file.setFileName(raw_file_name);

    if (QFile::exists(raw_file_name))
    {
        QFile::remove(raw_file_name);
    }

    if (!file.open(QIODevice::WriteOnly))
    {
        QMessageBox::critical(NULL, QString("错误提示"), QString("保存原始数据文件失败"));
        return;
    }

    write_stream.setDevice(&file);

    for (int i = 0; i != kCollectCharLength; ++i)
    {
        write_stream << static_cast<unsigned short>(receive_data_[i]) << "\n";
    }
    file.close();
    write_stream.reset();

    QMessageBox::warning(NULL, QString("提示"), QString("保存成功"));
}

void MainWindow::OnExit()
{
    //if (channel_tab_1_ptr_ != NULL)
    //{
    //    if (!channel_tab_1_ptr_->isHidden())
    //    {
    //        channel_tab_1_ptr_->close();
    //    }
    //}

    //qDebug() << mdi_area_ptr_->subWindowList().count();
    //if (mdi_area_ptr_->subWindowList().count() > 0)
    //{
    //    mdi_area_ptr_->closeAllSubWindows();
    //}
    close();
}

// 图片保存
void MainWindow::OnImageSave()
{
    QPixmap  pix_save = QPixmap::grabWidget(this, 0, 60, mdi_area_ptr_->width(), mdi_area_ptr_->height());
    QString file_name;

    QString sd_path = SAVE_IMAGE_PATH;

    QFileDialog file_dialog;
    // file_dialog.setWindowIcon(QIcon("保存图片"));
    file_dialog.setAcceptMode(QFileDialog::AcceptSave);
    file_dialog.setWindowTitle("保存图片");
    file_dialog.setDirectory(sd_path);
    file_dialog.setFilter(tr("Image (*.jpg *.png *.bmp)"));

    if (file_dialog.exec() == QDialog::Accepted)
    {
        file_name = file_dialog.selectedFiles()[0];

        if (file_name.isNull())
        {
            QMessageBox::warning(this, "提示", QString("文件名为空"));
            // delete file_dialog;
            return;
        }

        if (QFileInfo(file_name).suffix().isEmpty())
        {
            file_name.append(".png");
        }

        if (pix_save.save(file_name))
        {
            QMessageBox::warning(this, QString("提示"), QString("保存成功"));
        }
        else
        {
            QMessageBox::warning(this, QString("提示"), QString("保存失败"));
        }
    }


}

//void MainWindow::com_setting()
//{
//
//}

//void MainWindow::demacrate()
//{
//
//}

// 设置存储深度
void MainWindow::OnSaveDepth()
{
    bool ok;
    save_depth_ = QInputDialog::getInt(NULL, QString("存储深度"), QString("请输入存储深度"), save_depth_, 0, kMaxSaveDepth, 1, &ok);
}

void MainWindow::OnSensorDebug()
{
    SensorDialog sensor_dialog;
    if (sensor_dialog.exec() == QDialog::Rejected)
    {
        return;
    }

    //Demarcate demarcate_dialog;
    //demarcate_dialog.SetInstrumentNumber(INSTRUMENT_1);
    //demarcate_dialog.SetChannelNumber(CHANNEL_1);
    //demarcate_dialog.exec();
}

// 启动采集
void MainWindow::OnStart()
{
    if (!(ui_ptr_->action_instrument_1->isChecked()
         || ui_ptr_->action_instrument_2->isChecked()
         || ui_ptr_->action_instrument_3->isChecked()
         || ui_ptr_->action_instrument_4->isChecked()
         || ui_ptr_->action_instrument_5->isChecked()))
    {
        QMessageBox::warning(NULL, QString("提示"), QString("请选择仪器"));
        return;
    }

    if (ui_ptr_->action_instrument_1->isChecked())
    {
        if (!StartUSB(INSTRUMENT_1))
        {
            return;
        }
    }

    //if (ui_ptr_->action_instrument_2->isChecked())
    //{
    //    if (!StartUSB(INSTRUMENT_2))
    //    {
    //        return;
    //    }
    //}

    //if (ui_ptr_->action_instrument_3->isChecked())
    //{
    //    if (!StartUSB(INSTRUMENT_3))
    //    {
    //        return;
    //    }
    //}

    //if (ui_ptr_->action_instrument_4->isChecked())
    //{
    //    if (!StartUSB(INSTRUMENT_4))
    //    {
    //        return;
    //    }
    //}

    //if (ui_ptr_->action_instrument_5->isChecked())
    //{
    //    if (!StartUSB(INSTRUMENT_5))
    //    {
    //        return;
    //    }
    //}

    is_trigger_limit_channel_1_ = false;
    is_trigger_limit_channel_2_ = false;
    is_trigger_limit_channel_3_ = false;
    is_trigger_limit_channel_4_ = false;
    is_trigger_limit_channel_5_ = false;
    is_trigger_limit_channel_6_ = false;

    // 休眠70ms进行第一次数据采集
    Sleep(50);
    send_count_ = 0;
    continuous_collect_timer_ptr_->start();

    ui_ptr_->action_collect->setEnabled(false);
    ui_ptr_->action_stop->setEnabled(true);
    ui_ptr_->action_save->setEnabled(false);
}

// 停止采集
void MainWindow::OnStop()
{
    //if (continuous_collect_timer_ptr_->isActive())
    //{
    //    continuous_collect_timer_ptr_->stop();
    //}

    continuous_collect_timer_ptr_->stop();

    StopUSB();
    ui_ptr_->action_collect->setEnabled(true);
    ui_ptr_->action_save->setEnabled(true);
    ui_ptr_->action_image_save->setEnabled(true);
    ui_ptr_->action_stop->setEnabled(false);
}

// 根据像元数计算腔长值
float MainWindow::CalculateCavityByPixelNumber(int fitting_count, double* fitting_factor, int pixel_number)
{
    double temp;
    float cavity = 0.0;

    // 根据拟合后得到的多项式系数calFactor来计算波长

    temp = fitting_factor[0];

    // 该for循环是计算多项式
    // 假设fitting_count = 5
    // 第一次：temp = fitting_factor[0] * k + calFactor[1]
    // 第二次：temp = fitting_factor[0] *k * k + fitting_factor[1] * k + fitting_factor[2]
    // 最终：temp = calFactor[0] * k * k * k * k * k
    // + fitting_factor[1] * k * k * k * k + fitting_factor[2] * k * k * k
    // + fitting_factor[3] * k * k + fitting_factor[4] * k + fitting_factor[5]...
    for (int j = 0; j != fitting_count; ++j)
    {
        temp = temp * pixel_number + fitting_factor[j + 1];
    }

    cavity = static_cast<float>(temp);
    return cavity;
}

// 根据像元计算力
float MainWindow::CalculatePowerByPixelNumber(int fitting_count, double* fitting_factor, int pixel_number)
{
    double temp;
    float power = 0.0;

    // 根据拟合后得到的多项式系数calFactor来计算波长

    temp = fitting_factor[0];

    // 该for循环是计算多项式
    // 假设fitting_count = 5
    // 第一次：temp = fitting_factor[0] * k + calFactor[1]
    // 第二次：temp = fitting_factor[0] *k * k + fitting_factor[1] * k + fitting_factor[2]
    // 最终：temp = calFactor[0] * k * k * k * k * k
    // + fitting_factor[1] * k * k * k * k + fitting_factor[2] * k * k * k
    // + fitting_factor[3] * k * k + fitting_factor[4] * k + fitting_factor[5]...
    for (int j = 0; j != fitting_count; ++j)
    {
        temp = temp * pixel_number + fitting_factor[j + 1];
    }

    power = static_cast<float>(temp);
    return power;
}

// 数据转换
void MainWindow::Convert16To8(unsigned char* raw_data, int* new_data)
{
    // 读取的字符数据从第1位开始进行数据转换
    for(int i = 0; i != kCollectDataLength; ++i)
    {
        new_data[i] = static_cast<int>(raw_data[i * 2] + raw_data[i * 2 + 1] * 256);
    }

    //// 读取的字符数据从第3位开始进行数据转换
    //for(int i = 0; i != kCollectDataLength; ++i)
    //{
    //    new_data[i] = static_cast<int>(raw_data[i * 2 + 2] + raw_data[i * 2 + 2 + 1] * 256);
    //}
}

// FFT变换
void MainWindow::FFTConvert(float* raw_data, float* fft_data)
{
    double X[kChannelDataLength];
    double Y[kFFTMaxLength];

    for (int i = 0; i != kChannelDataLength; ++i)
    {
        X[i] = raw_data[i];
    }

    emxArray_real_T* MT_X = emxCreateWrapper_real_T(X, 1, kChannelDataLength);
    emxArray_real_T* MT_Y = emxCreateWrapper_real_T(Y, 1, kFFTMaxLength);
    myfft_N(MT_X, kFFTMaxLength, MT_Y);

    for (int j = 0; j != kFFTMaxLength; ++j)
    {
        fft_data[j] = Y[j];
    }

    emxDestroyArray_real_T(MT_X);
    emxDestroyArray_real_T(MT_Y);
}

// 数据初始化
void MainWindow::Init()
{
    for (int i = 0; i != kChannelDataLength; ++i)
    {
        cavity_channel_1_array_[i] = static_cast<float>(0.0);
        cavity_channel_2_array_[i] = static_cast<float>(0.0);
        cavity_channel_3_array_[i] = static_cast<float>(0.0);
        cavity_channel_4_array_[i] = static_cast<float>(0.0);
        cavity_channel_5_array_[i] = static_cast<float>(0.0);
        cavity_channel_6_array_[i] = static_cast<float>(0.0);
    }

    // 初始化标定系数
    // 把第1个标定系数初始化为1
    // 拟合次数也初始化为1
    // 这是为了在未标定的情况下
    // 计算腔长
    fitting_factor_channel_1_array_[0] = 1;
    fitting_factor_channel_2_array_[0] = 1;
    fitting_factor_channel_3_array_[0] = 1;
    fitting_factor_channel_4_array_[0] = 1;
    fitting_factor_channel_5_array_[0] = 1;
    fitting_factor_channel_6_array_[0] = 1;

    for (int j = 1; j != 10; ++j)
    {
        fitting_factor_channel_1_array_[j] = 0.0;
        fitting_factor_channel_2_array_[j] = 0.0;
        fitting_factor_channel_3_array_[j] = 0.0;
        fitting_factor_channel_4_array_[j] = 0.0;
        fitting_factor_channel_5_array_[j] = 0.0;
        fitting_factor_channel_6_array_[j] = 0.0;
    }

    fitting_count_1_ = 1;
    fitting_count_2_ = 1;
    fitting_count_3_ = 1;
    fitting_count_4_ = 1;
    fitting_count_5_ = 1;
    fitting_count_6_ = 1;

    cavity_channel_1_save_queue_.clear();
    cavity_channel_2_save_queue_.clear();
    cavity_channel_3_save_queue_.clear();
    cavity_channel_4_save_queue_.clear();
    cavity_channel_5_save_queue_.clear();
    cavity_channel_6_save_queue_.clear();

    is_trigger_limit_channel_1_ = false;
    is_trigger_limit_channel_2_ = false;
    is_trigger_limit_channel_3_ = false;
    is_trigger_limit_channel_4_ = false;
    is_trigger_limit_channel_5_ = false;
    is_trigger_limit_channel_6_ = false;

    limit_cavity_channel_1_ = kMaxPixelNumber;
    limit_cavity_channel_2_ = kMaxPixelNumber;
    limit_cavity_channel_3_ = kMaxPixelNumber;
    limit_cavity_channel_4_ = kMaxPixelNumber;
    limit_cavity_channel_5_ = kMaxPixelNumber;
    limit_cavity_channel_6_ = kMaxPixelNumber;
}

// 判断通道是否标定
bool MainWindow::IsChannelDemarcate(InstrumentNumber instrument_number, ChannelNumber channel_number)
{
    QString path_name = DEMARCATE_PATH;
    QString instrument_name;

    if (instrument_number == INSTRUMENT_1)
    {
        instrument_name = QString("仪器1");
    } else if (instrument_number == INSTRUMENT_2)
    {
        instrument_name = QString("仪器2");
    } else if (instrument_number == INSTRUMENT_3)
    {
        instrument_name = QString("仪器3");
    } else if (instrument_number == INSTRUMENT_4)
    {
        instrument_name = QString("仪器4");
    } else if (instrument_number == INSTRUMENT_5)
    {
        instrument_name = QString("仪器5");
    }

    QString channel_name;

    if (channel_number == CHANNEL_1)
    {
        channel_name = QString("通道1");
    } else if (channel_number == CHANNEL_2)
    {
        channel_name = QString("通道2");
    } else if (channel_number == CHANNEL_3)
    {
        channel_name = QString("通道3");
    } else if (channel_number == CHANNEL_4)
    {
        channel_name = QString("通道4");
    } else if (channel_number == CHANNEL_5)
    {
        channel_name = QString("通道5");
    } else if (channel_number == CHANNEL_6)
    {
        channel_name = QString("通道6");
    }

    QString file_name = path_name + instrument_name + channel_name + QString(".txt");

    QFileInfo file_info(file_name);

    if (!QFile::exists(file_name))
    {
        // QMessageBox::warning(NULL, QString("提示"), QString("%1未标定").arg(file_info.fileName().remove(".txt")));
        return false;
    }

    // QMessageBox::warning(NULL, QString("提示"), QString("%1标定").arg(file_info.fileName().remove(".txt")));
    return true;

    
}

// 判断仪器是否标定
bool MainWindow::IsInstrumentDemarcate(InstrumentNumber instrument_number)
{
    if (!IsChannelDemarcate(instrument_number, CHANNEL_1)
        && !IsChannelDemarcate(instrument_number, CHANNEL_2)
        && !IsChannelDemarcate(instrument_number, CHANNEL_3)
        && !IsChannelDemarcate(instrument_number, CHANNEL_4)
        && !IsChannelDemarcate(instrument_number, CHANNEL_5)
        && !IsChannelDemarcate(instrument_number, CHANNEL_6))
    {
        return false;
    }
    //QString path_name = DEMARCATE_PATH;
    //QString instrument_name;

    //if (instrument_number == INSTRUMENT_1)
    //{
    //    instrument_name = QString("仪器1");
    //} else if (instrument_number == INSTRUMENT_2)
    //{
    //    instrument_name = QString("仪器2");
    //} else if (instrument_number == INSTRUMENT_3)
    //{
    //    instrument_name = QString("仪器3");
    //} else if (instrument_number == INSTRUMENT_4)
    //{
    //    instrument_name = QString("仪器4");
    //} else if (instrument_number == INSTRUMENT_5)
    //{
    //    instrument_name = QString("仪器5");
    //}

    //for (int i = 1; i <= 6; ++i)
    //{
    //    QString file_name = path_name + instrument_name + QString("通道%1.txt").arg(i);
    //    QFileInfo file_info(file_name);

    //    if (!QFile::exists(file_name))
    //    {
    //        QMessageBox::warning(NULL, QString("提示"), QString("%1未标定").arg(file_info.fileName().remove(".txt")));
    //        return false;
    //    }

    //    QFile file(file_name);

    //    if (!file.open(QIODevice::ReadOnly))
    //    {
    //        QMessageBox::critical(NULL, QString("错误提示"), QString("标定文件%1无法读取").arg(file_info.fileName()));
    //        return false;
    //    }
    //    file.close();
    //}

    return true;
}

// 判断某台仪器的USB是否打开
bool MainWindow::IsUSBOpen(InstrumentNumber instrument_number)
{
    if (!USB_device_)
    {
        // USB_device_->Close();
        delete USB_device_;
        USB_device_ = NULL;
    }

    USB_device_ = new CCyUSBDevice(this);
    if (instrument_number == INSTRUMENT_1)  // 仪器1
    {
        bool is_open = false;
        int index = 0;
        for (int i = 0; i != USB_device_->DeviceCount(); ++i)
        {
            USB_device_->Open(i);

            if (USB_device_->ProductID == USB_INSTRUMENT_1)
            {
                is_open = true;
                index = i;
                break;
            }
        }

        if (!is_open)
        {
            QMessageBox::warning(NULL, QString("提示"), QString("仪器1USB未连接"));
            return false;
        }

        USB_device_->Close();  // 关闭之后，重新打开某个指定的USB设备

        if (!USB_device_->Open(index))
        {
            QMessageBox::warning(NULL, QString("提示"), QString("仪器1USB未连接"));
            return false;
        }
    }

    return true;
}

//bool MainWindow::IsUSBOpen()
//{
//    if (USB_device_ == NULL)
//    {
//        USB_device_ = new CCyUSBDevice(this);
//    }
//
//    if (!USB_device_->IsOpen())
//    {
//        QMessageBox::warning(NULL, QString("提示"), QString("USB设备未打开"));
//        return false;
//    }
//    return true;
//}

// 滑动平均
// 参考Matlab的滑动平均smooth函数
void MainWindow::MovingAverage(float* raw_data, int length, int average_count)
{
    double sum = 0;
    float* temp = new float[length];

    for (int i = 0; i != length; ++i)
    {
        temp[i] = raw_data[i];
    }

    if (length < average_count)
    {
        average_count = length;
    }

    if ((average_count % 2) == 0)  // 平均次数为偶数
    {
        average_count = average_count - 1;
    }

    for (int j = 0; j != length; ++j)
    {
        int n = j * 2 + 1;
        int half_width = static_cast<int>(average_count / 2);

        if (n < average_count)
        {
            for (int i = 0; i != n; ++i)
            {
                sum += temp[i];
            }
            raw_data[j] = sum / n;
            sum = 0.0;
        }
        else if ((length - j - 1) < half_width)
        {
            for (int i = (j - (length - j - 1)); i <= (j + (length - j - 1)); ++i)
            {
                sum += temp[i];
            }
            raw_data[j] = sum / (2 * (length - j - 1) + 1);
            sum = 0.0;
        }
        else
        {
            for (int i = (j - half_width); i <= (j + half_width); ++i)
            {
                sum += temp[i];
            }

            raw_data[j] = sum / average_count;
            sum = 0.0;
        }
    }

    delete [] temp;
    temp = NULL;
}

// 读取标定文件
void MainWindow::ReadDemarcateFile(InstrumentNumber instrument_number)
{
    QString path_name = DEMARCATE_PATH;
    QString instrument_name = QString::null;

    if (instrument_number == INSTRUMENT_1)
    {
        instrument_name = QString("仪器1");
    } else if (instrument_number == INSTRUMENT_2)
    {
        instrument_name = QString("仪器2");
    } else if (instrument_number == INSTRUMENT_3)
    {
        instrument_name = QString("仪器3");
    } else if (instrument_number == INSTRUMENT_4)
    {
        instrument_name = QString("仪器4");
    } else if (instrument_number == INSTRUMENT_5)
    {
        instrument_name = QString("仪器5");
    }

    // 分别读取6个通道的拟合次数和拟合系数
    QFileInfo file_info;
    QFile file;
    QTextStream read_stream;
    int index = 0;

    // 通道1

    if (IsChannelDemarcate(instrument_number, CHANNEL_1))
    {
        QString file_name_1 = path_name + instrument_name + QString("通道1.txt");

        file_info.setFile(file_name_1);

        file.setFileName(file_name_1);

        if (!file.open(QIODevice::ReadOnly))
        {
            QMessageBox::critical(NULL, QString("错误提示"), QString("读取标定文件%1失败").arg(file_info.fileName()));
            // return false;
        }
        else
        {
            read_stream.setDevice(&file);
            fitting_count_1_ = read_stream.readLine().toInt();

            // QMessageBox::warning(NULL, QString("DD"), QString::number(fitting_count_1_));

            index = 0;
            while (!read_stream.atEnd())
            {
                fitting_factor_channel_1_array_[index] = read_stream.readLine().toDouble();
                ++index;
            }
        }

        file.close();
        read_stream.reset();
    }


    // 通道2
    if (IsChannelDemarcate(instrument_number, CHANNEL_2))
    {
        QString file_name_2 = path_name + instrument_name + QString("通道2.txt");

        file_info.setFile(file_name_2);

        file.setFileName(file_name_2);
        if (!file.open(QIODevice::ReadOnly))
        {
            QMessageBox::critical(NULL, QString("错误提示"), QString("读取标定文件%1失败").arg(file_info.fileName()));
            // return false;
        }
        else
        {

            read_stream.setDevice(&file);

            fitting_count_2_ = read_stream.readLine().toInt();

            index = 0;
            while (!read_stream.atEnd())
            {
                fitting_factor_channel_2_array_[index] = read_stream.readLine().toDouble();
                ++index;
            }
        }

        file.close();
        read_stream.reset();
    }

    // 通道3
    if (IsChannelDemarcate(instrument_number, CHANNEL_3))
    {
        QString file_name_3 = path_name + instrument_name + QString("通道3.txt");
        file_info.setFile(file_name_3);

        file.setFileName(file_name_3);
        if (!file.open(QIODevice::ReadOnly))
        {
            QMessageBox::critical(NULL, QString("错误提示"), QString("读取标定文件%1失败").arg(file_info.fileName()));
            // return false;
        }
        else
        {
            read_stream.setDevice(&file);

            fitting_count_3_ = read_stream.readLine().toInt();

            index = 0;
            while (!read_stream.atEnd())
            {
                fitting_factor_channel_3_array_[index] = read_stream.readLine().toDouble();
                ++index;
            }
        }

        file.close();
        read_stream.reset();
    }


    // 通道4
    if (IsChannelDemarcate(instrument_number, CHANNEL_4))
    {
        QString file_name_4 = path_name + instrument_name + QString("通道4.txt");
        file_info.setFile(file_name_4);

        file.setFileName(file_name_4);
        if (!file.open(QIODevice::ReadOnly))
        {
            QMessageBox::critical(NULL, QString("错误提示"), QString("读取标定文件%1失败").arg(file_info.fileName()));
            // return false;
        }
        else
        {
            read_stream.setDevice(&file);

            fitting_count_4_ = read_stream.readLine().toInt();

            index = 0;
            while (!read_stream.atEnd())
            {
                fitting_factor_channel_4_array_[index] = read_stream.readLine().toDouble();
                ++index;
            }
        }

        file.close();
        read_stream.reset();
    }


    // 通道5
    if (IsChannelDemarcate(instrument_number, CHANNEL_5))
    {
        QString file_name_5 = path_name + instrument_name + QString("通道5.txt");
        file_info.setFile(file_name_5);

        file.setFileName(file_name_5);
        if (!file.open(QIODevice::ReadOnly))
        {
            QMessageBox::critical(NULL, QString("错误提示"), QString("读取标定文件%1失败").arg(file_info.fileName()));
            // return false;
        }
        else
        {
            read_stream.setDevice(&file);

            fitting_count_5_ = read_stream.readLine().toInt();

            index = 0;
            while (!read_stream.atEnd())
            {
                fitting_factor_channel_5_array_[index] = read_stream.readLine().toDouble();
                ++index;
            }
        }

        file.close();
        read_stream.reset();
    }


    // 通道6
    if (IsChannelDemarcate(instrument_number, CHANNEL_6))
    {
        QString file_name_6 = path_name + instrument_name + QString("通道6.txt");
        file_info.setFile(file_name_6);

        file.setFileName(file_name_6);
        if (!file.open(QIODevice::ReadOnly))
        {
            QMessageBox::critical(NULL, QString("错误提示"), QString("读取标定文件%1失败").arg(file_info.fileName()));
            // return false;
        }
        else
        {
            read_stream.setDevice(&file);

            fitting_count_6_ = read_stream.readLine().toInt();

            index = 0;
            while (!read_stream.atEnd())
            {
                fitting_factor_channel_6_array_[index] = read_stream.readLine().toDouble();
                ++index;
            }
        }

        file.close();
        read_stream.reset();
    }
}

bool MainWindow::ReadUSB()
{
    // 发送采集命令，等待数据上传
    unsigned char send_command[2];
    long command_length = 2;
    long command_back_length = 0;
    send_command[0] = 1;
    send_command[1] = 0;

    long receive_length = kCollectCharLength;
    memset(receive_data_, 0, sizeof(receive_data_));

    int pixel_array[kCollectDataLength];

    for (int i = 0; i != kCollectDataLength; ++i)
    {
        pixel_array[i] = 0;
    }

    bool is_send_ok;
    bool is_receive_ok;

    OVERLAPPED out_overlapped;
    OVERLAPPED in_overlapped;

    out_overlapped.hEvent = CreateEventA(NULL, false, false, "CYUSB_CMD");
    in_overlapped.hEvent = CreateEventA(NULL, false, false, "CYUSB_IN");

    command_end_point_ = USB_device_->EndPointOf(kCommandAddress);
    in_end_point_ = USB_device_->EndPointOf(kInAddress);
    command_end_point_->Reset();
    in_end_point_->Reset();

    // 发送命令
    unsigned char* out_context = command_end_point_->BeginDataXfer(send_command, command_length, &out_overlapped);
    command_end_point_->WaitForXfer(&out_overlapped, 500);
    is_send_ok = command_end_point_->FinishDataXfer(send_command, command_back_length, &out_overlapped, out_context);

    if (!is_send_ok)
    {
        // qDebug() << "发送命令失败";
        CloseHandle(out_overlapped.hEvent);
        CloseHandle(in_overlapped.hEvent);
        return false;
    }

    // 接收数据
    unsigned char* in_context = in_end_point_->BeginDataXfer(receive_data_, receive_length, &in_overlapped);
    in_end_point_->WaitForXfer(&in_overlapped, 4000);
    is_receive_ok = in_end_point_->FinishDataXfer(receive_data_, receive_length, &in_overlapped, in_context);
    if (!is_receive_ok)
    {
        // qDebug() << "接收数据失败";
        CloseHandle(out_overlapped.hEvent);
        CloseHandle(in_overlapped.hEvent);
        return false;
    }

    ++send_count_;

    //QString file_name = QString("../data/data_%1.csv").arg(send_count_);
    //QFile file(file_name);
    //file.open(QIODevice::WriteOnly);
    //QTextStream write_stream(&file);

    //for (int i = 0; i != (kEffectiveCharLength); ++i)
    //{
    //    write_stream << static_cast<unsigned short>(receive_data[i]) << "\n";
    //}
    //file.close();
    //write_stream.reset();

    Convert16To8(receive_data_, pixel_array);
    CalculateCavity(pixel_array);
    SetDrawData();

    //QString file_name = QString("../data/data_%1.csv").arg(send_count_);
    //QFile file(file_name);
    //file.open(QIODevice::WriteOnly);
    //QTextStream write_stream(&file);

    //for (int i = 0; i != (kCollectDataLength); ++i)
    //{
    //    write_stream << static_cast<unsigned short>(pixel_array[i]) << "\n";
    //}
    //file.close();
    //write_stream.reset();

    CloseHandle(out_overlapped.hEvent);
    CloseHandle(in_overlapped.hEvent);

    return true;
}

// 设置绘图数据
void MainWindow::SetDrawData()
{
    // 通道1
    if (ui_ptr_->action_channel_1->isChecked())
    {
        foreach (QMdiSubWindow* window, mdi_area_ptr_->subWindowList())
        {
            ChannelTabWidget* channel_tab_widget_ptr = qobject_cast<ChannelTabWidget*>(window->widget());

            if (channel_tab_widget_ptr->GetChannelNumber() == CHANNEL_1)
            {
                // 原始数据
                ChannelDialog* channel_dialog_ptr = qobject_cast<ChannelDialog*>(channel_tab_widget_ptr->widget(0));

                if (!is_trigger_limit_channel_1_)
                {
                    for (int i = 0; i != kChannelDataLength; ++i)
                    {
                        if (trigger_mode_channel_1_ == HIGH)
                        {
                            if (cavity_channel_1_array_[i] > limit_cavity_channel_1_)
                            {
                                is_trigger_limit_channel_1_ = true;
                                break;
                            }
                        }
                        else if (trigger_mode_channel_1_ == LOW)
                        {
                            if (cavity_channel_1_array_[i] < limit_cavity_channel_1_)
                            {
                                is_trigger_limit_channel_1_ = true;
                                break;
                            }
                        }
                    }

                    channel_dialog_ptr->SetData(cavity_channel_1_array_);

                    // FFT变换
                    if (ui_ptr_->action_fft->isChecked())
                    {
                        float fft_data[kFFTMaxLength];
                        FFTConvert(cavity_channel_1_array_, fft_data);
                        for (int i = 1; i != channel_tab_widget_ptr->count(); ++i)
                        {
                            if (channel_tab_widget_ptr->tabText(i) == QString("FFT变换"))
                            {
                                FFTDialog* fft_dialog_ptr = qobject_cast<FFTDialog*>(channel_tab_widget_ptr->widget(i));


                                fft_dialog_ptr->SetData(fft_data);
                                break;
                            }
                        }
                    }
                }

                break;
            }
        }
    }

    // 通道2
    if (ui_ptr_->action_channel_2->isChecked())
    {
        foreach (QMdiSubWindow* window, mdi_area_ptr_->subWindowList())
        {
            ChannelTabWidget* channel_tab_widget_ptr = qobject_cast<ChannelTabWidget*>(window->widget());

            if (channel_tab_widget_ptr->GetChannelNumber() == CHANNEL_2)
            {
                // 原始数据
                ChannelDialog* channel_dialog_ptr = qobject_cast<ChannelDialog*>(channel_tab_widget_ptr->widget(0));

                if (!is_trigger_limit_channel_2_)
                {
                    for (int i = 0; i != kChannelDataLength; ++i)
                    {
                        if (trigger_mode_channel_2_ == HIGH)
                        {
                            if (cavity_channel_2_array_[i] > limit_cavity_channel_2_)
                            {
                                is_trigger_limit_channel_2_ = true;
                                break;
                            }
                        }
                        else if (trigger_mode_channel_2_ == LOW)
                        {
                            if (cavity_channel_2_array_[i] < limit_cavity_channel_2_)
                            {
                                is_trigger_limit_channel_2_ = true;
                                break;
                            }
                        }

                    }

                    channel_dialog_ptr->SetData(cavity_channel_2_array_);

                    // FFT变换
                    if (ui_ptr_->action_fft->isChecked())
                    {
                        float fft_data[kFFTMaxLength];
                        FFTConvert(cavity_channel_2_array_, fft_data);
                        for (int i = 1; i != channel_tab_widget_ptr->count(); ++i)
                        {
                            if (channel_tab_widget_ptr->tabText(i) == QString("FFT变换"))
                            {
                                FFTDialog* fft_dialog_ptr = qobject_cast<FFTDialog*>(channel_tab_widget_ptr->widget(i));
                                fft_dialog_ptr->SetData(fft_data);
                                break;
                            }
                        }
                    }
                }

                break;
            }
        }
    }

    // 通道3
    if (ui_ptr_->action_channel_3->isChecked())
    {
        foreach (QMdiSubWindow* window, mdi_area_ptr_->subWindowList())
        {
            ChannelTabWidget* channel_tab_widget_ptr = qobject_cast<ChannelTabWidget*>(window->widget());

            if (channel_tab_widget_ptr->GetChannelNumber() == CHANNEL_3)
            {
                // 原始数据
                ChannelDialog* channel_dialog_ptr = qobject_cast<ChannelDialog*>(channel_tab_widget_ptr->widget(0));

                if (!is_trigger_limit_channel_3_)
                {
                    for (int i = 0; i != kChannelDataLength; ++i)
                    {
                        if (trigger_mode_channel_3_ == HIGH)
                        {
                            if (cavity_channel_3_array_[i] > limit_cavity_channel_3_)
                            {
                                is_trigger_limit_channel_3_ = true;
                                break;
                            }
                        }
                        else if (trigger_mode_channel_3_ == LOW)
                        {
                            if (cavity_channel_3_array_[i] < limit_cavity_channel_3_)
                            {
                                is_trigger_limit_channel_3_ = true;
                                break;
                            }
                        }

                    }

                    channel_dialog_ptr->SetData(cavity_channel_3_array_);

                    // FFT变换
                    if (ui_ptr_->action_fft->isChecked())
                    {
                        float fft_data[kFFTMaxLength];
                        FFTConvert(cavity_channel_3_array_, fft_data);
                        for (int i = 1; i != channel_tab_widget_ptr->count(); ++i)
                        {
                            if (channel_tab_widget_ptr->tabText(i) == QString("FFT变换"))
                            {
                                FFTDialog* fft_dialog_ptr = qobject_cast<FFTDialog*>(channel_tab_widget_ptr->widget(i));
                                fft_dialog_ptr->SetData(fft_data);
                                break;
                            }
                        }
                    }
                }

                break;
            }
        }
    }

    // 通道4
    if (ui_ptr_->action_channel_4->isChecked())
    {
        foreach (QMdiSubWindow* window, mdi_area_ptr_->subWindowList())
        {
            ChannelTabWidget* channel_tab_widget_ptr = qobject_cast<ChannelTabWidget*>(window->widget());

            if (channel_tab_widget_ptr->GetChannelNumber() == CHANNEL_4)
            {
                // 原始数据
                ChannelDialog* channel_dialog_ptr = qobject_cast<ChannelDialog*>(channel_tab_widget_ptr->widget(0));

                if (!is_trigger_limit_channel_4_)
                {
                    for (int i = 0; i != kChannelDataLength; ++i)
                    {
                        if (trigger_mode_channel_4_ == HIGH)
                        {
                            if (cavity_channel_4_array_[i] > limit_cavity_channel_4_)
                            {
                                is_trigger_limit_channel_4_ = true;
                                break;
                            }
                        }
                        else if(trigger_mode_channel_4_ == LOW)
                        {
                            if (cavity_channel_4_array_[i] < limit_cavity_channel_4_)
                            {
                                is_trigger_limit_channel_4_ = true;
                                break;
                            }
                        }

                    }

                    channel_dialog_ptr->SetData(cavity_channel_4_array_);

                    // FFT变换
                    if (ui_ptr_->action_fft->isChecked())
                    {
                        float fft_data[kFFTMaxLength];
                        FFTConvert(cavity_channel_4_array_, fft_data);
                        for (int i = 1; i != channel_tab_widget_ptr->count(); ++i)
                        {
                            if (channel_tab_widget_ptr->tabText(i) == QString("FFT变换"))
                            {
                                FFTDialog* fft_dialog_ptr = qobject_cast<FFTDialog*>(channel_tab_widget_ptr->widget(i));
                                fft_dialog_ptr->SetData(fft_data);
                                break;
                            }
                        }
                    }
                }

                break;
            }
        }
    }

    // 通道5
    if (ui_ptr_->action_channel_5->isChecked())
    {
        foreach (QMdiSubWindow* window, mdi_area_ptr_->subWindowList())
        {
            ChannelTabWidget* channel_tab_widget_ptr = qobject_cast<ChannelTabWidget*>(window->widget());

            if (channel_tab_widget_ptr->GetChannelNumber() == CHANNEL_5)
            {
                // 原始数据
                ChannelDialog* channel_dialog_ptr = qobject_cast<ChannelDialog*>(channel_tab_widget_ptr->widget(0));

                if (!is_trigger_limit_channel_5_)
                {
                    for (int i = 0; i != kChannelDataLength; ++i)
                    {
                        if (trigger_mode_channel_5_ == HIGH)
                        {
                            if (cavity_channel_5_array_[i] > limit_cavity_channel_5_)
                            {
                                is_trigger_limit_channel_5_ = true;
                                break;
                            }
                        }
                        else if (trigger_mode_channel_5_ == LOW)
                        {
                            if (cavity_channel_5_array_[i] < limit_cavity_channel_5_)
                            {
                                is_trigger_limit_channel_5_ = true;
                                break;
                            }
                        }

                    }

                    channel_dialog_ptr->SetData(cavity_channel_5_array_);

                    // FFT变换
                    if (ui_ptr_->action_fft->isChecked())
                    {
                        float fft_data[kFFTMaxLength];
                        FFTConvert(cavity_channel_5_array_, fft_data);
                        for (int i = 1; i != channel_tab_widget_ptr->count(); ++i)
                        {
                            if (channel_tab_widget_ptr->tabText(i) == QString("FFT变换"))
                            {
                                FFTDialog* fft_dialog_ptr = qobject_cast<FFTDialog*>(channel_tab_widget_ptr->widget(i));
                                fft_dialog_ptr->SetData(fft_data);
                                break;
                            }
                        }
                    }
                }

                break;
            }
        }
    }

    // 通道6
    if (ui_ptr_->action_channel_6->isChecked())
    {
        foreach (QMdiSubWindow* window, mdi_area_ptr_->subWindowList())
        {
            ChannelTabWidget* channel_tab_widget_ptr = qobject_cast<ChannelTabWidget*>(window->widget());

            if (channel_tab_widget_ptr->GetChannelNumber() == CHANNEL_6)
            {
                // 原始数据
                ChannelDialog* channel_dialog_ptr = qobject_cast<ChannelDialog*>(channel_tab_widget_ptr->widget(0));

                if (!is_trigger_limit_channel_6_)
                {
                    for (int i = 0; i != kChannelDataLength; ++i)
                    {
                        if (trigger_mode_channel_6_ == HIGH)
                        {
                            if (cavity_channel_6_array_[i] > limit_cavity_channel_6_)
                            {
                                is_trigger_limit_channel_6_ = true;
                                break;
                            }
                        }
                        else if (trigger_mode_channel_6_ == LOW)
                        {
                            if (cavity_channel_6_array_[i] < limit_cavity_channel_6_)
                            {
                                is_trigger_limit_channel_6_ = true;
                                break;
                            }
                        }

                    }

                    channel_dialog_ptr->SetData(cavity_channel_6_array_);

                    // FFT变换
                    if (ui_ptr_->action_fft->isChecked())
                    {
                        float fft_data[kFFTMaxLength];
                        FFTConvert(cavity_channel_6_array_, fft_data);
                        for (int i = 1; i != channel_tab_widget_ptr->count(); ++i)
                        {
                            if (channel_tab_widget_ptr->tabText(i) == QString("FFT变换"))
                            {
                                FFTDialog* fft_dialog_ptr = qobject_cast<FFTDialog*>(channel_tab_widget_ptr->widget(i));
                                fft_dialog_ptr->SetData(fft_data);
                                break;
                            }
                        }
                    }
                }

                break;
            }
        }
    }
}

// 启动指定仪器的USB设备
bool MainWindow::StartUSB(InstrumentNumber instrument_number)
{
    if (!IsUSBOpen(instrument_number))
    {
        return false;
    }

    long command_length = 2;
    long command_back_length = 0;

    unsigned char start_command[2];
    start_command[0] = 5;
    start_command[1] = 0;

    bool is_send_ok;

    OVERLAPPED out_overlapped;
    OVERLAPPED in_overlapped;

    out_overlapped.hEvent = CreateEventA(NULL, false, false, "CYUSB_CMD");
    in_overlapped.hEvent = CreateEventA(NULL, false, false, "CYUSB_IN");

    command_end_point_ = USB_device_->EndPointOf(0x02);
    in_end_point_ = USB_device_->EndPointOf(0x86);


    unsigned char* out_context = command_end_point_->BeginDataXfer(start_command, command_length, &out_overlapped);
    command_end_point_->WaitForXfer(&out_overlapped, 500);
    is_send_ok = command_end_point_->FinishDataXfer(start_command, command_back_length, &out_overlapped, out_context);

    if (!is_send_ok)
    {
        CloseHandle(out_overlapped.hEvent);
        CloseHandle(in_overlapped.hEvent);
        QMessageBox::critical(NULL, QString("错误"), QString("启动仪器%1未识别").arg(instrument_number));
        return false;
    }

    CloseHandle(out_overlapped.hEvent);
    CloseHandle(in_overlapped.hEvent);
    return true;
}

// 停止USB
void MainWindow::StopUSB()
{
    long command_length = 2;
    long command_back_length = 0;

    unsigned char stop_command[2];
    stop_command[0] = 6;
    stop_command[1] = 0;

    bool is_send_ok;

    OVERLAPPED out_overlapped;
    OVERLAPPED in_overlapped;

    out_overlapped.hEvent = CreateEventA(NULL, false, false, "CYUSB_CMD");
    in_overlapped.hEvent = CreateEventA(NULL, false, false, "CYUSB_IN");

    command_end_point_ = USB_device_->EndPointOf(0x02);
    in_end_point_ = USB_device_->EndPointOf(0x86);


    unsigned char* out_context = command_end_point_->BeginDataXfer(stop_command, command_length, &out_overlapped);
    command_end_point_->WaitForXfer(&out_overlapped, 500);
    is_send_ok = command_end_point_->FinishDataXfer(stop_command, command_back_length, &out_overlapped, out_context);

    CloseHandle(out_overlapped.hEvent);
    CloseHandle(in_overlapped.hEvent);

    USB_device_->Close();
}

//void MainWindow::Updata_cavity_length(float new_cavity_length, float *data)
//{
//    for(int i=kChannelDataLength-1;i!=0;--i)
//    {
//        data[i]=data[i-1];
//    }
//     data[0]=new_cavity_length;
//}
//
//void MainWindow::Updata_time_(QString time, QString *data_time_array_)
//{
//
//    for(int i=kChannelDataLength-1;i!=0;--i)
//    {
//        data_time_array_[i]=data_time_array_[i-1];
//    }
//     data_time_array_[0]=time;
//
//}


//void MainWindow::on_action_sample_triggered()
//{
//    continuous_collect_timer_ptr_->start(50);
//}
