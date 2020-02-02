#ifndef CHANNELTABWIDGET_H
#define CHANNELTABWIDGET_H

#include <QTabWidget>

#include "../include/channeltabbar.h"
#include "../include/global.h"

namespace Ui {
    class channel_tab;
};

class ChannelTabBar;

class ChannelTabWidget : public QTabWidget
{
    Q_OBJECT

  public:
    ChannelTabWidget(QWidget* parent = NULL, ChannelNumber cannel_number = CHANNEL_1);
    ~ChannelTabWidget();

  public:
    ChannelNumber GetChannelNumber() const;

  protected:
    void closeEvent(QCloseEvent *event);
    // void mousePressEvent(QMouseEvent *event);
    // bool eventFilter(QObject *target, QEvent *event);

  signals:
    void cancelChannel(ChannelNumber);

  private:
    Ui::channel_tab* ui_ptr_;
    ChannelTabBar* channel_tab_bar_ptr_;
    ChannelNumber channel_number_;
};


#endif  // CHANNELTABWIDGET_H
