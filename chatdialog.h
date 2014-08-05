#ifndef CHATDIALOG_H
#define CHATDIALOG_H

#include <QDialog>
#include <QMouseEvent>
#include <QLineEdit>

namespace Ui {
class ChatDialog;
}

class ChatDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ChatDialog(QWidget *parent = 0);
    ~ChatDialog();

protected:

    QPoint oldPos;

    QLineEdit * line;

    bool press;

    void mousePressEvent(QMouseEvent *event);

    void mouseMoveEvent(QMouseEvent *event);

    void mouseReleaseEvent(QMouseEvent *event);

private:
    Ui::ChatDialog *ui;
};

#endif // CHATDIALOG_H
