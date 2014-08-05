#include "qqpopmenuwidget.h"

#include <QDebug>

QQPopMenuWidget::QQPopMenuWidget(QWidget *parent) :
    QWidget(parent)
{
}

void QQPopMenuWidget::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::RightButton)
    {
        if (!popMenu)
        {
            return ;
        }
        emit onpopmenuwillshow(this, popMenu);

        qDebug()<<"x: "<<this->geometry().x();
        qDebug()<<"y: "<<this->geometry().y();
        qDebug()<<"widget: "<<this->geometry().width();
        qDebug()<<"height: "<<this->geometry().height();
        qDebug()<<QCursor::pos().x()<<": " << QCursor::pos().y();
        popMenu->exec(QCursor::pos());
    }
}

void QQPopMenuWidget::setPopMenu(QMenu *menu)
{
    popMenu = menu;
}
