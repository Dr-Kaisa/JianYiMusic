/********************************************************************************
** Form generated from reading UI file 'top_bar.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TOP_BAR_H
#define UI_TOP_BAR_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Top_bar
{
public:
    QHBoxLayout *horizontalLayout;
    QLineEdit *input;
    QPushButton *go_search;
    QSpacerItem *verticalSpacer_7;
    QLabel *avatar;
    QLabel *name;
    QSpacerItem *verticalSpacer_5;

    void setupUi(QWidget *Top_bar)
    {
        if (Top_bar->objectName().isEmpty())
            Top_bar->setObjectName(QString::fromUtf8("Top_bar"));
        Top_bar->resize(688, 101);
        horizontalLayout = new QHBoxLayout(Top_bar);
        horizontalLayout->setSpacing(10);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 10, 10, 10);
        input = new QLineEdit(Top_bar);
        input->setObjectName(QString::fromUtf8("input"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(input->sizePolicy().hasHeightForWidth());
        input->setSizePolicy(sizePolicy);
        input->setStyleSheet(QString::fromUtf8(""));

        horizontalLayout->addWidget(input);

        go_search = new QPushButton(Top_bar);
        go_search->setObjectName(QString::fromUtf8("go_search"));
        sizePolicy.setHeightForWidth(go_search->sizePolicy().hasHeightForWidth());
        go_search->setSizePolicy(sizePolicy);

        horizontalLayout->addWidget(go_search);

        verticalSpacer_7 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        horizontalLayout->addItem(verticalSpacer_7);

        avatar = new QLabel(Top_bar);
        avatar->setObjectName(QString::fromUtf8("avatar"));

        horizontalLayout->addWidget(avatar);

        name = new QLabel(Top_bar);
        name->setObjectName(QString::fromUtf8("name"));
        sizePolicy.setHeightForWidth(name->sizePolicy().hasHeightForWidth());
        name->setSizePolicy(sizePolicy);
        name->setAlignment(Qt::AlignBottom|Qt::AlignLeading|Qt::AlignLeft);

        horizontalLayout->addWidget(name);

        verticalSpacer_5 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        horizontalLayout->addItem(verticalSpacer_5);

        horizontalLayout->setStretch(0, 3);
        horizontalLayout->setStretch(1, 1);
        horizontalLayout->setStretch(2, 1);
        horizontalLayout->setStretch(3, 1);
        horizontalLayout->setStretch(4, 1);
        horizontalLayout->setStretch(5, 1);

        retranslateUi(Top_bar);

        QMetaObject::connectSlotsByName(Top_bar);
    } // setupUi

    void retranslateUi(QWidget *Top_bar)
    {
        go_search->setText(QCoreApplication::translate("Top_bar", "\346\220\234\347\264\242", nullptr));
        name->setText(QCoreApplication::translate("Top_bar", "\346\234\252\347\237\245", nullptr));
        (void)Top_bar;
    } // retranslateUi

};

namespace Ui {
    class Top_bar: public Ui_Top_bar {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TOP_BAR_H
