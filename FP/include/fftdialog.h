#ifndef FFTDIALOG_H
#define FFTDIALOG_H

#include <QDialog>

#include "../include/global.h"
#include "../include/plotset.h"

namespace Ui {
    class fft_dialog;
};

class FFTDialog : public QDialog
{
    Q_OBJECT

  public:
    FFTDialog(QWidget* parent = NULL);
    ~FFTDialog();

  public:
    void SetData(float* data);

  protected:
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
    void paintEvent(QPaintEvent *event);

  protected slots:
    void OnZoomIn();
    void OnZoomOut();
    // void closeEvent(QCloseEvent *event);

  private:
    void DrawCurve(QPainter* painter_ptr);
    void DrawGrid(QPainter* painter_ptr);
    void Init();
    void InitPlotSet();
    void GetYMaxAndMinValue();
    void RefreshPixmap();
    void UpdateZoomSelectRect();

  private:
    Ui::fft_dialog* ui_ptr_;

    QPixmap pix_map_;

    float data_array_[kFFTDataLength];

    QVector<PlotSet> zoom_plot_set_vector_;  // 绘图设置容器
    int current_zoom_index_;  // 当前绘图设置索引
    float x_max_value_;
    float x_min_value_;
    float y_max_value_;
    float y_min_value_;
    int x_axis_number_marker_;  // X轴标记数
    int y_axis_number_marker_;  // Y轴标记数
    bool is_clicked_;  // 是否点击后滑动
    QRect zoom_selected_rect_;  // 选中的缩放区域
};


#endif  // FFTDIALOG_H
