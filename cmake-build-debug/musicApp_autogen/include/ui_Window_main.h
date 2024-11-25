/********************************************************************************
** Form generated from reading UI file 'window_main.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WINDOW_MAIN_H
#define UI_WINDOW_MAIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Window_main
{
public:
    QWidget *page1;

    void setupUi(QStackedWidget *Window_main)
    {
        if (Window_main->objectName().isEmpty())
            Window_main->setObjectName(QString::fromUtf8("Window_main"));
        Window_main->resize(659, 579);
        page1 = new QWidget();
        page1->setObjectName(QString::fromUtf8("page1"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(page1->sizePolicy().hasHeightForWidth());
        page1->setSizePolicy(sizePolicy);
        Window_main->addWidget(page1);

        retranslateUi(Window_main);

        QMetaObject::connectSlotsByName(Window_main);
    } // setupUi

    void retranslateUi(QStackedWidget *Window_main)
    {
        page1->setWindowTitle(QCoreApplication::translate("Window_main", "GroupBox", nullptr));
        (void)Window_main;
    } // retranslateUi

};

namespace Ui {
    class Window_main: public Ui_Window_main {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WINDOW_MAIN_H
