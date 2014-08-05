#include "mainwindow.h"
#include <QApplication>
#include <QTranslator>
#include <QFile>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

    //加载语言包
    QTranslator translator;
    bool b = false;
    b = translator.load("cn.qm");
    a.installTranslator(&translator);

    QString qss;

    QFile qssFile(":/css/styles.qss");
    qssFile.open(QFile::ReadOnly);

    if(qssFile.isOpen())
    {

        qss = QLatin1String(qssFile.readAll());
        qApp->setStyleSheet(qss);
        qssFile.close();
    }

    w.show();

    qssFile.close();

    return a.exec();
}
