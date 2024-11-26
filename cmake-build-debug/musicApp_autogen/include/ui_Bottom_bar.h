/********************************************************************************
** Form generated from reading UI file 'bottom_bar.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BOTTOM_BAR_H
#define UI_BOTTOM_BAR_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Bottom_bar
{
public:
    QHBoxLayout *horizontalLayout;
    QSpacerItem *spacer1;
    QLabel *btn_favo;
    QLabel *btn_last;
    QLabel *btn_pause;
    QLabel *btn_next;
    QLabel *btn_circle;
    QSpacerItem *spacer2;

    void setupUi(QWidget *Bottom_bar)
    {
        if (Bottom_bar->objectName().isEmpty())
            Bottom_bar->setObjectName(QString::fromUtf8("Bottom_bar"));
        Bottom_bar->resize(608, 229);
        horizontalLayout = new QHBoxLayout(Bottom_bar);
        horizontalLayout->setSpacing(80);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(-1, 20, -1, -1);
        spacer1 = new QSpacerItem(40, 200, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(spacer1);

        btn_favo = new QLabel(Bottom_bar);
        btn_favo->setObjectName(QString::fromUtf8("btn_favo"));

        horizontalLayout->addWidget(btn_favo);

        btn_last = new QLabel(Bottom_bar);
        btn_last->setObjectName(QString::fromUtf8("btn_last"));

        horizontalLayout->addWidget(btn_last);

        btn_pause = new QLabel(Bottom_bar);
        btn_pause->setObjectName(QString::fromUtf8("btn_pause"));

        horizontalLayout->addWidget(btn_pause);

        btn_next = new QLabel(Bottom_bar);
        btn_next->setObjectName(QString::fromUtf8("btn_next"));

        horizontalLayout->addWidget(btn_next);

        btn_circle = new QLabel(Bottom_bar);
        btn_circle->setObjectName(QString::fromUtf8("btn_circle"));

        horizontalLayout->addWidget(btn_circle);

        spacer2 = new QSpacerItem(40, 200, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(spacer2);


        retranslateUi(Bottom_bar);

        QMetaObject::connectSlotsByName(Bottom_bar);
    } // setupUi

    void retranslateUi(QWidget *Bottom_bar)
    {
        (void)Bottom_bar;
    } // retranslateUi

};

namespace Ui {
    class Bottom_bar: public Ui_Bottom_bar {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BOTTOM_BAR_H
