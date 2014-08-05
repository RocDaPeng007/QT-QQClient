#ifndef QQSYSTEMTRAYDIALOG_H
#define QQSYSTEMTRAYDIALOG_H

#include <QDialog>
#include <QString>

namespace Ui {
class QQSystemTrayDialog;
}

class QQSystemTrayDialog : public QDialog
{
    Q_OBJECT

public:
    explicit QQSystemTrayDialog(QWidget *parent = 0);
    ~QQSystemTrayDialog();

private slots:
    void on_morePButton_tray_clicked();

private:
    Ui::QQSystemTrayDialog *ui;

private:
    QPixmap* ninePatch(QString picName,int titleHeight,int BorderLineWidth ,QWidget* Wnd);
    void optionViews();
    void paintEvent(QPaintEvent*);
};

#endif // QQSYSTEMTRAYDIALOG_H
