#ifndef MOREFORM_H
#define MOREFORM_H

#include <QWidget>
#include <QPaintEvent>
#include <QPainter>

namespace Ui {
class MoreForm;
}

class MoreForm : public QWidget
{
    Q_OBJECT

public:
    explicit MoreForm(QWidget *parent = 0);
    ~MoreForm();

    void paintEvent(QPaintEvent* p);

private slots:
    void on_forgetPButton_clicked();

    void on_rememberCBox_stateChanged(int arg1);

    void on_autoLoginCBox_stateChanged(int arg1);

    void on_registerPButton_clicked();


private:
    Ui::MoreForm *ui;

    QPainter *painter;
};

#endif // MOREFORM_H
