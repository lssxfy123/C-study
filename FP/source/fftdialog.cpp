
#include "../include/fftdialog.h"

#include <QLabel>
#include <QMouseEvent>
#include <QStylePainter>
#include <QtDebug>

#include "../ui/ui_fft_dialog.h"

FFTDialog::FFTDialog(QWidget* parent /* = NULL */)
: QDialog(parent), ui_ptr_(new Ui::fft_dialog)
{
    ui_ptr_->setupUi(this);

    connect(ui_ptr_->button_zoom_in, SIGNAL(clicked()), this, SLOT(OnZoomIn()));
    connect(ui_ptr_->button_zoom_out, SIGNAL(clicked()), this, SLOT(OnZoomOut()));
    Init();

    // QLabel* label = new QLabel(QString("FFT变换"), this);
}

FFTDialog::~FFTDialog()
{
    // qDebug() << "fft 析构";
    delete ui_ptr_;
    ui_ptr_ = NULL;
}

// 设置绘图数据
void FFTDialog::SetData(float* data)
{
    for (int i = 0; i != kFFTDataLength; ++i)
    {
        data_array_[i] = data[i];
    }

    InitPlotSet();
    RefreshPixmap();
}

void FFTDialog::mousePressEvent(QMouseEvent *event)
{
    // 绘图时用到的矩形区域
    QRect painter_rect(50, 30, width() - 100, height() - 80);

    if (event->button() == Qt::LeftButton)
    {
        if (painter_rect.contains(event->pos()))
        {
            is_clicked_ = true;
            zoom_selected_rect_.setTopLeft(event->pos());
            zoom_selected_rect_.setBottomRight(event->pos());
            UpdateZoomSelectRect();
            // zoom_selected_rect_.normalized();
        }
    }
}

void FFTDialog::mouseMoveEvent(QMouseEvent *event)
{
    if (is_clicked_)
    {
        // zoom_selected_rect_.normalized();
        UpdateZoomSelectRect();
        zoom_selected_rect_.setBottomRight(event->pos());
        // zoom_selected_rect_.normalized();
        UpdateZoomSelectRect();
    }
}

void FFTDialog::mouseReleaseEvent(QMouseEvent *event)
{
    if ((event->button() == Qt::LeftButton))
    {
        is_clicked_ = false;
        UpdateZoomSelectRect();
        QRect painter_rect = zoom_selected_rect_.normalized();
        if (painter_rect.width() < 5 || painter_rect.height() < 5)
        {
            return;
        }

        //qDebug() << "mouse release normalized" << "left" << painter_rect.left();
        //qDebug() << "mouse release normalized" << "right" << painter_rect.right();
        //qDebug() << "mouse release normalized" << "top" << painter_rect.top();
        //qDebug() << "mouse release normalized" << "bottom" << painter_rect.bottom();
        painter_rect.translate(-50, -30);
        //qDebug() << "mouse release normalized translate" << "left" << painter_rect.left();
        //qDebug() << "mouse release normalized translate" << "right" << painter_rect.right();
        //qDebug() << "mouse release normalized translate" << "top" << painter_rect.top();
        //qDebug() << "mouse release normalized translate" << "bottom" << painter_rect.bottom();

        PlotSet previous_plot_set = zoom_plot_set_vector_[current_zoom_index_];
        PlotSet plot_set;
        float dx = previous_plot_set.SpanX() / (width() - 100);
        float dy = previous_plot_set.SpanY() / (height() - 80);
        plot_set.x_min_value_ = previous_plot_set.x_min_value_ + dx * painter_rect.left();
        plot_set.x_max_value_ = previous_plot_set.x_min_value_ + dx * painter_rect.right();
        plot_set.y_min_value_ = previous_plot_set.y_max_value_ - dy * painter_rect.bottom();
        plot_set.y_max_value_ = previous_plot_set.y_max_value_ - dy * painter_rect.top();

        if (plot_set.y_min_value_ < 0)
        {
            plot_set.y_min_value_ = 0;
        }

        if (plot_set.y_max_value_ < 0)
        {
            plot_set.y_max_value_ = 0;
        }

        plot_set.x_axis_number_marker_ = previous_plot_set.x_axis_number_marker_;
        plot_set.y_axis_number_marker_ = previous_plot_set.y_axis_number_marker_;
        plot_set.AdjustXAndYAxis();
        zoom_plot_set_vector_.resize(current_zoom_index_ + 1);
        zoom_plot_set_vector_.append(plot_set);
        OnZoomIn();
    }
}

void FFTDialog::paintEvent(QPaintEvent *event)
{
    QStylePainter painter(this);
    painter.drawPixmap(0, 0, pix_map_);

    if (is_clicked_) {
        QPen pen(Qt::red, 1.5, Qt::DotLine);
        painter.setPen(pen);
        painter.drawRect(zoom_selected_rect_.normalized()
            .adjusted(0, 0, -1, -1));
        // return;
    }

    RefreshPixmap();
}

void FFTDialog::OnZoomIn()
{
    if (current_zoom_index_ < (zoom_plot_set_vector_.count() - 1))
    {
        ++current_zoom_index_;
        ui_ptr_->button_zoom_in->setEnabled(current_zoom_index_ < (zoom_plot_set_vector_.count() - 1));
        ui_ptr_->button_zoom_out->setEnabled(true);
        ui_ptr_->button_zoom_out->show();
        RefreshPixmap();
    }
}

void FFTDialog::OnZoomOut()
{
    if (current_zoom_index_ > 0)
    {
        --current_zoom_index_;
        // qDebug() << "current zoom index" << current_zoom_index_;
        ui_ptr_->button_zoom_out->setEnabled(current_zoom_index_ > 0);
        ui_ptr_->button_zoom_in->setEnabled(true);
        ui_ptr_->button_zoom_in->show();
        RefreshPixmap();
    }
}

void FFTDialog::DrawCurve(QPainter* painter_ptr)
{
    QRect painter_rect(50, 30, width() - 100, height() - 80);

    if (!painter_rect.isValid())
    {
        return;
    }

    painter_ptr->setClipRect(painter_rect.adjusted(1, 1, -1, -1));
    PlotSet plot_set = zoom_plot_set_vector_[current_zoom_index_];

    QPolygonF poly_line(kFFTDataLength);

    float x_axis_array[kFFTDataLength];

    for (int i = 0; i != kFFTDataLength; ++i)
    {
        x_axis_array[i] = static_cast<float>(i);
    }

    //float x_min_value = x_axis_array[0];
    //float x_max_value = x_axis_array[kFFTDataLength - 1];

    for (int j = 0; j != kFFTDataLength; ++j)
    {
        float x_distance = x_axis_array[j] - plot_set.x_min_value_;  // 曲线点的X轴坐标值与X轴最小坐标值的差值
        // float y_distance = data_array_[j] - kMinNormalizeIntensity;  // 曲线点的Y轴坐标值与Y轴最小坐标值的差值
        float y_distance = data_array_[j] - plot_set.y_min_value_;

        float x_position = painter_rect.left() + (x_distance * (painter_rect.width() - 1)
            / (plot_set.x_max_value_ - plot_set.x_min_value_));  // 曲线点的X轴坐标对应在绘图区域中的位置

        // float y_position = painter_rect.bottom() - (y_distance * (painter_rect.height() - 1)
        //    / (kMaxNormalizeIntensity - kMinNormalizeIntensity));  // 曲线点的Y轴坐标对应在绘图区域中的位置

        float y_position = painter_rect.bottom() - (y_distance * (painter_rect.height() - 1)
            / (plot_set.y_max_value_ - plot_set.y_min_value_));  // 曲线点的Y轴坐标对应在绘图区域中的位置

        // qDebug() << "x_position" << x_position << j;
        // qDebug() << "y_position" << y_position << j;
        poly_line[j] = QPointF(x_position, y_position);
    }

    QPen pen(Qt::red,3,Qt::SolidLine);
    painter_ptr->setPen(pen) ;
    painter_ptr->drawPolyline(poly_line);
}

void FFTDialog::DrawGrid(QPainter* painter_ptr)
{
    QRect painter_rect(50, 30, width() - 100, height() - 80);
    // QRect painter_rect(Margin, Margin, width() - Margin, height() - Margin);

    if (!painter_rect.isValid())
    {
        return;
    }

    QPen grid_pen;  // 用来绘制网络线的画笔
    grid_pen.setWidth(1);
    // grid_pen.setBrush(QColor(qRgb(50, 109, 159)));
    grid_pen.setStyle(Qt::DotLine);  // 圆点线

    QPen axis_pen;  // 用来绘制坐标轴的画笔

    QBrush old_brush = painter_ptr->brush();
    painter_ptr->setPen(grid_pen);
    // painter_ptr->setBrush(QColor(qRgb(0, 89, 159)));

    //// 获取Y轴的最大值和最小值
    //GetYMaxAndMinValue();

    //qDebug() << y_max_value_;
    //qDebug() << y_min_value_;
    //y_max_value_=kXMaxValue-1;
    //y_max_value_ = 17.85;
    //y_min_value_ = 13.15;

    painter_ptr->drawRect(painter_rect.adjusted(0, 0, -1, -1));

    // 设置放大和缩小按钮的位置
    int x_zoom_in = static_cast<int>((geometry().width() - (ui_ptr_->button_zoom_in->width() + ui_ptr_->button_zoom_out->width() + 20)) / 2);
    int y_zoom_in = 0;
    int x_zoom_out = x_zoom_in + ui_ptr_->button_zoom_in->width() + 20;
    int width_zoom_in = ui_ptr_->button_zoom_in->width();
    int height_zoom_in = ui_ptr_->button_zoom_in->height();
    ui_ptr_->button_zoom_in->setGeometry(x_zoom_in, y_zoom_in, width_zoom_in, height_zoom_in);
    ui_ptr_->button_zoom_out->setGeometry(x_zoom_out, y_zoom_in, width_zoom_in, height_zoom_in);

    // 横坐标初始为像元
    // ui->label_x_axis->setText(tr("波 长/nm"));

    PlotSet plot_set = zoom_plot_set_vector_[current_zoom_index_];

    for (int i = 0; i != plot_set.x_axis_number_marker_; ++i)
    {
        int x = painter_rect.left() + static_cast<int>(i * (painter_rect.width() - 1) / (plot_set.x_axis_number_marker_ - 1));
        float X_label = static_cast<float>(plot_set.x_min_value_
            + (i * (plot_set.x_max_value_ - plot_set.x_min_value_) / (plot_set.x_axis_number_marker_ - 1)));

        painter_ptr->setPen(grid_pen);
        painter_ptr->drawLine(x, painter_rect.top(), x, painter_rect.bottom());

        // qDebug() << "x = " << x;

        painter_ptr->drawText(x - 50, painter_rect.bottom() + 5, 100, 20, Qt::AlignHCenter | Qt::AlignTop, QString::number(X_label, 'f', 1));
    }

    // Y轴
    for (int j = 0; j != plot_set.y_axis_number_marker_; ++j)
    {
        int y = painter_rect.bottom() - static_cast<int>(j * (painter_rect.height() - 1) / (plot_set.y_axis_number_marker_ - 1));

        float Y_label = static_cast<float>(plot_set.y_min_value_ 
            + (j * (plot_set.y_max_value_ - plot_set.y_min_value_) / (plot_set.y_axis_number_marker_ - 1)));

        painter_ptr->setPen(grid_pen);
        painter_ptr->drawLine(painter_rect.left(), y, painter_rect.right(), y);

        painter_ptr->drawText(painter_rect.left() - 70, y - 10, 70, 25, Qt::AlignRight | Qt::AlignVCenter, QString::number(Y_label, 'f', 3));
    }

    painter_ptr->setPen(axis_pen);
    painter_ptr->setBrush(old_brush);
    painter_ptr->drawRect(painter_rect.adjusted(0, 0, -1, -1));
}

void FFTDialog::Init()
{
    for (int i = 0; i != kFFTDataLength; ++i)
    {
        data_array_[i] = 0.0;
    }

    x_axis_number_marker_ = kXAxisNumMarker;
    y_axis_number_marker_ = kYAxisNumMarker;

    InitPlotSet();
}

void FFTDialog::InitPlotSet()
{
    zoom_plot_set_vector_.clear();
    is_clicked_ = false;
    current_zoom_index_ = 0;
    ui_ptr_->button_zoom_in->hide();
    ui_ptr_->button_zoom_in->setIcon(QIcon("../icon/zoomin.png"));
    ui_ptr_->button_zoom_in->adjustSize();
    ui_ptr_->button_zoom_out->hide();
    ui_ptr_->button_zoom_out->setIcon(QIcon("../icon/zoomout.png"));
    ui_ptr_->button_zoom_out->adjustSize();

    PlotSet plot_set;

    x_max_value_ = static_cast<float>(kFFTMaxLength);
    x_min_value_ = static_cast<float>(kXMinValue);

    GetYMaxAndMinValue();

    plot_set.x_max_value_ = x_max_value_;
    plot_set.x_min_value_ = x_min_value_;
    plot_set.y_max_value_ = y_max_value_;
    plot_set.y_min_value_ = y_min_value_;
    //qDebug() << "x max value" << x_max_value_;
    //qDebug() << "x min value" << x_min_value_;
    //qDebug() << "y max value" << y_max_value_;
    //qDebug() << "y min value" << y_min_value_;
    plot_set.x_axis_number_marker_ = x_axis_number_marker_;
    plot_set.y_axis_number_marker_ = y_axis_number_marker_;
    zoom_plot_set_vector_.append(plot_set);
}

void FFTDialog::GetYMaxAndMinValue()
{
    y_max_value_ = y_min_value_ = data_array_[0];

    for (int i = 1; i != kFFTDataLength; ++i)
    {
        if (y_max_value_ < data_array_[i])
        {
            y_max_value_ = data_array_[i];
        }

        if (y_min_value_ > data_array_[i])
        {
            y_min_value_ = data_array_[i];
        }
    }

    if ((y_max_value_ - y_min_value_) <= 0.001)
    {
        y_max_value_ += 0.01;
        y_min_value_ -= 0.01;
    }
}

void FFTDialog::RefreshPixmap()
{
    pix_map_ = QPixmap(size());
    pix_map_.fill(this, 0, 0);

    QPainter painter(&pix_map_);
    painter.initFrom(this);

    DrawGrid(&painter);
    DrawCurve(&painter);

    update();
}

void FFTDialog::UpdateZoomSelectRect()
{
    QRect painter_rect = zoom_selected_rect_.normalized();

    update(painter_rect.left(), painter_rect.top(), painter_rect.width(), 1);
    update(painter_rect.left(), painter_rect.top(), 1, painter_rect.height());
    update(painter_rect.left(), painter_rect.bottom(), painter_rect.width(), 1);
    update(painter_rect.right(), painter_rect.top(), 1, painter_rect.height());
}

//void FFTDialog::closeEvent(QCloseEvent *event)
//{
//    qDebug() << "fft dialog close";
//}
