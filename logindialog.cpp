#include "logindialog.h"
#include "ui_logindialog.h"

#include <QPropertyAnimation>
#include <QDebug>
#include <QPainter>
#include <QPen>

LoginDialog::LoginDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LoginDialog)
{
    ui->setupUi(this);

    this->setAttribute(Qt::WA_TranslucentBackground);
    this->setWindowFlags(Qt::CustomizeWindowHint|Qt::Window);
    ui->capsPButtonL->setHidden(true);
    ui->backgroundWidget->setStyleSheet("background-color:rgb(100, 100, 100);border-radius:10px;");
    this->setStyleSheet("border-radius:10px;");

    ui->moreWidgetL->setAutoFillBackground(true);
    ui->moreWidgetL->setStyleSheet("border-bottom-right-radius:10px;\
                                   border-bottom-left-radius:10px;");
}

LoginDialog::~LoginDialog()
{
    delete ui;
}

void LoginDialog::on_closePButtonL_clicked()
{
     this->close();
}

//void LoginDialog::paintEvent(QPaintEvent* pv)
//{
//    QPainter painter(this);
//    painter.setCompositionMode( QPainter::CompositionMode_Clear );
//    painter.fillRect(rect(), Qt::SolidPattern);//QColor(0, 0, 0, 0));

//}

//    QDialog::paintEvent(p);

//    QPainter painter(this);
//    QPen pen;                                 //创建一个画笔
//    pen.setColor(Qt::darkCyan);
//    pen.setWidth(5);
//    painter.setPen(pen);

//    //学习绘画功能。
//    //
//    qsrand(time(NULL));
//    for(int i = 0;i<2;i++){
//        //myLine* pLine = lines[i];
//        QPoint startPnt(qrand()%100, qrand()%100);
//        QPoint endPnt(qrand()%100+100, qrand()%100+100);
//        painter.drawLine(startPnt, endPnt);
//    }
//}

void LoginDialog::mousePressEvent(QMouseEvent *event)
{
    if(event->button() == Qt::LeftButton)
    {
        oldPos = event->globalPos();
        press = true;
    }
}

void LoginDialog::mouseMoveEvent(QMouseEvent *event)
{
    if (press)
    {
        this->move(this->pos() + event->globalPos() - oldPos);
        oldPos = event->globalPos();
    }
}

void LoginDialog::mouseReleaseEvent(QMouseEvent *event)
{
    press = false;
}

void LoginDialog::on_loginPButtonL_clicked()
{
    //登陆
}

void LoginDialog::on_statusPButtonL_clicked()
{
    //修改登陆状态
    //是正常登陆，还是隐身登陆
    //0: 正常登陆
    //1: 隐身登陆
    ui->statusPButtonL->flag = !ui->statusPButtonL->flag;

    if (ui->statusPButtonL->flag)
    {
        ui->statusPButtonL->setStyleSheet("QPushButton{border:0px groove gray;\
                                          background-image: url(\":/images/images/background/Header+Search_Hide_Normal.png\")}");
        ui->statusPButtonL->setStyleSheet("QPushButton:hover{border:0px groove gray;\
                                          background-image: url(\":/images/images/background/Header+Search_Hide_Hover.png\")}");
    }
    else
    {
        ui->statusPButtonL->setStyleSheet("QPushButton{border:0px groove gray;\
                                          background-image: url(\":/images/images/background/Header+Search_Online_Normal.png\")}");
        ui->statusPButtonL->setStyleSheet("QPushButton:hover{border:0px groove gray;\
                                          background-image: url(\":/images/images/background/Header+Search_Online_Hover.png\")}");
    }
}

void LoginDialog::on_morePButton_clicked()
{
    //打开其它功能。
    ui->morePButton->flag = !ui->morePButton->flag;

    //修改背景图片
    if (!ui->morePButton->flag)
    {
        ui->morePButton->setStyleSheet("QPushButton{\
                                       border:0px groove gray; \
                                       background-image: url(\":/images/images/background/LoginWindow_DownArrow_Normal.png\") repeat fixed!important;} \
                                       QPushButton:click{\
                                       border:0px groove gray; \
                                       background-image: url(\":/images/images/background/LoginWindow_DownArrow_Click.png\") repeat fixed!important;} ");
    }
    else
    {
        ui->morePButton->setStyleSheet("QPushButton{\
                                       border:0px groove gray; \
                                       background-image: url(\":/images/images/background/LoginWindow_UpArrow_Normal.png\") repeat fixed!important;} \
                                       QPushButton:click{\
                                       border:0px groove gray; \
                                       background-image: url(\":/images/images/background/LoginWindow_UpArrow_Click.png\") repeat fixed!important;} ");
    }
    //0.3s
    QPropertyAnimation *anim1=new QPropertyAnimation(ui->moreWidgetL, "pos");
    anim1->setDuration(300);
    anim1->setStartValue(QPoint(0, ui->morePButton->flag?(318-80):318));
    anim1->setEndValue(QPoint(0, ui->morePButton->flag?318:(318-80)));
    //anim1->setEasingCurve(QEasingCurve::OutBounce);
    anim1->start();

    QPropertyAnimation *anim2=new QPropertyAnimation(this, "size");
    anim2->setDuration(300);
    anim2->setStartValue(QSize(249, ui->morePButton->flag?318:(318+80)));
    anim2->setEndValue(QSize(249, ui->morePButton->flag?(318+80):318));
    //anim2->setEasingCurve(QEasingCurve::OutBounce);
    anim2->start();

    //延迟0.3秒执行

}

void LoginDialog::on_pswLEditL_textEdited(const QString &arg1)
{

}

void LoginDialog::keyPressEvent(QKeyEvent *event)
{
    if(event->key() == Qt::Key_CapsLock)
    {
//        if(event->) {
//            ui->capsPButtonL->show();
//        }
//        else {
//            ui->capsPButtonL->hide();
//        }
    }

    QDialog::keyPressEvent(event);
}
