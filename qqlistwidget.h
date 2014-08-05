#ifndef QQLISTWIDGET_H
#define QQLISTWIDGET_H

#include <QListWidget>
#include <QList>
#include <QHash>
#include <QMenu>

#include "qqcell.h"
#include "qqlistviewgroup.h"
#include "qqlistviewchild.h"

class QQListWidget : public QListWidget
{
    Q_OBJECT
public:
    explicit QQListWidget(QWidget *parent = 0);

signals:
    void on_popmenu_will_show(QQListWidget *listWidget,QQPopMenuWidget *widget, QMenu *menu);

public slots:
    void onGroupOpenDidChanged(QQListViewGroup *group);

    void onChildDidSelected(QQListViewChild *child);
    void onChildDidDoubleClicked(QQListViewChild *child);

    void on_popmenuWillShow(QQPopMenuWidget *widget, QMenu *menu);

private:
    QList<QQCell *> cells;                      //所有的数据
    QMenu *mGroupMenu;
    QMenu *mChildMenu;

public:
    void insertQQCell(QQCell * cell);
    void removeQQCell(QQCell * cell);
    void upload();
    QQCell *getGroupForName(QString *groupName);

    void setGroupPopMenu(QMenu *menu);
    void setChildPopMenu(QMenu *menu);

private:
    void setBackGroundColor(QWidget *widget,int index);
};

#endif // QQLISTWIDGET_H
