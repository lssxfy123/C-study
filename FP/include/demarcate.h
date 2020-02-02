#ifndef DEMARCATE_H
#define DEMARCATE_H

#include <QDialog>
#include <QPainter>
#include "../include/global.h"

namespace Ui {
class demarcate;
}

class Demarcate : public QDialog
{
    Q_OBJECT
    
  public:
    explicit Demarcate(QWidget* parent = 0);
    ~Demarcate();

  public:
    bool CavityFitting();
    void SetChannelNumber(ChannelNumber channel_number);
    void SetInstrumentNumber(InstrumentNumber instrumen_number);

  protected:
    void paintEvent(QPaintEvent *event);

  private slots:
    void OnAdd();
    void OnDelete();
    void OnDemarcate();
    void OnSave();

  private:
    void ClearItem();
    void DrawCurve(QPainter* painter_ptr);
    void DrawGrid(QPainter* painter_ptr);
    void Init();

    void RefreshPixmap();

  private:
    Ui::demarcate* ui_ptr_;
    QPixmap pix_map_;
    float fitting_cavity_[kFitCavityCount];
    int fitting_pixel_number_[kFitCavityCount];
    double fitting_factor_[12];  // ���ϵ��

    InstrumentNumber instrument_number_;  // ������
    ChannelNumber channel_number_;        // ͨ����
};

#endif  // DEMARCATE_H
