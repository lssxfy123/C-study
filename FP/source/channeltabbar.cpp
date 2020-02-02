
#include "../include/channeltabbar.h"

#include <QMouseEvent>
#include <QDebug>

ChannelTabBar::ChannelTabBar(QWidget* parent /* = NULL */)
: QTabBar(parent)
{
    // setTabsClosable(true);
}

ChannelTabBar::~ChannelTabBar()
{
}

void ChannelTabBar::mouseDoubleClickEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton)
    {
        // qDebug() << currentIndex();

        if (currentIndex() > 0)  // 不删除第一个tab
        {
            removeTab(currentIndex());
        }
    }
    else
    {
        QTabBar::mouseDoubleClickEvent(event);
    }
}

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
