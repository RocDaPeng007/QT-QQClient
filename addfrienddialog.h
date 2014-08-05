#ifndef ADDFRIENDDIALOG_H
#define ADDFRIENDDIALOG_H

#include <QDialog>

namespace Ui {
class AddFriendDialog;
}

class AddFriendDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AddFriendDialog(QWidget *parent = 0);
    ~AddFriendDialog();

signals:
    void onaddFriendBtnclicked(QString text, int index);

private slots:
    void on_addPButton_clicked();

    void on_childQQLEdit_cursorPositionChanged(int arg1, int arg2);

    void on_groupNumLEdit_cursorPositionChanged(int arg1, int arg2);

    void on_tabWidget_currentChanged(int index);

private:
    Ui::AddFriendDialog *ui;
};

#endif // ADDFRIENDDIALOG_H
