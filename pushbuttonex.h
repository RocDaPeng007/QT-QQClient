#ifndef PUSHBUTTONEX_H
#define PUSHBUTTONEX_H

#include <QPushButton>

class PushButtonEx : public QPushButton
{
    Q_OBJECT
public:
    explicit PushButtonEx(QWidget *parent = 0);

public:
    int flag;       //作为一个标识使用

signals:

public slots:

};

#endif // PUSHBUTTONEX_H
