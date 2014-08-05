#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMenu>
#include <QSystemTrayIcon>

#include "logindialog.h"
#include "addfrienddialog.h"
#include "addgroupdialog.h"
#include "qqlistwidget.h"
#include "qqpopmenuwidget.h"
#include "qqsystemtraydialog.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:

    void on_iconSelfPButton_clicked();

    void on_statusButton_clicked();

    void on_optionPButton_clicked();

    void on_addFriendPButton_clicked();


    void onAddFriendMenuDidSelected(QAction *action);
    void onStatusPopMenuDidSelected(QAction *action);
    void onGroupPopMenuDidSelected(QAction *action);
    void onChildPopMenuDidSelected(QAction *action);

    void on_addFriendBtnClicked(QString text, int index);
    void onaddGroupLButtonclicked(QString text);
    void on_popmenuWillShow(QQListWidget *listWidget,QQPopMenuWidget *widget, QMenu *menu);
    void ontrayIconclicked(QSystemTrayIcon::ActivationReason reason);

private:
    Ui::MainWindow *ui;

    AddFriendDialog *addFriendDialog;
    AddGroupDialog *addGroupDialog;

    QMenu *groupListMenu;

    //
    QSystemTrayIcon *trayIcon;
    QQSystemTrayDialog *systemTrayDialog;
};

#endif // MAINWINDOW_H
