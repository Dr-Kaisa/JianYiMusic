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
    QLabel *favo;
    QLabel *last;
    QLabel *pause;
    QLabel *next;
    QLabel *circle;
    QSpacerItem *spacer2;

    void setupUi(QWidget *Bottom_bar)
    {
        if (Bottom_bar->objectName().isEmpty())
            Bottom_bar->setObjectName(QString::fromUtf8("Bottom_bar"));
        horizontalLayout = new QHBoxLayout(Bottom_bar);
        horizontalLayout->setSpacing(80);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(-1, 20, -1, -1);
        spacer1 = new QSpacerItem(40, 200, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(spacer1);

        favo = new QLabel(Bottom_bar);
        favo->setObjectName(QString::fromUtf8("favo"));

        horizontalLayout->addWidget(favo);

        last = new QLabel(Bottom_bar);
        last->setObjectName(QString::fromUtf8("last"));

        horizontalLayout->addWidget(last);

        pause = new QLabel(Bottom_bar);
        pause->setObjectName(QString::fromUtf8("pause"));

        horizontalLayout->addWidget(pause);

        next = new QLabel(Bottom_bar);
        next->setObjectName(QString::fromUtf8("next"));

        horizontalLayout->addWidget(next);

        circle = new QLabel(Bottom_bar);
        circle->setObjectName(QString::fromUtf8("circle"));

        horizontalLayout->addWidget(circle);

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
