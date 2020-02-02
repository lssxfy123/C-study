
#include "../include/demarcatedialog.h"

#include<QtGui>

#include "../ui/ui_demarcate_dialog.h"

DemarcateDialog::DemarcateDialog(QWidget *parent) :
    QDialog(parent),
    ui_ptr_(new Ui::demarcate_dialog)
{
    ui_ptr_->setupUi(this);
    // setWindowFlags(Qt::FramelessWindowHint);  // 去掉标题栏


    connect(ui_ptr_->button_sure, SIGNAL(clicked()), this, SLOT(OnSure()));
    connect(ui_ptr_->button_cancel, SIGNAL(clicked()), this, SLOT(OnCancel()));
    //connect(ui_ptr_->button_demarcate, SIGNAL(clicked()), this, SLOT(OnDemarcate()));
    //connect(ui_ptr_->button_save, SIGNAL(clicked()), this, SLOT(OnSave()));

}

DemarcateDialog::~DemarcateDialog()
{
    delete ui_ptr_;
}

void DemarcateDialog::SetChannelNumber(ChannelNumber channel_number)
{
    channel_number_ = channel_number;
}

void DemarcateDialog::SetInstrumentNumber(InstrumentNumber instrumen_number)
{
    instrument_number_ = instrumen_number;
}

void DemarcateDialog::OnSure()
{
    coefficient_x_3_ = ui_ptr_->line_edit_x_3->text().toFloat();
    coefficient_x_2_ = ui_ptr_->line_edit_x_2->text().toFloat();
    coefficient_x_1_ = ui_ptr_->line_edit_x_1->text().toFloat();
    coefficient_const_ = ui_ptr_->line_edit_const->text().toFloat();

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

    int fitting_count = 3;
    QTextStream write_stream(&file);

    // 在windows下的txt文档中，换行符为\r\n
    write_stream << fitting_count << "\r\n";  // 第一行，拟合次数


    write_stream << coefficient_x_3_ << "\r\n";
    write_stream << coefficient_x_2_ << "\r\n";
    write_stream << coefficient_x_1_ << "\r\n";
    write_stream << coefficient_const_ << "\r\n";

    file.close();

    QMessageBox::warning(NULL, QString("提示"), QString("保存成功"));

    accept();
}

void DemarcateDialog::OnCancel()
{
    close();
}
