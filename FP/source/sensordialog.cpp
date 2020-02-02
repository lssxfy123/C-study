#include "../include/sensordialog.h"

#include <QMessageBox>

#include "../include/demarcate.h"
#include "../include/demarcatedialog.h"
#include "../include/global.h"

#include "../ui/ui_sensor_dialog.h"

SensorDialog::SensorDialog(QWidget* parent /* = NULL */)
:QDialog(parent), ui_ptr_(new Ui::sensor_dialog)
{
    ui_ptr_->setupUi(this);

    connect(ui_ptr_->button_set, SIGNAL(clicked()), this, SLOT(OnSet()));
    connect(ui_ptr_->button_cancel, SIGNAL(clicked()), this, SLOT(OnCancel()));
}

SensorDialog::~SensorDialog()
{
    delete ui_ptr_;
    ui_ptr_ = NULL;
}

void SensorDialog::OnCancel()
{
    close();
}

void SensorDialog::OnSet()
{
    // Demarcate demarcate_dialog;
    DemarcateDialog demarcate_dialog;

    // 选择仪器号
    if (ui_ptr_->radio_button_instrument_1->isChecked())
    {
        demarcate_dialog.SetInstrumentNumber(INSTRUMENT_1);
    } else if (ui_ptr_->radio_button_instrument_2->isChecked())
    {
        demarcate_dialog.SetInstrumentNumber(INSTRUMENT_2);
    } else if (ui_ptr_->radio_button_instrument_3->isChecked())
    {
        demarcate_dialog.SetInstrumentNumber(INSTRUMENT_3);
    } else if (ui_ptr_->radio_button_instrument_4->isChecked())
    {
        demarcate_dialog.SetInstrumentNumber(INSTRUMENT_4);
    } else if (ui_ptr_->radio_button_instrument_5->isChecked())
    {
        demarcate_dialog.SetInstrumentNumber(INSTRUMENT_5);
    }
    else
    {
        QMessageBox::warning(NULL, QString("提示"), QString("请选择仪器号"));
        return;
    }


    // 选择通道号
    if (ui_ptr_->radio_button_channel_1->isChecked())
    {
        demarcate_dialog.SetChannelNumber(CHANNEL_1);
    } else if (ui_ptr_->radio_button_channel_2->isChecked())
    {
        demarcate_dialog.SetChannelNumber(CHANNEL_2);
    } else if (ui_ptr_->radio_button_channel_3->isChecked())
    {
        demarcate_dialog.SetChannelNumber(CHANNEL_3);
    } else if (ui_ptr_->radio_button_channel_4->isChecked())
    {
        demarcate_dialog.SetChannelNumber(CHANNEL_4);
    } else if (ui_ptr_->radio_button_channel_5->isChecked())
    {
        demarcate_dialog.SetChannelNumber(CHANNEL_5);
    } else if (ui_ptr_->radio_button_channel_6->isChecked())
    {
        demarcate_dialog.SetChannelNumber(CHANNEL_6);
    }
    else
    {
        QMessageBox::warning(NULL, QString("提示"), QString("请选择通道号"));
        return;
    }

    demarcate_dialog.exec();

}
