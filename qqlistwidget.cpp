#include "qqlistwidget.h"

#include <QDebug>

QQListWidget::QQListWidget(QWidget *parent) :
    QListWidget(parent)
{
}

void QQListWidget::setGroupPopMenu(QMenu *menu)
{
    mGroupMenu = menu;
}

void QQListWidget::setChildPopMenu(QMenu *menu)
{
    mChildMenu = menu;
}

void QQListWidget::insertQQCell(QQCell * cell)
{
    if (cell->type == QQCellType_Group ||
            cell->type == QQCellType_GroupEx)
    {
        cells.append(cell);
    }
    else
    {
        for (QQCell *group : cells)
        {
            if (!group->groupName.compare(cell->groupName))
            {
                group->childs.append(cell);

                break;
            }
        }
    }

    upload();
}

void QQListWidget::removeQQCell(QQCell * cell)
{
    if (cell->type == QQCellType_Group ||
            cell->type == QQCellType_GroupEx)
    {
        cells.removeOne(cell);
    }
    else
    {
        for (QQCell *group : cells)
        {
            if (!group->groupName.compare(cell->groupName))
            {
                group->childs.removeOne(cell);

                break;
            }
        }
    }

    upload();
}

void QQListWidget::upload()
{
    this->clear();
    int index = 0;

    for (QQCell * cell:cells)
    {
        if (cell->type == QQCellType_Group ||
                cell->type == QQCellType_GroupEx )
        {
            QQListViewGroup *group = new QQListViewGroup;
            group->setGeometry(0,0, 270, 25);
            if (cell->type == QQCellType_Group)
            {
                group->ui->groupTitleLabel->setText(cell->groupName);
                group->ui->groupSubTitleLabel->setText(QString("(%1/%1)").arg(cell->childs.size()));
            }
            else
            {
                group->ui->groupTitleLabel->setText(QString("%1(%2/%2)").arg(cell->groupName).arg(cell->childs.size()));
                group->ui->groupSubTitleLabel->setText(QString(""));
            }
            group->setQQCell(cell);
            group->setPopMenu(mGroupMenu);
            connect(group,
                    SIGNAL(onGroupOpenStatusDidChanged(QQListViewGroup*)),
                    this,
                    SLOT(onGroupOpenDidChanged(QQListViewGroup *)));
            connect(group,
                    SIGNAL(onpopmenuwillshow(QQPopMenuWidget*,QMenu*)),
                    this,
                    SLOT(on_popmenuWillShow(QQPopMenuWidget*,QMenu*)));

            QListWidgetItem * item = new QListWidgetItem("");
            this->addItem(item);
            this->setItemWidget(item, group);
            item->setSizeHint(group->geometry().size());

            if (cell->isOpen)
            {
                for (QQCell * ccell:cell->childs)
                {
                    QQListViewChild *child = new QQListViewChild;
                    child->setGeometry(0,0, 270, 60);
                    child->ui->childTitleLabel->setText(ccell->title);
                    child->ui->childSubTitleLabel->setText(ccell->subTitle);
                    child->cell = ccell;
                    child->setPopMenu(mChildMenu);
                    connect(child, SIGNAL(onChildDidSelected(QQListViewChild*)), this,
                            SLOT(onChildDidSelected(QQListViewChild*)));
                    connect(child, SIGNAL(onChildDidDoubleClicked(QQListViewChild*)), this,
                            SLOT(onChildDidDoubleClicked(QQListViewChild*)));
                    connect(child,
                            SIGNAL(onpopmenuwillshow(QQPopMenuWidget*,QMenu*)),
                            this,
                            SLOT(on_popmenuWillShow(QQPopMenuWidget*,QMenu*)));

                    QListWidgetItem * item = new QListWidgetItem("");
                    this->addItem(item);
                    this->setItemWidget(item, child);
                    item->setSizeHint(child->geometry().size());

                    index++;

                    setBackGroundColor(child, index);
                }
            }
        }
        else
        {
            QQListViewChild *child = new QQListViewChild;
            child->setGeometry(0,0, 270, 60);
            child->ui->childTitleLabel->setText(cell->title);
            child->ui->childSubTitleLabel->setText(cell->subTitle);
            child->cell = cell;
            child->setPopMenu(mChildMenu);
            connect(child, SIGNAL(onChildDidSelected(QQListViewChild*)), this,
                    SLOT(onChildDidSelected(QQListViewChild*)));
            connect(child, SIGNAL(onChildDidDoubleClicked(QQListViewChild*)), this,
                    SLOT(onChildDidDoubleClicked(QQListViewChild*)));
            connect(child,
                    SIGNAL(on_popmenu_willshow(QQPopMenuWidget*,QMenu*)),
                    this,
                    SLOT(on_popmenuWillShow(QQPopMenuWidget*,QMenu*)));

            QListWidgetItem * item = new QListWidgetItem("");
            this->addItem(item);
            this->setItemWidget(item, child);
            item->setSizeHint(child->geometry().size());

            index++;

            setBackGroundColor(child, index);
        }
    }
}

void QQListWidget::onGroupOpenDidChanged(QQListViewGroup *group)
{
    upload();
}

void QQListWidget::onChildDidSelected(QQListViewChild *child)
{

}

void QQListWidget::onChildDidDoubleClicked(QQListViewChild *child)
{

}

void QQListWidget::setBackGroundColor(QWidget *widget,int index)
{
    widget->setStyleSheet(index%2?"QWidget{background:rgb(100, 100, 100, 100)}":
                                  "QWidget{background:rgb(255, 255, 255)}");
}

QQCell *QQListWidget::getGroupForName(QString *groupName)
{
    for (QQCell *group : cells)
    {
        if (!group->groupName.compare(groupName))
        {
            return group;
        }
    }

    return NULL;
}

void QQListWidget::on_popmenuWillShow(QQPopMenuWidget *widget, QMenu *menu)
{
    emit on_popmenu_will_show(this, widget, menu);;
}
