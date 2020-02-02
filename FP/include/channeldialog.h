#ifndef CHANNELDIALOG_H
#define CHANNELDIALOG_H

#include <QDialog>
#include <QMouseEvent>

#include "../include/global.h"
#include "../include/plotset.h"

namespace Ui {
    class channel_dialog;
}

class ChannelDialog : public QDialog
{
    Q_OBJECT

  public:
    ChannelDialog(QWidget* parent = NULL);
    ~ChannelDialog();

  public:
    void SetData(float* data);
    void SetIsChannelDemarcate(bool is_instrument_demarcate);
    void SetYMaxAndMinValue(float y_max_value, float y_min_value);

  protected:
    void mouseMoveEvent(QMouseEvent *event);
    void mousePressEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
    void paintEvent(QPaintEvent *event);
    void resizeEvent(QResizeEvent* event);

  protected slots:
    void OnZoomIn();
    void OnZoomOut();

  private:
    void DrawCurve(QPainter* painter_ptr);
    void DrawGrid(QPainter* painter_ptr);
    void GetYMaxAndMinValue();
    void Init();
    void InitPlotSet();
    void RefreshPixmap();
    void UpdateZoomSelectRect();

  private:
    Ui::channel_dialog* ui_ptr_;
    QPixmap pix_map_;

    float data_array_[kChannelDataLength];

    QVector<PlotSet> zoom_plot_set_vector_;  // ��ͼ��������
    int current_zoom_index_;  // ��ǰ��ͼ��������
    float x_max_value_;
    float x_min_value_;
    float y_max_value_;
    float y_min_value_;
    int x_axis_number_marker_;  // X������
    int y_axis_number_marker_;  // Y������
    bool is_zoom_in_clicked_;   // �Ƿ����Ŵ�ť
    bool is_zoom_out_clicked_;  // �Ƿ�����С��ť
    bool is_button_press_;      // �Ƿ�Ϊ�϶��Ŵ�
    QRect zoom_selected_rect_;  // ѡ�е���������

    bool is_channel_demarcate_;    // �Ƿ񱻱궨
    bool is_set_y_max_min_value_;  // �Ƿ�������Y������ֵ����Сֵ
};

#endif  // CHANNELDIALOG_H
