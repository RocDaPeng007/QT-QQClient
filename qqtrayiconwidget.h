#ifndef QQTRAYICONWIDGET_H
#define QQTRAYICONWIDGET_H

#include <QWidget>

#include "ui_qqtrayiconwidget.h"

namespace Ui {
class QQTrayIconWidget;
}

class QQTrayIconWidget : public QWidget
{
    Q_OBJECT

public:
    explicit QQTrayIconWidget(QWidget *parent = 0);
    ~QQTrayIconWidget();


public:
    int flag;

    Ui::QQTrayIconWidget *ui;
};

#endif // QQTRAYICONWIDGET_H
