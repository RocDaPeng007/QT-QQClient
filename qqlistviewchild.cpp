#include "qqlistviewchild.h"

#include <QDebug>

QQListViewChild::QQListViewChild(QQPopMenuWidget *parent) :
    QQPopMenuWidget(parent),
    ui(new Ui::QQListViewChild)
{
    ui->setupUi(this);

    //
    ui->childIconLabel->setStyleSheet("border-image:url(:/icon/images/icon/logo64X64.png) scaled contents");
}

QQListViewChild::~QQListViewChild()
{
    delete ui;
}

void QQListViewChild::mousePressEvent(QMouseEvent *ev)
{
    QQPopMenuWidget::mousePressEvent(ev);

    qDebug()<<"mouseReleaseEvent";
    if (ev->button() == Qt::LeftButton)
    {
        emit onChildDidSelected(this);
    }
}

void QQListViewChild::mouseDoubleClickEvent(QMouseEvent * event)
{
    emit onChildDidDoubleClicked(this);
}
