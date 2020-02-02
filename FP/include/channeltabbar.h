#ifndef CHANNELTABBAR_H
#define CHANNELTABBAR_H

#include <QTabBar>

#include "../include/global.h"


class ChannelTabBar : public QTabBar
{
    Q_OBJECT

  public:
    ChannelTabBar(QWidget* parent = NULL);
    ~ChannelTabBar();

  protected:
    void mouseDoubleClickEvent(QMouseEvent *event);
    // void mousePressEvent(QMouseEvent *event);
    // bool eventFilter(QObject *target, QEvent *event);

};


#endif  // CHANNELTABBAR_H
