#ifndef SENSORDIALOG_H
#define SENSORDIALOG_H

#include <QDialog>

#include "../include/global.h"

namespace Ui {
    class sensor_dialog;
}

class SensorDialog : public QDialog
{
    Q_OBJECT

  public:
    SensorDialog(QWidget* parent = NULL);
    ~SensorDialog();

  private slots:
    void OnCancel();
    void OnSet();

  private:
    Ui::sensor_dialog* ui_ptr_;
};

#endif  // SENSORDIALOG_H
