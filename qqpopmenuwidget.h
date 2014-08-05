#ifndef QQPOPMENUWIDGET_H
#define QQPOPMENUWIDGET_H

#include <QWidget>
#include <QMenu>
#include <QMouseEvent>

class QQPopMenuWidget : public QWidget
{
    Q_OBJECT
public:
    explicit QQPopMenuWidget(QWidget *parent = 0);

signals:
    void onpopmenuwillshow(QQPopMenuWidget * widget, QMenu *menu);

public slots:

public:
    void setPopMenu(QMenu *menu);

protected slots:

protected:
    QMenu *popMenu;

public:
    virtual void mousePressEvent(QMouseEvent *event);
};

#endif // QQPOPMENUWIDGET_H
