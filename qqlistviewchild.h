#ifndef QQLISTVIEWCHILD_H
#define QQLISTVIEWCHILD_H

#include <QWidget>
#include <QMouseEvent>

#include "ui_qqlistviewchild.h"
#include "qqcell.h"
#include "qqpopmenuwidget.h"

namespace Ui {
class QQListViewChild;
}

class QQListViewChild : public QQPopMenuWidget
{
    Q_OBJECT

public:
    explicit QQListViewChild(QQPopMenuWidget *parent = 0);
    ~QQListViewChild();

signals:
    void onChildDidSelected(QQListViewChild *child);
    void onChildDidDoubleClicked(QQListViewChild *child);

protected:
    void mousePressEvent(QMouseEvent *ev);
    void mouseDoubleClickEvent(QMouseEvent * event);

public:
    Ui::QQListViewChild *ui;

    QQCell *cell;
};

#endif // QQLISTVIEWCHILD_H
