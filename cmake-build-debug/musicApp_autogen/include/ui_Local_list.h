/********************************************************************************
** Form generated from reading UI file 'local_list.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOCAL_LIST_H
#define UI_LOCAL_LIST_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Local_list
{
public:
    QWidget *inner_widget;
    QVBoxLayout *list_layout;

    void setupUi(QScrollArea *Local_list)
    {
        if (Local_list->objectName().isEmpty())
            Local_list->setObjectName(QString::fromUtf8("Local_list"));
        inner_widget = new QWidget();
        inner_widget->setObjectName(QString::fromUtf8("inner_widget"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(inner_widget->sizePolicy().hasHeightForWidth());
        inner_widget->setSizePolicy(sizePolicy);
        list_layout = new QVBoxLayout(inner_widget);
        list_layout->setSpacing(0);
        list_layout->setObjectName(QString::fromUtf8("list_layout"));
        list_layout->setContentsMargins(0, 0, 0, 0);
        Local_list->setWidget(inner_widget);

        retranslateUi(Local_list);

        QMetaObject::connectSlotsByName(Local_list);
    } // setupUi

    void retranslateUi(QScrollArea *Local_list)
    {
        (void)Local_list;
    } // retranslateUi

};

namespace Ui {
    class Local_list: public Ui_Local_list {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOCAL_LIST_H
