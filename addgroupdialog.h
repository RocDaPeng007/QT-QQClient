#ifndef ADDGROUPDIALOG_H
#define ADDGROUPDIALOG_H

#include <QDialog>

namespace Ui {
class AddGroupDialog;
}

class AddGroupDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AddGroupDialog(QWidget *parent = 0);
    ~AddGroupDialog();

signals:
    void on_addGroupLButtonDidClicked(QString text);

private slots:
    void on_addGroupLButton_clicked();

    void on_addGroupNameLEdit_cursorPositionChanged(int arg1, int arg2);

private:
    Ui::AddGroupDialog *ui;
};

#endif // ADDGROUPDIALOG_H
