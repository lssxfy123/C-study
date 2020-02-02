
#include "../include/triggermodedialog.h"


#include "../ui/ui_trigger_mode.h"


TriggerModeDialog::TriggerModeDialog(QWidget* parent /* = NULL */)
: QDialog(parent), ui_ptr_(new Ui::trigger_mode_dialog)
{
    ui_ptr_->setupUi(this);
    connect(ui_ptr_->button_sure, SIGNAL(clicked()), this, SLOT(OnSure()));
    connect(ui_ptr_->button_cancel, SIGNAL(clicked()), this, SLOT(OnCancel()));
}

TriggerModeDialog::~TriggerModeDialog()
{
    delete ui_ptr_;
    ui_ptr_ = NULL;
}

void TriggerModeDialog::OnSure()
{
    if (ui_ptr_->radio_button_high->isChecked())
    {
        trigger_mode_ = HIGH;
    }
    else if (ui_ptr_->radio_button_low->isChecked())
    {
        trigger_mode_ = LOW;
    }

    accept();
}

void TriggerModeDialog::OnCancel()
{
    close();
}
