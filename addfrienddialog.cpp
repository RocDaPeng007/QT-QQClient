#include "addfrienddialog.h"
#include "ui_addfrienddialog.h"

AddFriendDialog::AddFriendDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddFriendDialog)
{
    ui->setupUi(this);
}

AddFriendDialog::~AddFriendDialog()
{
    delete ui;
}

void AddFriendDialog::on_addPButton_clicked()
{
    int index = ui->tabWidget->currentIndex();
    emit onaddFriendBtnclicked(!index?ui->childQQLEdit->text():ui->groupNumLEdit->text(),
                                 index);
}

void AddFriendDialog::on_childQQLEdit_cursorPositionChanged(int arg1, int arg2)
{
    if (ui->tabWidget->currentIndex() == 0)
    {
        ui->addPButton->setEnabled(!!ui->childQQLEdit->text().length());
    }
}

void AddFriendDialog::on_groupNumLEdit_cursorPositionChanged(int arg1, int arg2)
{
    if (ui->tabWidget->currentIndex() == 1)
    {
        ui->addPButton->setEnabled(!!ui->groupNumLEdit->text().length());
    }
}

void AddFriendDialog::on_tabWidget_currentChanged(int index)
{
    if (ui->tabWidget->currentIndex() == 0)
    {
        ui->addPButton->setEnabled(!!ui->childQQLEdit->text().length());
    }
    else if (ui->tabWidget->currentIndex() == 1)
    {
        ui->addPButton->setEnabled(!!ui->groupNumLEdit->text().length());
    }
}
