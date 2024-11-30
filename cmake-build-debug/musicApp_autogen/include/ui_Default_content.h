/********************************************************************************
** Form generated from reading UI file 'default_content.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DEFAULT_CONTENT_H
#define UI_DEFAULT_CONTENT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Default_content
{
public:
    QGridLayout *gridLayout;
    QSpacerItem *horizontalSpacer;
    QSpacerItem *verticalSpacer_2;
    QPushButton *btn;
    QLabel *label;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *verticalSpacer;
    QLabel *icon;
    QSpacerItem *verticalSpacer_3;

    void setupUi(QWidget *Default_content)
    {
        if (Default_content->objectName().isEmpty())
            Default_content->setObjectName(QString::fromUtf8("Default_content"));
        Default_content->resize(400, 300);
        gridLayout = new QGridLayout(Default_content);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 2, 0, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer_2, 0, 1, 1, 1);

        btn = new QPushButton(Default_content);
        btn->setObjectName(QString::fromUtf8("btn"));

        gridLayout->addWidget(btn, 2, 1, 1, 1);

        label = new QLabel(Default_content);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 4, 1, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 2, 2, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 5, 1, 1, 1);

        icon = new QLabel(Default_content);
        icon->setObjectName(QString::fromUtf8("icon"));

        gridLayout->addWidget(icon, 1, 1, 1, 1);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer_3, 3, 1, 1, 1);


        retranslateUi(Default_content);

        QMetaObject::connectSlotsByName(Default_content);
    } // setupUi

    void retranslateUi(QWidget *Default_content)
    {
        btn->setText(QCoreApplication::translate("Default_content", "\351\200\211\346\213\251", nullptr));
        label->setText(QCoreApplication::translate("Default_content", "\346\213\226\346\213\275\346\210\226\351\200\211\346\213\251\346\226\207\344\273\266\345\244\271", nullptr));
        icon->setText(QString());
        (void)Default_content;
    } // retranslateUi

};

namespace Ui {
    class Default_content: public Ui_Default_content {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DEFAULT_CONTENT_H
