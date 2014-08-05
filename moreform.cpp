#include "moreform.h"
#include "ui_moreform.h"

#include <QPainter>

MoreForm::MoreForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MoreForm)
{
    ui->setupUi(this);
    this->setAttribute(Qt::WA_TranslucentBackground);
}

void MoreForm::paintEvent(QPaintEvent* event)
{
    QPainter p(this);
    p.fillRect(rect(), QColor(255,255,255,125));
}

MoreForm::~MoreForm()
{
    delete ui;
}

void MoreForm::on_forgetPButton_clicked()
{
}

void MoreForm::on_rememberCBox_stateChanged(int arg1)
{

}

void MoreForm::on_autoLoginCBox_stateChanged(int arg1)
{

}

void MoreForm::on_registerPButton_clicked()
{

}
