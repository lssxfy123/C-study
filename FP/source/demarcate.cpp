
#include "../include/demarcate.h"

#include <QtDebug>
#include<QtGui>

#include "../include/DataFit.h"
#include "../include/MT_emxAPI.h"
#include "../ui/ui_demarcate.h"

Demarcate::Demarcate(QWidget *parent) :
    QDialog(parent),
    ui_ptr_(new Ui::demarcate)
{
    ui_ptr_->setupUi(this);
    // setWindowFlags(Qt::FramelessWindowHint);  // 去掉标题栏
     setGeometry(60, 60, 800, 420);

    // connect(ui_ptr_->pixel_edit, SIGNAL(textEdited(const QString&)), this, SLOT(OnPixelEditChanged(const QString&)));
    connect(ui_ptr_->button_add, SIGNAL(clicked()), this, SLOT(OnAdd()));
    connect(ui_ptr_->button_delete, SIGNAL(clicked()), this, SLOT(OnDelete()));
    connect(ui_ptr_->button_demarcate, SIGNAL(clicked()), this, SLOT(OnDemarcate()));
    connect(ui_ptr_->button_save, SIGNAL(clicked()), this, SLOT(OnSave()));

    Init();
}

Demarcate::~Demarcate()
{
    ClearItem();
    delete ui_ptr_;
}

void Demarcate::paintEvent(QPaintEvent *event)
{
    QStylePainter painter(this);
    painter.drawPixmap(0, 0, pix_map_);

}

bool Demarcate::CavityFitting()      //拟合函数
{
    int row_count = ui_ptr_->table_pixel_cavity->rowCount();
    if (row_count < kFitMinSensorCount)
    {
        QMessageBox::warning(NULL, QString("提示"), QString("像元腔长对数不能小于%1")
            .arg(kFitMinSensorCount));
        return false;
    }

    if (row_count > kFitMaxSensorCount)
    {
        QMessageBox::warning(NULL, QString("提示"), QString("像元腔长对数不能大于%1")
            .arg(kFitMaxSensorCount));
        return false;
    }

    double pixel_number[kFitMaxSensorCount];
    double wavelength[kFitMaxSensorCount];
    
    int fitting_count = 0;  // 拟合次数

    fitting_count = ui_ptr_->combox_fitting_count->currentText().toInt();

    if (fitting_count >= row_count)
    {
        QMessageBox::warning(NULL, QString("提示"), QString("拟合次数必须小于像元腔长对数"));
        return false;
    }

    for (int j = 0; j != row_count; ++j)
    {
        pixel_number[j] = ui_ptr_->table_pixel_cavity->item(j, 0)->text().toDouble();
        wavelength[j] = ui_ptr_->table_pixel_cavity->item(j, 1)->text().toDouble();
    }

    // 将拟合使用的数据类型double转换成Matlab生成的函数需要的数据emxArray_real_T
    // 其中rows一直为1 cols为拟合使用的原始数据个数
    emxArray_real_T* pix_number_Matlab = emxCreateWrapper_real_T(pixel_number, 1, row_count);
    emxArray_real_T* wavelength_Matlab = emxCreateWrapper_real_T(wavelength, 1, row_count);


    emxArray_real_T* fitting_factor_Matlab = emxCreateWrapper_real_T(fitting_factor_, 1, row_count);

    DataFit(pix_number_Matlab, wavelength_Matlab, fitting_count, fitting_factor_Matlab);

    //for (int i = 0; i != fitting_count + 1; ++i)
    //{
    //    qDebug() << fitting_factor_[i] << ",";
    //}

    //qDebug() << "\n";

    double temp;

    // 根据拟合后得到的多项式系数calFactor来计算波长
    for (int k = 0; k != kFitCavityCount; ++k)
    {
        temp = fitting_factor_[0];

        // 该for循环是计算多项式
        // 假设fitting_count = 5
        // 第一次：temp = fitting_factor[0] * k + calFactor[1]
        // 第二次：temp = fitting_factor[0] *k * k + fitting_factor[1] * k + fitting_factor[2]
        // 最终：temp = calFactor[0] * k * k * k * k * k
        // + fitting_factor[1] * k * k * k * k + fitting_factor[2] * k * k * k
        // + fitting_factor[3] * k * k + fitting_factor[4] * k + fitting_factor[5]...
        for (int j = 0; j != fitting_count; ++j)
        {
            temp = temp * k + fitting_factor_[j + 1];
        }

        fitting_cavity_[k] = static_cast<float>(temp);
    }

    return true;

}

// 设置通道号
void Demarcate::SetChannelNumber(ChannelNumber channel_number)
{
    channel_number_ = channel_number;
}

// 设置仪器号
void Demarcate::SetInstrumentNumber(InstrumentNumber instrumen_number)
{
    instrument_number_ = instrumen_number;
}

// 添加波长和像元
void Demarcate::OnAdd()
{
    QString pixel_text = ui_ptr_->edit_pixel->text();

    // 判断像元数上是否合适
    int pixel_number = pixel_text.toInt();
    if ((pixel_number < kMinPixelNumber) || (pixel_number > kMaxPixelNumber))
    {
        QMessageBox::critical(NULL, QString("像元错误"), QString("像元数必须在%1-%2之间").arg(kMinPixelNumber)
            .arg(kMaxPixelNumber));
        return;
    }

    // 判断是否已存在相同的像元数
    for (int i = 0; i != ui_ptr_->table_pixel_cavity->rowCount(); ++i)
    {
        int pixel_exist = ui_ptr_->table_pixel_cavity->item(i, 0)->text().toInt();  // 已存在的像元数
        if (pixel_exist == pixel_number)
        {
            QMessageBox::warning(NULL, QString("提示"), QString("像元数%1已存在").arg(pixel_number));
            return;
        }
        
    }

    QString cavity_text = ui_ptr_->edit_cavity->text();

    // 判断腔长是否合适
    float cavity = cavity_text.toFloat();
    if ((cavity < kFitMinCavitylength) || (cavity > kFitMaxCavtiyength))
    {
        QMessageBox::critical(NULL, QString("腔长错误"), QString("腔长必须在%1-%2之间").arg(kFitMinCavitylength)
            .arg(kFitMaxCavtiyength));
        return;
    }
    

    int row_count = ui_ptr_->table_pixel_cavity->rowCount();
    ++row_count;
    ui_ptr_->table_pixel_cavity->setRowCount(row_count);

    ui_ptr_->table_pixel_cavity->setItem(row_count - 1, 0, new QTableWidgetItem(pixel_text));
    ui_ptr_->table_pixel_cavity->setItem(row_count - 1, 1, new QTableWidgetItem(cavity_text));

    ui_ptr_->table_pixel_cavity->horizontalHeader()->setResizeMode(QHeaderView::Stretch);

    ui_ptr_->edit_pixel->clear();
    ui_ptr_->edit_cavity->clear();

    // ui_ptr_->pixel_wavelength_table->resizeColumnsToContents();

    // QMessageBox::information(NULL,"show picture", pixel_text + wavelenth_text);

    // ui->textEdit->setText(str5);
}

// 删除波长和像元
void Demarcate::OnDelete()
{
    QList<QTableWidgetItem*> select_items_list = ui_ptr_->table_pixel_cavity->selectedItems();

    // 删除选中的数据项
    if (!select_items_list.isEmpty())
    {
        foreach (QTableWidgetItem* item, select_items_list)
        {
            delete item;
        }
    }

    // 判断每一行的第一个数据项是否为空，来删除空行
    for (int j = 0; j != ui_ptr_->table_pixel_cavity->rowCount(); ++j)
    {
        // qDebug() << "数据表行长度" << ui_ptr_->data_table->rowCount() << "\n";

        if (NULL == ui_ptr_->table_pixel_cavity->item(j, 0))
        {
            ui_ptr_->table_pixel_cavity->removeRow(j);
            // qDebug() << "删除的数据行" << j;
            --j;
        }
    }
}


// 腔长标定
void Demarcate::OnDemarcate()
{
    //Ynum=1;
    //str1=str1.fromLocal8Bit("显示图片成功");
    //QMessageBox::information(NULL,"show picture",str1);

     if (!CavityFitting())  // 标定腔长
     {
        return;
     }

    RefreshPixmap();
}

// 保存标定文件
void Demarcate::OnSave()
{
    // 标定文件名
    QString file_name = DEMARCATE_PATH;

    if (instrument_number_ == INSTRUMENT_1)
    {
        file_name += QString("仪器1");
    } else if (instrument_number_ == INSTRUMENT_2)
    {
        file_name += QString("仪器2");
    } else if (instrument_number_ == INSTRUMENT_3)
    {
        file_name += QString("仪器3");
    } else if (instrument_number_ == INSTRUMENT_4)
    {
        file_name += QString("仪器4");
    } else if (instrument_number_ == INSTRUMENT_5)
    {
        file_name += QString("仪器5");
    }

    if (channel_number_ == CHANNEL_1)
    {
        file_name += QString("通道1");
    } else if (channel_number_ == CHANNEL_2)
    {
        file_name += QString("通道2");
    } else if (channel_number_ == CHANNEL_3)
    {
        file_name += QString("通道3");
    } else if (channel_number_ == CHANNEL_4)
    {
        file_name += QString("通道4");
    } else if (channel_number_ == CHANNEL_5)
    {
        file_name += QString("通道5");
    } else if (channel_number_ == CHANNEL_6)
    {
        file_name += QString("通道6");
    }

    file_name += QString(".txt");

    QFileInfo file_info(file_name);

    if (QFile::exists(file_name))
    {
        QMessageBox::StandardButton question = QMessageBox::question(this,
            QString("复制"), QString("%1已存在，是否覆盖").arg(file_info.fileName()),
            QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);

        if (question == QMessageBox::Yes)
        {
            QFile::remove(file_name);
        } else if (question == QMessageBox::No)
        {
            return;
        }
    }

    QFile file(file_name);
    if (!file.open(QIODevice::WriteOnly))
    {
        QMessageBox::critical(NULL, QString("错误"), QString("保存文件%1失败").arg(file_name));
        return;
    }

    int fitting_count = ui_ptr_->combox_fitting_count->currentText().toInt();
    QTextStream write_stream(&file);

    // 在windows下的txt文档中，换行符为\r\n
    write_stream << fitting_count << "\r\n";  // 第一行，拟合次数

    for (int i = 0; i != (fitting_count + 1); ++i)
    {
        write_stream << fitting_factor_[i] << "\r\n";
    }

    file.close();

    QMessageBox::warning(NULL, QString("提示"), QString("保存成功"));
    close();

}

void Demarcate::ClearItem()
{
    ui_ptr_->table_pixel_cavity->clearContents();
    ui_ptr_->table_pixel_cavity->setRowCount(0);
}

void Demarcate::DrawCurve(QPainter* painter_ptr)
{
    QRect painter_rect(300, 40, width() - 2 * 170, height() - 2 * 100);
    // QRect painter_rect(Margin, Margin, width() - Margin, height() - Margin);

    if (!painter_rect.isValid())
    {
        return;
    }

    painter_ptr->setClipRect(painter_rect.adjusted(1, 1, -1, -1));

    QPolygonF poly_line(kFitCavityCount);

    float min_cavtiy = fitting_cavity_[0];
    float max_cavity = fitting_cavity_[kFitCavityCount - 1];

    // qDebug() << min_wavelength;
    // qDebug() << max_wavelength;

    for (int j = 0; j != kFitCavityCount; ++j)
    {
        float x_distance = fitting_cavity_[j] - min_cavtiy;  // 曲线点的X轴坐标值与X轴最小坐标值的差值
        float y_distance = fitting_pixel_number_[j] - kMinPixelNumber;  // 曲线点的Y轴坐标值与Y轴最小坐标值的差值

        float x_position = painter_rect.left() + (x_distance * (painter_rect.width() - 1)
            / (max_cavity - min_cavtiy));  // 曲线点的X轴坐标对应在绘图区域中的位置

        float y_position = painter_rect.bottom() - (y_distance * (painter_rect.height() - 1)
            / (kMaxPixelNumber - kMinPixelNumber));  // 曲线点的Y轴坐标对应在绘图区域中的位置

        poly_line[j] = QPointF(x_position, y_position);
    }

    painter_ptr->setPen(Qt::red);
    painter_ptr->drawPolyline(poly_line);
}

void Demarcate::DrawGrid(QPainter* painter_ptr)
{
    QRect painter_rect(300, 40, width() - 2 * 170, height() - 2 * 100);
    // QRect painter_rect(Margin, Margin, width() - Margin, height() - Margin);

    if (!painter_rect.isValid())
    {
        return;
    }

    QPen grid_pen;  // 用来绘制网络线的画笔
    grid_pen.setWidth(1);
    grid_pen.setBrush(QColor(qRgb(50, 109, 159)));
    grid_pen.setStyle(Qt::DotLine);  // 圆点线

    QPen axis_pen;  // 用来绘制坐标轴的画笔

    QBrush old_brush = painter_ptr->brush();
    painter_ptr->setPen(grid_pen);
    painter_ptr->setBrush(QColor(qRgb(0, 89, 159)));

    // 获取Y轴的最大值和最小值
    // GetYMaxAndMinValue();

    painter_ptr->drawRect(painter_rect.adjusted(0, 0, -1, -1));

    // 横坐标为波长
    float min_cavity = fitting_cavity_[0];
    float max_cavity = fitting_cavity_[kFitCavityCount - 1];

    for (int i = 0; i != kXAxisNumMarker; ++i)
    {
        int x = painter_rect.left() + static_cast<int>(i * (painter_rect.width() - 1) / (kXAxisNumMarker - 1));
        float X_label = static_cast<float>(min_cavity + (i * (max_cavity - min_cavity) / (kXAxisNumMarker - 1)));

        painter_ptr->setPen(grid_pen);
        painter_ptr->drawLine(x, painter_rect.top(), x, painter_rect.bottom());

        painter_ptr->drawText(x - 50, painter_rect.bottom() + 5, 100, 15, Qt::AlignHCenter | Qt::AlignTop, QString::number(X_label));
    }

    // 纵坐标为像元数
    for (int j = 0; j != kYAxisNumMarker; ++j)
    {
        int y = painter_rect.bottom() - static_cast<int>(j * (painter_rect.height() - 1) / (kYAxisNumMarker - 1));
        float Y_label = static_cast<float>(kMinPixelNumber + (j * (kMaxPixelNumber - kMinPixelNumber) / (kYAxisNumMarker - 1)));

        painter_ptr->setPen(grid_pen);
        painter_ptr->drawLine(painter_rect.left(), y, painter_rect.right(), y);
        painter_ptr->drawText(painter_rect.left() - 70, y - 10, 70 - 5, 20, Qt::AlignRight | Qt::AlignVCenter, QString::number(Y_label));
    }

    painter_ptr->setPen(axis_pen);
    painter_ptr->setBrush(old_brush);
    // painter_ptr->drawRect(painter_rect);
    painter_ptr->drawRect(painter_rect.adjusted(0, 0, -1, -1));

    if (!ui_ptr_->label_x_axis->isVisible())
    {
        ui_ptr_->label_x_axis->setVisible(true);
    }

    if (!ui_ptr_->label_y_axis->isVisible())
    {
        ui_ptr_->label_y_axis->setVisible(true);
    }
}

// 初始化拟合次数选择
void Demarcate::Init()
{
    for (int i = 0; i <= kFitMaxCount; ++i)
    {
        ui_ptr_->combox_fitting_count->addItem(QString::number(i));
    }

    for (int j = 0; j != kFitCavityCount; ++j)
    {
        fitting_cavity_[j] = j + 0.5;
    }

    for (int k = 0; k != kFitCavityCount; ++k)
    {
        fitting_pixel_number_[k] = k;
    }

    for (int k = 0; k != 12; ++k)
    {
        fitting_factor_[k] = 0.0;
    }

    ui_ptr_->label_x_axis->setVisible(false);
    ui_ptr_->label_y_axis->setVisible(false);
}

void Demarcate::RefreshPixmap()
{
    pix_map_ = QPixmap(size());
    pix_map_.fill(this, 0, 0);

    QPainter painter(&pix_map_);
    painter.initFrom(this);

    DrawGrid(&painter);
    DrawCurve(&painter);
    update();
}
