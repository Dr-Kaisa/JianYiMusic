/********************************************************************************
** Form generated from reading UI file 'side_bar.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SIDE_BAR_H
#define UI_SIDE_BAR_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Side_bar
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *logo;
    QLabel *title;
    QPushButton *myFavo;
    QPushButton *local;
    QSpacerItem *verticalSpacer;
    QSpacerItem *verticalSpacer_2;
    QSpacerItem *verticalSpacer_3;
    QSpacerItem *verticalSpacer_4;

    void setupUi(QWidget *Side_bar)
    {
        if (Side_bar->objectName().isEmpty())
            Side_bar->setObjectName(QString::fromUtf8("Side_bar"));
        Side_bar->resize(456, 451);
        verticalLayout = new QVBoxLayout(Side_bar);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(12);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        logo = new QLabel(Side_bar);
        logo->setObjectName(QString::fromUtf8("logo"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(logo->sizePolicy().hasHeightForWidth());
        logo->setSizePolicy(sizePolicy);
        logo->setMinimumSize(QSize(100, 70));

        horizontalLayout->addWidget(logo);

        title = new QLabel(Side_bar);
        title->setObjectName(QString::fromUtf8("title"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(title->sizePolicy().hasHeightForWidth());
        title->setSizePolicy(sizePolicy1);
        title->setStyleSheet(QString::fromUtf8(""));
        title->setIndent(40);

        horizontalLayout->addWidget(title);


        verticalLayout->addLayout(horizontalLayout);

        myFavo = new QPushButton(Side_bar);
        myFavo->setObjectName(QString::fromUtf8("myFavo"));
        sizePolicy.setHeightForWidth(myFavo->sizePolicy().hasHeightForWidth());
        myFavo->setSizePolicy(sizePolicy);
        myFavo->setMinimumSize(QSize(100, 0));

        verticalLayout->addWidget(myFavo);

        local = new QPushButton(Side_bar);
        local->setObjectName(QString::fromUtf8("local"));
        sizePolicy.setHeightForWidth(local->sizePolicy().hasHeightForWidth());
        local->setSizePolicy(sizePolicy);
        local->setMinimumSize(QSize(100, 0));

        verticalLayout->addWidget(local);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_2);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_3);

        verticalSpacer_4 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_4);


        retranslateUi(Side_bar);

        QMetaObject::connectSlotsByName(Side_bar);
    } // setupUi

    void retranslateUi(QWidget *Side_bar)
    {
        title->setText(QCoreApplication::translate("Side_bar", "\347\256\200\346\230\223\344\272\221\351\237\263\344\271\220", nullptr));
        myFavo->setText(QCoreApplication::translate("Side_bar", "\346\210\221\347\232\204\346\224\266\350\227\217", nullptr));
        local->setText(QCoreApplication::translate("Side_bar", "\346\234\254\345\234\260\351\237\263\344\271\220", nullptr));
        (void)Side_bar;
    } // retranslateUi

};

namespace Ui {
    class Side_bar: public Ui_Side_bar {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SIDE_BAR_H
