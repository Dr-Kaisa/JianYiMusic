/********************************************************************************
** Form generated from reading UI file 'myfavo_list.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MYFAVO_LIST_H
#define UI_MYFAVO_LIST_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Myfavo_list
{
public:
    QVBoxLayout *list_layout;

    void setupUi(QWidget *Myfavo_list)
    {
        if (Myfavo_list->objectName().isEmpty())
            Myfavo_list->setObjectName(QString::fromUtf8("Myfavo_list"));
        Myfavo_list->resize(1200, 300);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Myfavo_list->sizePolicy().hasHeightForWidth());
        Myfavo_list->setSizePolicy(sizePolicy);
        list_layout = new QVBoxLayout(Myfavo_list);
        list_layout->setSpacing(0);
        list_layout->setObjectName(QString::fromUtf8("list_layout"));
        list_layout->setContentsMargins(0, 0, 0, 0);

        retranslateUi(Myfavo_list);

        QMetaObject::connectSlotsByName(Myfavo_list);
    } // setupUi

    void retranslateUi(QWidget *Myfavo_list)
    {
        (void)Myfavo_list;
    } // retranslateUi

};

namespace Ui {
    class Myfavo_list: public Ui_Myfavo_list {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MYFAVO_LIST_H
