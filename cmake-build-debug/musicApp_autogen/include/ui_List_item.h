/********************************************************************************
** Form generated from reading UI file 'list_item.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LIST_ITEM_H
#define UI_LIST_ITEM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_List_item
{
public:
    QHBoxLayout *verticalLayout;
    QLabel *num;
    QSpacerItem *verticalSpacer;
    QVBoxLayout *verticalLayout_2;
    QLabel *title;
    QLabel *author;
    QSpacerItem *verticalSpacer_3;
    QLabel *favo;

    void setupUi(QWidget *List_item)
    {
        if (List_item->objectName().isEmpty())
            List_item->setObjectName(QString::fromUtf8("List_item"));
        List_item->resize(400, 60);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(List_item->sizePolicy().hasHeightForWidth());
        List_item->setSizePolicy(sizePolicy);
        verticalLayout = new QHBoxLayout(List_item);
        verticalLayout->setSpacing(20);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(40, 5, 20, 5);
        num = new QLabel(List_item);
        num->setObjectName(QString::fromUtf8("num"));

        verticalLayout->addWidget(num);

        verticalSpacer = new QSpacerItem(40, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(1);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        title = new QLabel(List_item);
        title->setObjectName(QString::fromUtf8("title"));

        verticalLayout_2->addWidget(title);

        author = new QLabel(List_item);
        author->setObjectName(QString::fromUtf8("author"));

        verticalLayout_2->addWidget(author);


        verticalLayout->addLayout(verticalLayout_2);

        verticalSpacer_3 = new QSpacerItem(80, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_3);

        favo = new QLabel(List_item);
        favo->setObjectName(QString::fromUtf8("favo"));

        verticalLayout->addWidget(favo);


        retranslateUi(List_item);

        QMetaObject::connectSlotsByName(List_item);
    } // setupUi

    void retranslateUi(QWidget *List_item)
    {
        title->setText(QString());
        author->setText(QString());
        (void)List_item;
    } // retranslateUi

};

namespace Ui {
    class List_item: public Ui_List_item {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LIST_ITEM_H
