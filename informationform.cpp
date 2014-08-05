#include "informationform.h"
#include "ui_informationform.h"

InformationForm::InformationForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::InformationForm)
{
    ui->setupUi(this);
}

InformationForm::~InformationForm()
{
    delete ui;
}
