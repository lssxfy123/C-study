
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
    // setWindowFlags(Qt::FramelessWindowHint);  // ȥ��������
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

bool Demarcate::CavityFitting()      //��Ϻ���
{
    int row_count = ui_ptr_->table_pixel_cavity->rowCount();
    if (row_count < kFitMinSensorCount)
    {
        QMessageBox::warning(NULL, QString("��ʾ"), QString("��Ԫǻ����������С��%1")
            .arg(kFitMinSensorCount));
        return false;
    }

    if (row_count > kFitMaxSensorCount)
    {
        QMessageBox::warning(NULL, QString("��ʾ"), QString("��Ԫǻ���������ܴ���%1")
            .arg(kFitMaxSensorCount));
        return false;
    }

    double pixel_number[kFitMaxSensorCount];
    double wavelength[kFitMaxSensorCount];
    
    int fitting_count = 0;  // ��ϴ���

    fitting_count = ui_ptr_->combox_fitting_count->currentText().toInt();

    if (fitting_count >= row_count)
    {
        QMessageBox::warning(NULL, QString("��ʾ"), QString("��ϴ�������С����Ԫǻ������"));
        return false;
    }

    for (int j = 0; j != row_count; ++j)
    {
        pixel_number[j] = ui_ptr_->table_pixel_cavity->item(j, 0)->text().toDouble();
        wavelength[j] = ui_ptr_->table_pixel_cavity->item(j, 1)->text().toDouble();
    }

    // �����ʹ�õ���������doubleת����Matlab���ɵĺ�����Ҫ������emxArray_real_T
    // ����rowsһֱΪ1 colsΪ���ʹ�õ�ԭʼ���ݸ���
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

    // ������Ϻ�õ��Ķ���ʽϵ��calFactor�����㲨��
    for (int k = 0; k != kFitCavityCount; ++k)
    {
        temp = fitting_factor_[0];

        // ��forѭ���Ǽ������ʽ
        // ����fitting_count = 5
        // ��һ�Σ�temp = fitting_factor[0] * k + calFactor[1]
        // �ڶ��Σ�temp = fitting_factor[0] *k * k + fitting_factor[1] * k + fitting_factor[2]
        // ���գ�temp = calFactor[0] * k * k * k * k * k
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

// ����ͨ����
void Demarcate::SetChannelNumber(ChannelNumber channel_number)
{
    channel_number_ = channel_number;
}

// ����������
void Demarcate::SetInstrumentNumber(InstrumentNumber instrumen_number)
{
    instrument_number_ = instrumen_number;
}

// ��Ӳ�������Ԫ
void Demarcate::OnAdd()
{
    QString pixel_text = ui_ptr_->edit_pixel->text();

    // �ж���Ԫ�����Ƿ����
    int pixel_number = pixel_text.toInt();
    if ((pixel_number < kMinPixelNumber) || (pixel_number > kMaxPixelNumber))
    {
        QMessageBox::critical(NULL, QString("��Ԫ����"), QString("��Ԫ��������%1-%2֮��").arg(kMinPixelNumber)
            .arg(kMaxPixelNumber));
        return;
    }

    // �ж��Ƿ��Ѵ�����ͬ����Ԫ��
    for (int i = 0; i != ui_ptr_->table_pixel_cavity->rowCount(); ++i)
    {
        int pixel_exist = ui_ptr_->table_pixel_cavity->item(i, 0)->text().toInt();  // �Ѵ��ڵ���Ԫ��
        if (pixel_exist == pixel_number)
        {
            QMessageBox::warning(NULL, QString("��ʾ"), QString("��Ԫ��%1�Ѵ���").arg(pixel_number));
            return;
        }
        
    }

    QString cavity_text = ui_ptr_->edit_cavity->text();

    // �ж�ǻ���Ƿ����
    float cavity = cavity_text.toFloat();
    if ((cavity < kFitMinCavitylength) || (cavity > kFitMaxCavtiyength))
    {
        QMessageBox::critical(NULL, QString("ǻ������"), QString("ǻ��������%1-%2֮��").arg(kFitMinCavitylength)
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

// ɾ����������Ԫ
void Demarcate::OnDelete()
{
    QList<QTableWidgetItem*> select_items_list = ui_ptr_->table_pixel_cavity->selectedItems();

    // ɾ��ѡ�е�������
    if (!select_items_list.isEmpty())
    {
        foreach (QTableWidgetItem* item, select_items_list)
        {
            delete item;
        }
    }

    // �ж�ÿһ�еĵ�һ���������Ƿ�Ϊ�գ���ɾ������
    for (int j = 0; j != ui_ptr_->table_pixel_cavity->rowCount(); ++j)
    {
        // qDebug() << "���ݱ��г���" << ui_ptr_->data_table->rowCount() << "\n";

        if (NULL == ui_ptr_->table_pixel_cavity->item(j, 0))
        {
            ui_ptr_->table_pixel_cavity->removeRow(j);
            // qDebug() << "ɾ����������" << j;
            --j;
        }
    }
}


// ǻ���궨
void Demarcate::OnDemarcate()
{
    //Ynum=1;
    //str1=str1.fromLocal8Bit("��ʾͼƬ�ɹ�");
    //QMessageBox::information(NULL,"show picture",str1);

     if (!CavityFitting())  // �궨ǻ��
     {
        return;
     }

    RefreshPixmap();
}

// ����궨�ļ�
void Demarcate::OnSave()
{
    // �궨�ļ���
    QString file_name = DEMARCATE_PATH;

    if (instrument_number_ == INSTRUMENT_1)
    {
        file_name += QString("����1");
    } else if (instrument_number_ == INSTRUMENT_2)
    {
        file_name += QString("����2");
    } else if (instrument_number_ == INSTRUMENT_3)
    {
        file_name += QString("����3");
    } else if (instrument_number_ == INSTRUMENT_4)
    {
        file_name += QString("����4");
    } else if (instrument_number_ == INSTRUMENT_5)
    {
        file_name += QString("����5");
    }

    if (channel_number_ == CHANNEL_1)
    {
        file_name += QString("ͨ��1");
    } else if (channel_number_ == CHANNEL_2)
    {
        file_name += QString("ͨ��2");
    } else if (channel_number_ == CHANNEL_3)
    {
        file_name += QString("ͨ��3");
    } else if (channel_number_ == CHANNEL_4)
    {
        file_name += QString("ͨ��4");
    } else if (channel_number_ == CHANNEL_5)
    {
        file_name += QString("ͨ��5");
    } else if (channel_number_ == CHANNEL_6)
    {
        file_name += QString("ͨ��6");
    }

    file_name += QString(".txt");

    QFileInfo file_info(file_name);

    if (QFile::exists(file_name))
    {
        QMessageBox::StandardButton question = QMessageBox::question(this,
            QString("����"), QString("%1�Ѵ��ڣ��Ƿ񸲸�").arg(file_info.fileName()),
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
        QMessageBox::critical(NULL, QString("����"), QString("�����ļ�%1ʧ��").arg(file_name));
        return;
    }

    int fitting_count = ui_ptr_->combox_fitting_count->currentText().toInt();
    QTextStream write_stream(&file);

    // ��windows�µ�txt�ĵ��У����з�Ϊ\r\n
    write_stream << fitting_count << "\r\n";  // ��һ�У���ϴ���

    for (int i = 0; i != (fitting_count + 1); ++i)
    {
        write_stream << fitting_factor_[i] << "\r\n";
    }

    file.close();

    QMessageBox::warning(NULL, QString("��ʾ"), QString("����ɹ�"));
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
        float x_distance = fitting_cavity_[j] - min_cavtiy;  // ���ߵ��X������ֵ��X����С����ֵ�Ĳ�ֵ
        float y_distance = fitting_pixel_number_[j] - kMinPixelNumber;  // ���ߵ��Y������ֵ��Y����С����ֵ�Ĳ�ֵ

        float x_position = painter_rect.left() + (x_distance * (painter_rect.width() - 1)
            / (max_cavity - min_cavtiy));  // ���ߵ��X�������Ӧ�ڻ�ͼ�����е�λ��

        float y_position = painter_rect.bottom() - (y_distance * (painter_rect.height() - 1)
            / (kMaxPixelNumber - kMinPixelNumber));  // ���ߵ��Y�������Ӧ�ڻ�ͼ�����е�λ��

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

    QPen grid_pen;  // �������������ߵĻ���
    grid_pen.setWidth(1);
    grid_pen.setBrush(QColor(qRgb(50, 109, 159)));
    grid_pen.setStyle(Qt::DotLine);  // Բ����

    QPen axis_pen;  // ��������������Ļ���

    QBrush old_brush = painter_ptr->brush();
    painter_ptr->setPen(grid_pen);
    painter_ptr->setBrush(QColor(qRgb(0, 89, 159)));

    // ��ȡY������ֵ����Сֵ
    // GetYMaxAndMinValue();

    painter_ptr->drawRect(painter_rect.adjusted(0, 0, -1, -1));

    // ������Ϊ����
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

    // ������Ϊ��Ԫ��
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

// ��ʼ����ϴ���ѡ��
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
