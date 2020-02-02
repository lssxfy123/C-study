#ifndef TRIGGERMODEDIALOG_H
#define TRIGGERMODEDIALOG_H

#include <QDialog>

#include "../include/global.h"

namespace Ui {
    class trigger_mode_dialog;
}

class TriggerModeDialog : public QDialog
{
    Q_OBJECT

  public:
    TriggerModeDialog(QWidget* parent = NULL);
    ~TriggerModeDialog();

  protected slots:
    void OnSure();
    void OnCancel();

  public:
    TriggerMode trigger_mode_;

  private:
    Ui::trigger_mode_dialog* ui_ptr_;

};

#endif  // TRIGGERMODEDIALOG_H
