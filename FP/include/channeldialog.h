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

    QVector<PlotSet> zoom_plot_set_vector_;  // 绘图设置容器
    int current_zoom_index_;  // 当前绘图设置索引
    float x_max_value_;
    float x_min_value_;
    float y_max_value_;
    float y_min_value_;
    int x_axis_number_marker_;  // X轴标记数
    int y_axis_number_marker_;  // Y轴标记数
    bool is_zoom_in_clicked_;   // 是否点击放大按钮
    bool is_zoom_out_clicked_;  // 是否点击缩小按钮
    bool is_button_press_;      // 是否为拖动放大
    QRect zoom_selected_rect_;  // 选中的缩放区域

    bool is_channel_demarcate_;    // 是否被标定
    bool is_set_y_max_min_value_;  // 是否设置了Y轴的最大值和最小值
};

#endif  // CHANNELDIALOG_H
