#include "addgroupdialog.h"
#include "ui_addgroupdialog.h"

AddGroupDialog::AddGroupDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddGroupDialog)
{
    ui->setupUi(this);
}

AddGroupDialog::~AddGroupDialog()
{
    delete ui;
}

void AddGroupDialog::on_addGroupLButton_clicked()
{
    emit on_addGroupLButtonDidClicked(ui->addGroupNameLEdit->text());
}

void AddGroupDialog::on_addGroupNameLEdit_cursorPositionChanged(int arg1, int arg2)
{
    ui->addGroupLButton->setEnabled(!!ui->addGroupNameLEdit->text().length());
}
