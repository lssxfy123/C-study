
#include "../include/channeldialog.h"

#include <QFile>
#include <QTextStream>
#include <QStylePainter>
#include <QtDebug>

#include "../ui/ui_channel_dialog.h"


ChannelDialog::ChannelDialog(QWidget* parent /* = NULL */)
: QDialog(parent), ui_ptr_(new Ui::channel_dialog)
{
    ui_ptr_->setupUi(this);

    // setMouseTracking(true);  // 设置为true，鼠标移动就会响应mouseMoveEvent，否则只有鼠标按下再移动才会响应mouseMoveEvent
    connect(ui_ptr_->button_zoom_in, SIGNAL(clicked()), this, SLOT(OnZoomIn()));
    connect(ui_ptr_->button_zoom_out, SIGNAL(clicked()), this, SLOT(OnZoomOut()));
    Init();
    //InitPlotSet();
    //RefreshPixmap();

    // setModal(false);
    // setWindowFlags(Qt::WindowStaysOnTopHint);
}

ChannelDialog::~ChannelDialog()
{
    delete ui_ptr_;
    ui_ptr_ = NULL;
}

// 设置绘图数据
void ChannelDialog::SetData(float* data)
{
    for (int i = 0; i != kChannelDataLength; ++i)
    {
        data_array_[i] = data[i];
    }

    //QFile file("yf-koujian-40.csv");
    //file.open(QIODevice::ReadOnly);
    //QTextStream read_stream(&file);

    //int index = 0;
    //while (!read_stream.atEnd())
    //{
    //    data_array_[index] = read_stream.readLine().toFloat();
    //    ++index;
    //}

    //file.close();
    //read_stream.reset();

    InitPlotSet();
    RefreshPixmap();
}

// 设置仪器是否被标定
void ChannelDialog::SetIsChannelDemarcate(bool is_instrument_demarcate)
{
    is_channel_demarcate_ = is_instrument_demarcate;
}

//设置Y轴的最大值和最小值
void ChannelDialog::SetYMaxAndMinValue(float y_max_value, float y_min_value)
{
    is_set_y_max_min_value_ = true;
    y_max_value_ = y_max_value;
    y_min_value_ = y_min_value;
}

//void ChannelDialog::mousePressEvent(QMouseEvent *event)
//{
//    // 绘图时用到的矩形区域
//    QRect painter_rect(50, 30, width() - 100, height() - 80);
//
//    if (event->button() == Qt::LeftButton)
//    {
//        if (painter_rect.contains(event->pos()))
//        {
//            is_clicked_ = true;
//            zoom_selected_rect_.setTopLeft(event->pos());
//            zoom_selected_rect_.setBottomRight(event->pos());
//            UpdateZoomSelectRect();
//            // zoom_selected_rect_.normalized();
//        }
//    }
//}

void ChannelDialog::mouseMoveEvent(QMouseEvent *event)
{
    QRect painter_rect(50, 30, width() - 100, height() - 80);

    if (hasMouseTracking())
    {
        if (is_zoom_in_clicked_)
        {
            if (painter_rect.contains(event->pos()))
            {
                QCursor cursor_zoom_in(QPixmap("../icon/zoomin.png"));
                setCursor(cursor_zoom_in);
            }
            else
            {
                unsetCursor();
            }
        }
        else if (is_zoom_out_clicked_)
        {
            if (painter_rect.contains(event->pos()))
            {
                QCursor cursor_zoom_out(QPixmap("../icon/zoomout.png"));
                setCursor(cursor_zoom_out);
            }
            else
            {
                unsetCursor();
            }
        }
        else
        {
            unsetCursor();
        }
    }
    else
    {
        if (is_button_press_)
        {
            if (painter_rect.contains(event->pos()))
            {
                UpdateZoomSelectRect();
                zoom_selected_rect_.setBottomRight(event->pos());
                // zoom_selected_rect_.normalized();
                UpdateZoomSelectRect();
            }
        }
    }

}

void ChannelDialog::mousePressEvent(QMouseEvent *event)
{
    if (!hasMouseTracking())
    {
        // 绘图时用到的矩形区域
        QRect painter_rect(50, 30, width() - 100, height() - 80);

        if (event->button() == Qt::LeftButton)
        {
            if (painter_rect.contains(event->pos()))
            {
                is_button_press_ = true;
                zoom_selected_rect_.setTopLeft(event->pos());
                zoom_selected_rect_.setBottomRight(event->pos());
                UpdateZoomSelectRect();
            }
        }
    }
}

void ChannelDialog::mouseReleaseEvent(QMouseEvent *event)
{
    if ((event->button() == Qt::LeftButton))
    {
        // is_clicked_ = false;

        QRect painter_rect(50, 30, width() - 100, height() - 80);

        if (hasMouseTracking())
        {
            if (painter_rect.contains(event->pos()))
            {
                if (is_zoom_in_clicked_)
                {
                    int x = event->pos().x();
                    int y = event->pos().y();
                    int zoom_select_width = static_cast<int>(painter_rect.width() / 3) ;
                    int zoom_select_height = static_cast<int>(painter_rect.height() / 3);

                    int left = x - static_cast<int>(zoom_select_width / 2);
                    int top = y - static_cast<int>(zoom_select_height / 2);
                    int right = x + static_cast<int>(zoom_select_width / 2);
                    int bottom = y + static_cast<int>(zoom_select_height / 2);

                    if (left < painter_rect.left())
                    {
                        left = painter_rect.left();
                        right = left + zoom_select_width;
                    }
                    else if (right > painter_rect.right())
                    {
                        right = painter_rect.right();
                        left = right - zoom_select_width;
                    }

                    if (top < painter_rect.top())
                    {
                        top = painter_rect.top();
                        bottom = top + zoom_select_height;
                    } else if (bottom > painter_rect.bottom())
                    {
                        bottom = painter_rect.bottom();
                        top = bottom - zoom_select_height;
                    }

                    zoom_selected_rect_.setRect(left, top, zoom_select_width, zoom_select_height);

                    zoom_selected_rect_.translate(-50, -30);

                    //qDebug() << "painter rect left" << painter_rect.left();
                    //qDebug() << "painter rect top" << painter_rect.top();
                    //qDebug() << "painter rect right" << painter_rect.right();
                    //qDebug() << "painter rect bottom" << painter_rect.bottom();

                    //qDebug() << "zoom select rect left" << zoom_selected_rect_.left();
                    //qDebug() << "zoom select rect top" << zoom_selected_rect_.top();
                    //qDebug() << "zoom select rect right" << zoom_selected_rect_.right();
                    //qDebug() << "zoom select rect bottom" << zoom_selected_rect_.bottom();

                    PlotSet previous_plot_set = zoom_plot_set_vector_[current_zoom_index_];
                    PlotSet plot_set;
                    float dx = previous_plot_set.SpanX() / (width() - 100);
                    float dy = previous_plot_set.SpanY() / (height() - 80);
                    plot_set.x_min_value_ = previous_plot_set.x_min_value_ + dx * zoom_selected_rect_.left();
                    plot_set.x_max_value_ = previous_plot_set.x_min_value_ + dx * zoom_selected_rect_.right();
                    plot_set.y_min_value_ = previous_plot_set.y_max_value_ - dy * zoom_selected_rect_.bottom();
                    plot_set.y_max_value_ = previous_plot_set.y_max_value_ - dy * zoom_selected_rect_.top();

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
                    ++current_zoom_index_;
                }
                else if (is_zoom_out_clicked_)
                {
                    if (current_zoom_index_ > 0)
                    {
                        --current_zoom_index_;
                    }
                }
                RefreshPixmap();
            }
        }
        else
        {
            is_button_press_ = false;

            UpdateZoomSelectRect();
            zoom_selected_rect_ = zoom_selected_rect_.normalized();

            if (zoom_selected_rect_.width() < 5 || zoom_selected_rect_.height() < 5)
            {
                // RefreshPixmap();
                return;
            }

            zoom_selected_rect_.translate(-50, -30);

            PlotSet previous_plot_set = zoom_plot_set_vector_[current_zoom_index_];
            PlotSet plot_set;
            float dx = previous_plot_set.SpanX() / (width() - 100);
            float dy = previous_plot_set.SpanY() / (height() - 80);
            plot_set.x_min_value_ = previous_plot_set.x_min_value_ + dx * zoom_selected_rect_.left();
            plot_set.x_max_value_ = previous_plot_set.x_min_value_ + dx * zoom_selected_rect_.right();
            plot_set.y_min_value_ = previous_plot_set.y_max_value_ - dy * zoom_selected_rect_.bottom();
            plot_set.y_max_value_ = previous_plot_set.y_max_value_ - dy * zoom_selected_rect_.top();

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
            ++current_zoom_index_;
            RefreshPixmap();
        }


    }
}

void ChannelDialog::paintEvent(QPaintEvent *event)
{
    // qDebug() << "paint event";
    QStylePainter painter(this);
    painter.drawPixmap(0, 0, pix_map_);

    if (is_button_press_) {
        QPen pen(Qt::red, 1.5, Qt::DotLine);
        painter.setPen(pen);
        painter.drawRect(zoom_selected_rect_.normalized()
            .adjusted(0, 0, -1, -1));
        // return;
    }

    //if (is_clicked_) {
    //    QPen pen(Qt::red, 1.5, Qt::DotLine);
    //    painter.setPen(pen);
    //    painter.drawRect(zoom_selected_rect_.normalized()
    //        .adjusted(0, 0, -1, -1));
    //    // return;
    //}

    // RefreshPixmap();
}

void ChannelDialog::resizeEvent(QResizeEvent* event)
{
    // qDebug() << "resize event";
    RefreshPixmap();
}

void ChannelDialog::OnZoomIn()
{
    if ((!is_zoom_in_clicked_) || (is_zoom_out_clicked_))
    {
        //QCursor cursor_zoom_in(QPixmap("../icon/zoomin.png"));
        //setCursor(cursor_zoom_in);
        setMouseTracking(true);  // 设置为true，鼠标移动就会响应mouseMoveEvent，否则只有鼠标按下再移动才会响应mouseMoveEvent
        is_zoom_in_clicked_ = true;
        is_zoom_out_clicked_ = false;
    }
    else
    {
        //unsetCursor();
        setMouseTracking(false);
        is_zoom_in_clicked_ = false;
    }

    //if (current_zoom_index_ < (zoom_plot_set_vector_.count() - 1))
    //{
    //    // ++current_zoom_index_;
    //    // ui_ptr_->button_zoom_in->setEnabled(current_zoom_index_ < (zoom_plot_set_vector_.count() - 1));
    //    // ui_ptr_->button_zoom_out->setEnabled(true);
    //    // ui_ptr_->button_zoom_out->show();
    //    // RefreshPixmap();
    //}
}

void ChannelDialog::OnZoomOut()
{
    if ((!is_zoom_out_clicked_) || is_zoom_in_clicked_)
    {
        setMouseTracking(true);  // 设置为true，鼠标移动就会响应mouseMoveEvent，否则只有鼠标按下再移动才会响应mouseMoveEvent
        is_zoom_out_clicked_ = true;
        is_zoom_in_clicked_ = false;
    }
    else
    {
        setMouseTracking(false);  // 设置为true，鼠标移动就会响应mouseMoveEvent，否则只有鼠标按下再移动才会响应mouseMoveEvent
        is_zoom_out_clicked_ = false;
    }

    //if (current_zoom_index_ > 0)
    //{
    //    // --current_zoom_index_;
    //    // qDebug() << "current zoom index" << current_zoom_index_;
    //    // ui_ptr_->button_zoom_out->setEnabled(current_zoom_index_ > 0);
    //    // ui_ptr_->button_zoom_in->setEnabled(true);
    //    // ui_ptr_->button_zoom_in->show();
    //    // RefreshPixmap();
    //}
}

void ChannelDialog::DrawCurve(QPainter* painter_ptr)
{
    QRect painter_rect(50, 30, width() - 100, height() - 80);

    if (!painter_rect.isValid())
    {
        return;
    }

    painter_ptr->setClipRect(painter_rect.adjusted(1, 1, -1, -1));

    PlotSet plot_set = zoom_plot_set_vector_[current_zoom_index_];

    QPolygonF poly_line(kChannelDataLength);

    float x_axis_array[kChannelDataLength];

    for (int i = 0; i != kChannelDataLength; ++i)
    {
        x_axis_array[i] = static_cast<float>(i * static_cast<float>(kXMaxValue) / static_cast<float>(kChannelDataLength - 1));
    }

    //float x_min_value = x_axis_array[0];
    //float x_max_value = x_axis_array[kChannelDataLength - 1];

    for (int j = 0; j != kChannelDataLength; ++j)
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

        //qDebug() << "x position" << x_position << j;
        //qDebug() << "y position" << y_position << j;

        poly_line[j] = QPointF(x_position, y_position);
    }

    QPen pen(Qt::red, 3, Qt::SolidLine);
    painter_ptr->setPen(pen) ;
    painter_ptr->drawPolyline(poly_line);
}

void ChannelDialog::DrawGrid(QPainter* painter_ptr)
{
    QRect painter_rect(50, 30, width() - 100, height() - 80);
    // QRect painter_rect(Margin, Margin, width() - Margin, height() - Margin);

    if (!painter_rect.isValid())
    {
        return;
    }

    //qDebug() << width() << painter_rect.width();
    //qDebug() << height() << painter_rect.height();
    //qDebug() << geometry().right() << painter_rect.right();
    //qDebug() << geometry().bottom() << painter_rect.bottom();

    QPen grid_pen;  // 用来绘制网络线的画笔
    grid_pen.setWidth(1);
    // grid_pen.setBrush(QColor(qRgb(50, 109, 159)));
    grid_pen.setStyle(Qt::DotLine);  // 圆点线

    QPen axis_pen;  // 用来绘制坐标轴的画笔

    QBrush old_brush = painter_ptr->brush();
    painter_ptr->setPen(grid_pen);
    // painter_ptr->setBrush(QColor(qRgb(0, 89, 159)));

    //if (!is_channel_demarcate_)
    //{
    //    y_min_value_ = kMinPixelNumber;
    //    y_max_value_ = kMaxPixelNumber;
    //}


    //if (!is_set_y_max_min_value_)
    //{
    //    // 获取Y轴的最大值和最小值
    //    GetYMaxAndMinValue();
    //}

    // painter_ptr->drawRect(painter_rect.adjusted(0, 0, -1, -1));

    // 设置放大和缩小按钮的位置
    int x_zoom_in = static_cast<int>((geometry().width() - (ui_ptr_->button_zoom_in->width() + ui_ptr_->button_zoom_out->width() + 20)) / 2);
    int y_zoom_in = 0;
    int x_zoom_out = x_zoom_in + ui_ptr_->button_zoom_in->width() + 20;
    int width_zoom_in = ui_ptr_->button_zoom_in->width();
    int height_zoom_in = ui_ptr_->button_zoom_in->height();
    ui_ptr_->button_zoom_in->setGeometry(x_zoom_in, y_zoom_in, width_zoom_in, height_zoom_in);
    ui_ptr_->button_zoom_out->setGeometry(x_zoom_out, y_zoom_in, width_zoom_in, height_zoom_in);

    // 横坐标为时间
    int x = static_cast<int>((geometry().width() - ui_ptr_->label_X->geometry().width()) / 2);
    int y = static_cast<int>((geometry().height() - 30));
    int width = ui_ptr_->label_X->width();
    int height = ui_ptr_->label_X->height();
    ui_ptr_->label_X->setGeometry(x, y, width, height);

    PlotSet plot_set = zoom_plot_set_vector_[current_zoom_index_];

    for (int i = 0; i != plot_set.x_axis_number_marker_; ++i)
    {
        int x = painter_rect.left() + static_cast<int>(i * (painter_rect.width() - 1) / (plot_set.x_axis_number_marker_ - 1));
        float X_label = static_cast<float>(plot_set.x_min_value_ 
            + (i * (plot_set.x_max_value_ - plot_set.x_min_value_) / (plot_set.x_axis_number_marker_ - 1)));

        painter_ptr->setPen(grid_pen);
        painter_ptr->drawLine(x, painter_rect.top(), x, painter_rect.bottom());

        // qDebug() << "x = " << x;

        painter_ptr->drawText(x - 50, painter_rect.bottom() + 5, 100, 20, Qt::AlignHCenter | Qt::AlignTop, QString::number(X_label));
    }

    // 未标定，纵坐标为像元
    // 已标定，纵坐标为力/牛
    // Y轴
    x = 0;
    y = static_cast<int>((geometry().height() - ui_ptr_->label_Y->height()) / 2);
    width = ui_ptr_->label_Y->width();
    height = ui_ptr_->label_Y->height();
    ui_ptr_->label_Y->setGeometry(x, y, width, height);

    if (!is_channel_demarcate_)
    {
        ui_ptr_->label_Y->setText("像\n元");
    }

    for (int j = 0; j != plot_set.y_axis_number_marker_; ++j)
    {
        int y = painter_rect.bottom() - static_cast<int>(j * (painter_rect.height() - 1) / (plot_set.y_axis_number_marker_ - 1));

        if (is_channel_demarcate_)
        {
            float Y_label = static_cast<float>(plot_set.y_min_value_ 
                + (j * (plot_set.y_max_value_ - plot_set.y_min_value_) / (plot_set.y_axis_number_marker_ - 1)));

            QString label_string = QString::number(Y_label, 'f', 2);  // 保留小数点后两位有效数字
            painter_ptr->setPen(grid_pen);
            painter_ptr->drawLine(painter_rect.left(), y, painter_rect.right(), y);
            painter_ptr->drawText(painter_rect.left() - 70, y - 10, 70, 25, Qt::AlignRight | Qt::AlignVCenter, QString::number(Y_label));
        }
        else
        {
            int Y_label = static_cast<int>(plot_set.y_min_value_ + (j * (plot_set.y_max_value_ - plot_set.y_min_value_) / (plot_set.y_axis_number_marker_ - 1)));
            // float Y_label = static_cast<float>(y_min_value_ + (j * (y_max_value_ - y_min_value_) / (kYAxisNumMarker - 1)));

            painter_ptr->setPen(grid_pen);
            painter_ptr->drawLine(painter_rect.left(), y, painter_rect.right(), y);
            painter_ptr->drawText(painter_rect.left() - 70, y - 10, 70, 25, Qt::AlignRight | Qt::AlignVCenter, QString::number(Y_label));
        }

    }

    painter_ptr->setPen(axis_pen);
    painter_ptr->setBrush(old_brush);
    painter_ptr->drawRect(painter_rect.adjusted(0, 0, -1, -1));
}

// 获取Y轴的最大值和最小值
void ChannelDialog::GetYMaxAndMinValue()
{
    y_max_value_ = y_min_value_ = data_array_[0];

    for (int i = 1; i != kChannelDataLength; ++i)
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

// 初始化
void ChannelDialog::Init()
{
    for (int i = 0; i != kChannelDataLength; ++i)
    {
        data_array_[i] = 0.0;
    }

    x_axis_number_marker_ = kXAxisNumMarker;
    y_axis_number_marker_ = kYAxisNumMarker;
    is_channel_demarcate_ = false;
    is_set_y_max_min_value_ = false;

    InitPlotSet();
}

void ChannelDialog::InitPlotSet()
{
    zoom_plot_set_vector_.clear();
    is_zoom_in_clicked_ = false;
    is_zoom_out_clicked_ = false;
    is_button_press_ = false;
    current_zoom_index_ = 0;
    // ui_ptr_->button_zoom_in->hide();
    ui_ptr_->button_zoom_in->setIcon(QIcon("../icon/zoomin.png"));
    ui_ptr_->button_zoom_in->adjustSize();
    // ui_ptr_->button_zoom_out->hide();
    ui_ptr_->button_zoom_out->setIcon(QIcon("../icon/zoomout.png"));
    ui_ptr_->button_zoom_out->adjustSize();

    PlotSet plot_set;

    x_max_value_ = static_cast<float>(kXMaxValue);
    x_min_value_ = static_cast<float>(kXMinValue);

    if (!is_set_y_max_min_value_)
    {
        GetYMaxAndMinValue();
    }

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

void ChannelDialog::RefreshPixmap()
{
    pix_map_ = QPixmap(size());
    pix_map_.fill(this, 0, 0);

    QPainter painter(&pix_map_);
    painter.initFrom(this);

    DrawGrid(&painter);
    DrawCurve(&painter);

    update();
}

void ChannelDialog::UpdateZoomSelectRect()
{
    QRect painter_rect = zoom_selected_rect_.normalized();

    update(painter_rect.left(), painter_rect.top(), painter_rect.width(), 1);
    update(painter_rect.left(), painter_rect.top(), 1, painter_rect.height());
    update(painter_rect.left(), painter_rect.bottom(), painter_rect.width(), 1);
    update(painter_rect.right(), painter_rect.top(), 1, painter_rect.height());
}
