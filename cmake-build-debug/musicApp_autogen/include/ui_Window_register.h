/********************************************************************************
** Form generated from reading UI file 'window_register.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WINDOW_REGISTER_H
#define UI_WINDOW_REGISTER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Window_register
{
public:
    QGridLayout *main_layout;
    QHBoxLayout *h_layout1;
    QLabel *label;
    QLineEdit *txt_account;
    QHBoxLayout *h_layout2;
    QLabel *label_2;
    QLineEdit *txt_password;
    QHBoxLayout *h_layout21;
    QLabel *label_21;
    QLineEdit *txt_password1;
    QHBoxLayout *h_layout4;
    QPushButton *btn_loginByCus;

    void setupUi(QWidget *Window_register)
    {
        if (Window_register->objectName().isEmpty())
            Window_register->setObjectName(QString::fromUtf8("Window_register"));
        Window_register->resize(800, 600);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Window_register->sizePolicy().hasHeightForWidth());
        Window_register->setSizePolicy(sizePolicy);
        main_layout = new QGridLayout(Window_register);
        main_layout->setObjectName(QString::fromUtf8("main_layout"));
        h_layout1 = new QHBoxLayout();
        h_layout1->setSpacing(40);
        h_layout1->setObjectName(QString::fromUtf8("h_layout1"));
        h_layout1->setContentsMargins(40, 40, 40, 40);
        label = new QLabel(Window_register);
        label->setObjectName(QString::fromUtf8("label"));

        h_layout1->addWidget(label);

        txt_account = new QLineEdit(Window_register);
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
        label_2 = new QLabel(Window_register);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        h_layout2->addWidget(label_2);

        txt_password = new QLineEdit(Window_register);
        txt_password->setObjectName(QString::fromUtf8("txt_password"));
        sizePolicy1.setHeightForWidth(txt_password->sizePolicy().hasHeightForWidth());
        txt_password->setSizePolicy(sizePolicy1);

        h_layout2->addWidget(txt_password);


        main_layout->addLayout(h_layout2, 1, 0, 1, 2);

        h_layout21 = new QHBoxLayout();
        h_layout21->setSpacing(40);
        h_layout21->setObjectName(QString::fromUtf8("h_layout21"));
        h_layout21->setContentsMargins(40, 40, 40, 40);
        label_21 = new QLabel(Window_register);
        label_21->setObjectName(QString::fromUtf8("label_21"));

        h_layout21->addWidget(label_21);

        txt_password1 = new QLineEdit(Window_register);
        txt_password1->setObjectName(QString::fromUtf8("txt_password1"));
        sizePolicy1.setHeightForWidth(txt_password1->sizePolicy().hasHeightForWidth());
        txt_password1->setSizePolicy(sizePolicy1);

        h_layout21->addWidget(txt_password1);


        main_layout->addLayout(h_layout21, 2, 0, 1, 2);

        h_layout4 = new QHBoxLayout();
        h_layout4->setSpacing(40);
        h_layout4->setObjectName(QString::fromUtf8("h_layout4"));
        h_layout4->setContentsMargins(40, 40, 40, 40);
        btn_loginByCus = new QPushButton(Window_register);
        btn_loginByCus->setObjectName(QString::fromUtf8("btn_loginByCus"));
        sizePolicy1.setHeightForWidth(btn_loginByCus->sizePolicy().hasHeightForWidth());
        btn_loginByCus->setSizePolicy(sizePolicy1);

        h_layout4->addWidget(btn_loginByCus);


        main_layout->addLayout(h_layout4, 3, 0, 1, 1);


        retranslateUi(Window_register);

        QMetaObject::connectSlotsByName(Window_register);
    } // setupUi

    void retranslateUi(QWidget *Window_register)
    {
        Window_register->setWindowTitle(QCoreApplication::translate("Window_register", "Window_login", nullptr));
        label->setText(QCoreApplication::translate("Window_register", "\346\230\265\347\247\260", nullptr));
        label_2->setText(QCoreApplication::translate("Window_register", "\350\264\246\345\217\267", nullptr));
        label_21->setText(QCoreApplication::translate("Window_register", "\345\257\206\347\240\201", nullptr));
        btn_loginByCus->setText(QCoreApplication::translate("Window_register", "\346\263\250\345\206\214", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Window_register: public Ui_Window_register {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WINDOW_REGISTER_H
