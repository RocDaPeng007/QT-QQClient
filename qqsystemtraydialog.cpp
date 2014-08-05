#include "qqsystemtraydialog.h"
#include "ui_qqsystemtraydialog.h"

#include <QBitmap>
#include <QPainter>
#include <QDebug>
#include <QPropertyAnimation>

// 透明色为品红qRgba(255,0,255,255)
//将非品红色转换成black,品红色转换成white,以做mask图用
//QPixmap Form::convertToBW(const QImage &map)
//{
// QImage img(map);
// for (int i = 0; i < img.height(); i++)
// {
//  for (int j = 0; j < img.width(); j++)
//  {
//   if(img.pixel(j, i) == qRgba(255,0,255,255))
//    img.setPixel(j, i, qRgba(255,255,255,255));//Or you can use qRgba(0,0,0,0) instead for trans
//   else
//    img.setPixel(j, i, qRgba(0,0,0,255));//Or you can use qRgba(0,0,0,0) instead for trans
//  }
// }
// return QPixmap::fromImage(img, Qt::MonoOnly);
//};

//QPixmap Form::convertToBW(const QString &file)
//{
// QImage img;
// img.load(file);
// return convertToBW(img);
//}
//调用方法：
//QPixmap piximg = convertToBW("bg.png");
// piximg.save("kk05.png");

//Qt实现具有反锯齿的圆角窗口：不规则窗口
//http://www.cppblog.com/biao/archive/2011/10/12/158175.html
QQSystemTrayDialog::QQSystemTrayDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::QQSystemTrayDialog)
{
    ui->setupUi(this);

    setWindowFlags(Qt::FramelessWindowHint);
    setAttribute(Qt::WA_TranslucentBackground);

    optionViews();

    //加载一幅有部分区域是透明的图片作为程序的界面
//    QPixmap m_Pixmap;
//    m_Pixmap.load(":/new/images/new/HistoryTranPanel_bg_001.png");
//    //resize( m_Pixmap.size() );
//    //不规则窗口的关键，将图片透明的地方设为穿透
//    setMask( m_Pixmap.mask() );
}

void QQSystemTrayDialog::paintEvent(QPaintEvent*)
{
    QPixmap pixmap;
    pixmap.load(":/new/images/new/HistoryTranPanel_bg_001.png");

    QPainter painter(this);
    painter.drawPixmap(0,0,pixmap.scaled(this->size(),Qt::IgnoreAspectRatio,Qt::SmoothTransformation)); // 绘制不规则背景
}


void QQSystemTrayDialog::optionViews()
{
    ui->lianxirenWidget_tray->ui->trayIconTextLabel->setText(tr("联系人"));
    ui->youxiangWidget->ui->trayIconTextLabel->setText(tr("邮箱"));
    ui->kongjianWidget_tray->ui->trayIconTextLabel->setText(tr("空间"));
    ui->weiboWidget_tray->ui->trayIconTextLabel->setText(tr("微博"));
    ui->swiftiyWidget_tray->ui->trayIconTextLabel->setText(tr("swiftiy"));
}

QQSystemTrayDialog::~QQSystemTrayDialog()
{
    delete ui;
}

/*
**  功能                : 9格图处理
**  picName          : 图片名字
**  titleHeight      : 标题栏高度(单位:像素)
**  BorderLineWidth  : 边框宽度(单位:像素)
**  parent           : 带画背景的窗口句柄
**  返回值              :处理完成的图片
*/
QPixmap* QQSystemTrayDialog::ninePatch(QString picName,int titleHeight,int BorderLineWidth ,QWidget* Wnd)
{
    QPixmap* pix = new QPixmap(picName);

    int pixWidth = pix->width();
    int pixHeight = pix->height();

    QSize WndSize = Wnd->size();
    int DstWidth = WndSize.width();
    int DstHeight = WndSize.height();

    QPixmap pix_1 = pix->copy(0,0,BorderLineWidth,titleHeight);
    QPixmap pix_2 = pix->copy(BorderLineWidth,0,pixWidth-BorderLineWidth*2,titleHeight);
    QPixmap pix_3 = pix->copy(pixWidth-BorderLineWidth,0,BorderLineWidth,titleHeight);

    QPixmap pix_4 = pix->copy(0,titleHeight,BorderLineWidth,pixHeight-titleHeight-BorderLineWidth);
    QPixmap pix_5 = pix->copy(BorderLineWidth,titleHeight,pixWidth-BorderLineWidth*2,pixHeight-titleHeight-BorderLineWidth);
    QPixmap pix_6 = pix->copy(pixWidth-BorderLineWidth,titleHeight,BorderLineWidth,pixHeight-titleHeight-BorderLineWidth);

    QPixmap pix_7 = pix->copy(0,pixHeight-BorderLineWidth,BorderLineWidth,BorderLineWidth);
    QPixmap pix_8 = pix->copy(BorderLineWidth,pixHeight-BorderLineWidth,pixWidth-BorderLineWidth*2,BorderLineWidth);
    QPixmap pix_9 = pix->copy(pixWidth-BorderLineWidth,pixHeight-BorderLineWidth,BorderLineWidth,BorderLineWidth);

    pix_2 = pix_2.scaled(DstWidth-BorderLineWidth*2,titleHeight,Qt::IgnoreAspectRatio);//保持高度拉宽
    pix_4 = pix_4.scaled(BorderLineWidth,DstHeight-titleHeight-BorderLineWidth,Qt::IgnoreAspectRatio);//保持宽度拉高
    pix_5 = pix_5.scaled(DstWidth-3,DstHeight-titleHeight-BorderLineWidth);
    pix_6 = pix_6.scaled(BorderLineWidth,DstHeight-titleHeight-BorderLineWidth,Qt::IgnoreAspectRatio);//保持宽度拉高
    pix_8 = pix_8.scaled(DstWidth-BorderLineWidth*2,BorderLineWidth);//保持高度拉宽


    QPixmap* resultImg =new QPixmap(WndSize);
    QPainter* painter = new QPainter(resultImg);
    if (!resultImg->isNull())
    {
        painter->drawPixmap(0,0,pix_1);
        painter->drawPixmap(3,0,pix_2);
        painter->drawPixmap(DstWidth-3,0,pix_3);
        painter->drawPixmap(0,titleHeight,pix_4);
        painter->drawPixmap(3,titleHeight,pix_5);
        painter->drawPixmap(DstWidth-3,titleHeight,pix_6);
        painter->drawPixmap(0,DstHeight-3,pix_7);
        painter->drawPixmap(3,DstHeight-3,pix_8);
        painter->drawPixmap(DstWidth-3,DstHeight-3,pix_9);
        painter->end();
    }
    return resultImg;
}

void QQSystemTrayDialog::on_morePButton_tray_clicked()
{
    bool open = rect().height()<=(220-61);

    QPropertyAnimation *anim2=new QPropertyAnimation(this, "size");
    anim2->setDuration(300);
    anim2->setStartValue(QSize(rect().width(),
                               open?(220-61):220));
    anim2->setEndValue(QSize(rect().width(),
                             open?(220):(220-61)));
    //anim2->setEasingCurve(QEasingCurve::OutBounce);
    anim2->start();

    QPropertyAnimation *anim1=new QPropertyAnimation(ui->widget_3, "pos");
    anim1->setDuration(300);
    anim1->setStartValue(QPoint(0, open?(220-102):180));
    anim1->setEndValue(QPoint(0, open?180:(220-102)));
    //anim1->setEasingCurve(QEasingCurve::OutBounce);
    anim1->start();
}
