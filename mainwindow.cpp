#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QDebug>

#include "addfrienddialog.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    setHidden(true);

    LoginDialog *login = new LoginDialog;
    login->show();

    //有这个才能把QLineEdit的边框搞没
    this->setStyleSheet("border-radius:10px;");

    //设置菜单
    //设置组菜单
    QMenu *groupMenu = new QMenu(this);
    groupMenu->addAction(tr("小图标"));
    groupMenu->addAction(tr("添加组"));
    groupMenu->addAction(tr("重命名该组"));
    groupMenu->addAction(tr("删除该组"));
    groupMenu->addSeparator();
    groupMenu->addAction(tr("仅显示在线联系人"));
    connect(groupMenu, SIGNAL(triggered(QAction*)), this, SLOT(onGroupPopMenuDidSelected(QAction*)));
    ui->friendLWidget->setGroupPopMenu(groupMenu);
    connect(ui->friendLWidget, SIGNAL(on_popmenu_will_show(QQListWidget*,QQPopMenuWidget*,QMenu*)), this,
            SLOT(on_popmenuWillShow(QQListWidget*,QQPopMenuWidget*,QMenu*)));

    //设置子菜单
    QMenu *childMenu = new QMenu(this);
    childMenu->addAction(tr("发送即时消息"));
    childMenu->addAction(tr("发送邮件"));

    QMenu *avMenu = new QMenu("影音交谈");
    avMenu->addAction(tr("开始视频会话"));
    avMenu->addAction(tr("开始音频会话"));
    childMenu->addMenu(avMenu);

    childMenu->addSeparator();

    childMenu->addAction("隐身对其可见");
    groupListMenu = new QMenu(tr("移动联系人至"));
    childMenu->addMenu(groupListMenu);

    childMenu->addAction("移动至黑名单");
    childMenu->addAction("删除联系人");
    childMenu->addSeparator();
    childMenu->addAction("修改备注姓名");
    childMenu->addAction("访问好友QQ空间");
    childMenu->addAction("查看消息记录");
    childMenu->addAction("查看资料");

    //childMenu->addAction(tr("创建讨论组"));
    connect(childMenu, SIGNAL(triggered(QAction*)), this, SLOT(onChildPopMenuDidSelected(QAction*)));
    ui->friendLWidget->setChildPopMenu(childMenu);

    //添加默认项
    //好友列表
    QQCell *myFriend = new QQCell;
    myFriend->groupName = QString(tr("我的好友"));
    myFriend->isOpen = false;
    myFriend->type = QQCellType_Group;
    myFriend->title = QString(tr("我的好友"));
    myFriend->subTitle = QString("(0/0)");
    ui->friendLWidget->insertQQCell(myFriend);
    QQCell *stranger = new QQCell;
    stranger->groupName = QString(tr("陌生人"));
    stranger->isOpen = false;
    stranger->type = QQCellType_Group;
    stranger->title = QString(tr("陌生人"));
    stranger->subTitle = QString("(0/0)");
    ui->friendLWidget->insertQQCell(stranger);
    QQCell *blacklist = new QQCell;
    blacklist->groupName = QString(tr("黑名单"));
    blacklist->isOpen = false;
    blacklist->type = QQCellType_Group;
    blacklist->title = QString(tr("黑名单"));
    blacklist->subTitle = QString("(0/0)");
    ui->friendLWidget->insertQQCell(blacklist);
    //组列表
    QQCell *discussionGroup = new QQCell;
    discussionGroup->groupName = QString(tr("讨论组"));
    discussionGroup->isOpen = false;
    discussionGroup->type = QQCellType_GroupEx;
    discussionGroup->title = QString(tr("讨论组(0/0)"));
    discussionGroup->subTitle = QString("");
    ui->groupLWidget->insertQQCell(discussionGroup);
    QQCell *group = new QQCell;
    group->groupName = QString(tr("群"));
    group->isOpen = false;
    group->type = QQCellType_GroupEx;
    group->title = QString(tr("群(0/0)"));
    group->subTitle = QString("");
    ui->groupLWidget->insertQQCell(group);

    //显示托盘
    QIcon icon = QIcon(":/icon/images/icon/remind_QQlogo_normal.png");
    trayIcon = new QSystemTrayIcon(this);
    trayIcon->setIcon(icon);
    trayIcon->setToolTip(tr("子曰USay"));
    trayIcon->show();

    connect(trayIcon, SIGNAL(activated(QSystemTrayIcon::ActivationReason)), this,
            SLOT(ontrayIconclicked(QSystemTrayIcon::ActivationReason)));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_iconSelfPButton_clicked()
{

}

void MainWindow::on_statusButton_clicked()
{
    QMenu *menu = new QMenu(this);
    menu->addAction(QIcon(":/images/images/background/Header+Search_Online_Normal.png"),
                    tr("在线"));
    menu->addAction(QIcon(":/images/images/background/Header+Search_Busy_Normal.png"),
                    tr("忙碌"));
    menu->addAction(QIcon(":/images/images/background/Header+Search_Hide_Normal.png"),
                    tr("隐身"));
    menu->addAction(QIcon(":/images/images/background/Header+Search_Offline_Normal.png"),
                    tr("离线"));
    connect(menu, SIGNAL(triggered(QAction*)), this, SLOT(onStatusPopMenuDidSelected(QAction*)));

    QPoint pos(ui->statusButton->geometry().x(), ui->statusButton->geometry().y());
    int x = pos.x();
    int y = pos.y();

    pos.setX(x);
    pos.setY(y+this->geometry().height()-140);

    //返回菜单下面的action不管有没被选中，可以算一个小事件循环
    //里面参数的意思是在哪个坐标弹出菜单，这里将自定义的pop按键的坐标作参考，并在其下面弹出菜单
    menu->exec(this->mapToGlobal(pos));
}

void MainWindow::onStatusPopMenuDidSelected(QAction *action)
{
    qDebug()<<"onStatusPopMenuDidSelected: " << action->text();
}

void MainWindow::on_optionPButton_clicked()
{
}

void MainWindow::on_addFriendPButton_clicked()
{
    QMenu *menu = new QMenu(this);
    menu->addAction(tr("添加联系人/群"));
    menu->addAction(tr("创建群"));
    menu->addAction(tr("创建讨论组"));
    connect(menu, SIGNAL(triggered(QAction*)), this, SLOT(onAddFriendMenuDidSelected(QAction*)));

    QPoint pos(ui->addFriendPButton->geometry().x(), ui->addFriendPButton->geometry().y());
    int x = pos.x();
    int y = pos.y();

    pos.setX(x);
    pos.setY(this->geometry().height()-y);

    menu->exec(this->mapToParent(pos));
}

void MainWindow::onAddFriendMenuDidSelected(QAction *action)
{
    qDebug()<<"onAddFriendMenuDidSelected";
    if (!action->text().compare(tr("添加联系人/群")))
    {
        addFriendDialog = new AddFriendDialog;
        addFriendDialog->show();
        connect(addFriendDialog, SIGNAL(onaddFriendBtnclicked(QString, int)), this,
                SLOT(on_addFriendBtnClicked(QString, int)));
    }
}

void MainWindow::onGroupPopMenuDidSelected(QAction *action)
{
    if (!action->text().compare(tr("添加组")))
    {
        addGroupDialog = new AddGroupDialog;
        addGroupDialog->show();
        connect(addGroupDialog, SIGNAL(on_addGroupLButtonDidClicked(QString)), this,
                SLOT(onaddGroupLButtonclicked(QString)));
    }
}

void MainWindow::onChildPopMenuDidSelected(QAction *action)
{

}

void MainWindow::onaddGroupLButtonclicked(QString text)
{
    addGroupDialog->close();

    QQCell *cell = new QQCell;
    cell->groupName = text;
    cell->type = QQCellType_Group;

    ui->friendLWidget->insertQQCell(cell);
}

void MainWindow::on_addFriendBtnClicked(QString text, int index)
{
    addFriendDialog->close();

    if (!index)
    {
        //
        QQCell *cell = new QQCell;
        cell->groupName = QString(tr("我的好友"));
        cell->type = QQCellType_Child;
        cell->title = text;
        cell->subTitle = QString("");

        ui->friendLWidget->insertQQCell(cell);
    }
    else if (index)
    {
        QQCell *cell = new QQCell;
        cell->groupName = QString(tr("群"));
        cell->type = QQCellType_Child;
        cell->title = text;
        cell->subTitle = QString("");
        ui->groupLWidget->insertQQCell(cell);
    }
}

void MainWindow::on_popmenuWillShow(QQListWidget *listWidget,
                                    QQPopMenuWidget *widget,
                                    QMenu *menu)
{
    //
}

void MainWindow::ontrayIconclicked(QSystemTrayIcon::ActivationReason reason)
{
    //trayIcon->
//    qDebug()<<"on_trayIcon_clicked";
    if (!systemTrayDialog)
    {
        systemTrayDialog = new QQSystemTrayDialog;
        systemTrayDialog->setGeometry(QRect(QCursor::pos().x()-systemTrayDialog->geometry().size().width()/2.0,
                                            25,
                                            systemTrayDialog->geometry().size().width(),
                                            systemTrayDialog->geometry().size().height()));
        systemTrayDialog->show();
    }
    else
    {
        systemTrayDialog->close();
        systemTrayDialog = NULL;
    }
}

