#include "qqtrayiconwidget.h"

QQTrayIconWidget::QQTrayIconWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::QQTrayIconWidget)
{
    ui->setupUi(this);

    ui->trayIconTextLabel->setAlignment(Qt::AlignCenter);
    QFont ft;
    ft.setPointSize(12);
    ui->trayIconTextLabel->setFont(ft);
}

QQTrayIconWidget::~QQTrayIconWidget()
{
    delete ui;
}
