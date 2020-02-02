
#include "../include/channeltabwidget.h"

#include <QMouseEvent>
#include <QDebug>

#include "../ui/ui_channel_tab.h"

ChannelTabWidget::ChannelTabWidget(QWidget* parent /* = NULL */ , ChannelNumber channel_number)
: QTabWidget(parent), ui_ptr_(new Ui::channel_tab)
{
    ui_ptr_->setupUi(this);
    setWindowFlags(Qt::WindowStaysOnTopHint);
    setAttribute(Qt::WA_DeleteOnClose);
    channel_number_ = channel_number;

    channel_tab_bar_ptr_ = NULL;
    channel_tab_bar_ptr_ = new ChannelTabBar;
    clear();
    setTabBar(channel_tab_bar_ptr_);

    // installEventFilter(this);
}

ChannelTabWidget::~ChannelTabWidget()
{
    delete channel_tab_bar_ptr_;
    channel_tab_bar_ptr_ = NULL;

    delete ui_ptr_;
    ui_ptr_ = NULL;
}

ChannelNumber ChannelTabWidget::GetChannelNumber() const
{
    return channel_number_;
}

void ChannelTabWidget::closeEvent(QCloseEvent *event)
{
    emit cancelChannel(channel_number_);
}

//void ChannelTabWidget::mousePressEvent(QMouseEvent *event)
//{
//    if (event->button() == Qt::LeftButton)
//    {
//        qDebug() << currentIndex();
//    }
//    else
//    {
//        QTabWidget::mousePressEvent(event);
//    }
//}

//bool ChannelTabWidget::eventFilter(QObject *target, QEvent *event)
//{
//    if (event->type() == QEvent::MouseButtonDblClick)
//    {
//        QMouseEvent* mouse_event = static_cast<QMouseEvent*>(event);
//
//        if (mouse_event->button() == Qt::LeftButton)
//        {
//            qDebug() << currentIndex();
//        }
//    }
//
//    return true;
//}
