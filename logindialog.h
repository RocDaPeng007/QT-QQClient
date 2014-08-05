#ifndef LOGINDIALOG_H
#define LOGINDIALOG_H

#include <QDialog>
#include <QMouseEvent>

#include "moreform.h"

namespace Ui {
class LoginDialog;
}

class LoginDialog : public QDialog
{
    Q_OBJECT

public:
    explicit LoginDialog(QWidget *parent = 0);
    ~LoginDialog();

protected:

    QPoint oldPos;

    bool press;

    void mousePressEvent(QMouseEvent *event);

    void mouseMoveEvent(QMouseEvent *event);

    void mouseReleaseEvent(QMouseEvent *event);

private slots:
    void on_closePButtonL_clicked();

    void on_loginPButtonL_clicked();

    void on_statusPButtonL_clicked();

    void on_morePButton_clicked();

    void on_pswLEditL_textEdited(const QString &arg1);

private:
    Ui::LoginDialog *ui;

    MoreForm *moreForm;

private:
    void keyPressEvent(QKeyEvent *event);

    //void paintEvent(QPaintEvent* p);
};

#endif // LOGINDIALOG_H
