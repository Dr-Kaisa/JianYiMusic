/********************************************************************************
** Form generated from reading UI file 'window_login.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WINDOW_LOGIN_H
#define UI_WINDOW_LOGIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Window_login
{
public:
    QGridLayout *main_layout;
    QHBoxLayout *h_layout1;
    QLabel *label;
    QLineEdit *txt_account;
    QHBoxLayout *h_layout2;
    QLabel *label_2;
    QLineEdit *txt_password;
    QHBoxLayout *h_layout3;
    QPushButton *btn_register;
    QPushButton *btn_login;
    QHBoxLayout *h_layout4;
    QPushButton *btn_loginByGuest;

    void setupUi(QWidget *Window_login)
    {
        if (Window_login->objectName().isEmpty())
            Window_login->setObjectName(QString::fromUtf8("Window_login"));
        Window_login->resize(800, 600);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Window_login->sizePolicy().hasHeightForWidth());
        Window_login->setSizePolicy(sizePolicy);
        main_layout = new QGridLayout(Window_login);
        main_layout->setObjectName(QString::fromUtf8("main_layout"));
        h_layout1 = new QHBoxLayout();
        h_layout1->setSpacing(40);
        h_layout1->setObjectName(QString::fromUtf8("h_layout1"));
        h_layout1->setContentsMargins(40, 40, 40, 40);
        label = new QLabel(Window_login);
        label->setObjectName(QString::fromUtf8("label"));

        h_layout1->addWidget(label);

        txt_account = new QLineEdit(Window_login);
        txt_account->setObjectName(QString::fromUtf8("txt_account"));
        txt_account->setEnabled(true);
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(txt_account->sizePolicy().hasHeightForWidth());
        txt_account->setSizePolicy(sizePolicy1);

        h_layout1->addWidget(txt_account);


        main_layout->addLayout(h_layout1, 0, 0, 1, 2);

        h_layout2 = new QHBoxLayout();
        h_layout2->setSpacing(40);
        h_layout2->setObjectName(QString::fromUtf8("h_layout2"));
        h_layout2->setContentsMargins(40, 40, 40, 40);
        label_2 = new QLabel(Window_login);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        h_layout2->addWidget(label_2);

        txt_password = new QLineEdit(Window_login);
        txt_password->setObjectName(QString::fromUtf8("txt_password"));
        sizePolicy1.setHeightForWidth(txt_password->sizePolicy().hasHeightForWidth());
        txt_password->setSizePolicy(sizePolicy1);

        h_layout2->addWidget(txt_password);


        main_layout->addLayout(h_layout2, 1, 0, 1, 2);

        h_layout3 = new QHBoxLayout();
        h_layout3->setSpacing(40);
        h_layout3->setObjectName(QString::fromUtf8("h_layout3"));
        h_layout3->setContentsMargins(40, 40, 40, 40);
        btn_register = new QPushButton(Window_login);
        btn_register->setObjectName(QString::fromUtf8("btn_register"));
        QSizePolicy sizePolicy2(QSizePolicy::Minimum, QSizePolicy::Expanding);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(btn_register->sizePolicy().hasHeightForWidth());
        btn_register->setSizePolicy(sizePolicy2);

        h_layout3->addWidget(btn_register);

        btn_login = new QPushButton(Window_login);
        btn_login->setObjectName(QString::fromUtf8("btn_login"));
        sizePolicy2.setHeightForWidth(btn_login->sizePolicy().hasHeightForWidth());
        btn_login->setSizePolicy(sizePolicy2);

        h_layout3->addWidget(btn_login);


        main_layout->addLayout(h_layout3, 2, 0, 1, 2);

        h_layout4 = new QHBoxLayout();
        h_layout4->setSpacing(40);
        h_layout4->setObjectName(QString::fromUtf8("h_layout4"));
        h_layout4->setContentsMargins(40, 40, 40, 40);
        btn_loginByGuest = new QPushButton(Window_login);
        btn_loginByGuest->setObjectName(QString::fromUtf8("btn_loginByGuest"));
        sizePolicy1.setHeightForWidth(btn_loginByGuest->sizePolicy().hasHeightForWidth());
        btn_loginByGuest->setSizePolicy(sizePolicy1);

        h_layout4->addWidget(btn_loginByGuest);


        main_layout->addLayout(h_layout4, 3, 1, 1, 1);


        retranslateUi(Window_login);

        QMetaObject::connectSlotsByName(Window_login);
    } // setupUi

    void retranslateUi(QWidget *Window_login)
    {
        Window_login->setWindowTitle(QCoreApplication::translate("Window_login", "Window_login", nullptr));
        label->setText(QCoreApplication::translate("Window_login", "\350\264\246\345\217\267", nullptr));
        label_2->setText(QCoreApplication::translate("Window_login", "\345\257\206\347\240\201", nullptr));
        btn_register->setText(QCoreApplication::translate("Window_login", "\346\263\250\345\206\214", nullptr));
        btn_login->setText(QCoreApplication::translate("Window_login", "\347\231\273\345\275\225", nullptr));
        btn_loginByGuest->setText(QCoreApplication::translate("Window_login", "\346\270\270\345\256\242\347\231\273\345\275\225", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Window_login: public Ui_Window_login {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WINDOW_LOGIN_H
