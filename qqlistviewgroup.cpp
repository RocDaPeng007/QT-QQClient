#include "qqlistviewgroup.h"

#include <QDebug>

QQListViewGroup::QQListViewGroup(QQPopMenuWidget *parent) :
    QQPopMenuWidget(parent),
    ui(new Ui::QQListViewGroup)
{
    ui->setupUi(this);

    //
    ui->groupSubTitleLabel->setAlignment(Qt::AlignRight);
}

QQListViewGroup::~QQListViewGroup()
{
    delete ui;
}

void QQListViewGroup::setQQCell(QQCell *c)
{
    cell = c;
    if (cell->isOpen)
    {
        ui->groupIconLabel->setPixmap(QPixmap(":/images/images/background/aio_arrow_down.png"));
    }
    else
    {
        ui->groupIconLabel->setPixmap(QPixmap(":/images/images/background/aio_arrow_right.png"));
    }
}

void QQListViewGroup::mousePressEvent(QMouseEvent *ev)
{
    QQPopMenuWidget::mousePressEvent(ev);
    qDebug()<<"QQListViewGroup::mousePressEvent";

    if (ev->button() != Qt::LeftButton)
    {
        return ;
    }

    cell->isOpen = !cell->isOpen;
    if (cell->isOpen)
    {
        ui->groupIconLabel->setPixmap(QPixmap(":/images/images/background/aio_arrow_down.png"));
    }
    else
    {
        ui->groupIconLabel->setPixmap(QPixmap(":/images/images/background/aio_arrow_right.png"));
    }

    emit onGroupOpenStatusDidChanged(this);
}
