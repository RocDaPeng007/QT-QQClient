#ifndef INFORMATIONFORM_H
#define INFORMATIONFORM_H

#include <QWidget>

namespace Ui {
class InformationForm;
}

class InformationForm : public QWidget
{
    Q_OBJECT

public:
    explicit InformationForm(QWidget *parent = 0);
    ~InformationForm();

private:
    Ui::InformationForm *ui;
};

#endif // INFORMATIONFORM_H
