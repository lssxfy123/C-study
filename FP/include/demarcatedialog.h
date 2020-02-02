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

    float coefficient_x_3_;   // ������ϵ��
    float coefficient_x_2_;   // ������ϵ��
    float coefficient_x_1_;   // һ����ϵ��
    float coefficient_const_;  // ������ϵ��

    InstrumentNumber instrument_number_;  // ������
    ChannelNumber channel_number_;        // ͨ����

};


#endif  // DEMARCATEDIALOG_H
