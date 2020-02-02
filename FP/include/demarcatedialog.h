#ifndef DEMARCATEDIALOG_H
#define DEMARCATEDIALOG_H

#include <QDialog>

#include "../include/global.h"

namespace Ui {
    class demarcate_dialog;
};

class DemarcateDialog : public QDialog
{
    Q_OBJECT

  public:
    DemarcateDialog(QWidget* parent = NULL);
    ~DemarcateDialog();

  public:
    void SetChannelNumber(ChannelNumber channel_number);
    void SetInstrumentNumber(InstrumentNumber instrumen_number);

  protected slots:
    void OnSure();
    void OnCancel();

  private:
    Ui::demarcate_dialog* ui_ptr_;

    float coefficient_x_3_;   // 三次项系数
    float coefficient_x_2_;   // 二次项系数
    float coefficient_x_1_;   // 一次项系数
    float coefficient_const_;  // 常数项系数

    InstrumentNumber instrument_number_;  // 仪器号
    ChannelNumber channel_number_;        // 通道号

};


#endif  // DEMARCATEDIALOG_H
