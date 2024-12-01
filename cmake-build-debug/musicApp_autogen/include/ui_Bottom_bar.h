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
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Bottom_bar
{
public:
    QHBoxLayout *horizontalLayout_out;
    QSpacerItem *spacer1;
    QWidget *song_info;
    QHBoxLayout *horizontalLayout_inner;
    QWidget *title_wrap;
    QLabel *title;
    QLabel *separator;
    QWidget *author_wrap;
    QLabel *author;
    QLabel *btn_favo;
    QLabel *btn_last;
    QLabel *btn_pause;
    QLabel *btn_next;
    QLabel *btn_circle;
    QSlider *slider;
    QSpacerItem *spacer2;

    void setupUi(QWidget *Bottom_bar)
    {
        if (Bottom_bar->objectName().isEmpty())
            Bottom_bar->setObjectName(QString::fromUtf8("Bottom_bar"));
        Bottom_bar->resize(778, 242);
        horizontalLayout_out = new QHBoxLayout(Bottom_bar);
        horizontalLayout_out->setSpacing(60);
        horizontalLayout_out->setObjectName(QString::fromUtf8("horizontalLayout_out"));
        spacer1 = new QSpacerItem(40, 200, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_out->addItem(spacer1);

        song_info = new QWidget(Bottom_bar);
        song_info->setObjectName(QString::fromUtf8("song_info"));
        horizontalLayout_inner = new QHBoxLayout(song_info);
        horizontalLayout_inner->setObjectName(QString::fromUtf8("horizontalLayout_inner"));
        horizontalLayout_inner->setContentsMargins(0, 0, 0, 0);
        title_wrap = new QWidget(song_info);
        title_wrap->setObjectName(QString::fromUtf8("title_wrap"));
        title = new QLabel(title_wrap);
        title->setObjectName(QString::fromUtf8("title"));

        horizontalLayout_inner->addWidget(title_wrap);

        separator = new QLabel(song_info);
        separator->setObjectName(QString::fromUtf8("separator"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(separator->sizePolicy().hasHeightForWidth());
        separator->setSizePolicy(sizePolicy);

        horizontalLayout_inner->addWidget(separator);

        author_wrap = new QWidget(song_info);
        author_wrap->setObjectName(QString::fromUtf8("author_wrap"));
        author = new QLabel(author_wrap);
        author->setObjectName(QString::fromUtf8("author"));

        horizontalLayout_inner->addWidget(author_wrap);


        horizontalLayout_out->addWidget(song_info);

        btn_favo = new QLabel(Bottom_bar);
        btn_favo->setObjectName(QString::fromUtf8("btn_favo"));

        horizontalLayout_out->addWidget(btn_favo);

        btn_last = new QLabel(Bottom_bar);
        btn_last->setObjectName(QString::fromUtf8("btn_last"));

        horizontalLayout_out->addWidget(btn_last);

        btn_pause = new QLabel(Bottom_bar);
        btn_pause->setObjectName(QString::fromUtf8("btn_pause"));

        horizontalLayout_out->addWidget(btn_pause);

        btn_next = new QLabel(Bottom_bar);
        btn_next->setObjectName(QString::fromUtf8("btn_next"));

        horizontalLayout_out->addWidget(btn_next);

        btn_circle = new QLabel(Bottom_bar);
        btn_circle->setObjectName(QString::fromUtf8("btn_circle"));

        horizontalLayout_out->addWidget(btn_circle);

        slider = new QSlider(Bottom_bar);
        slider->setObjectName(QString::fromUtf8("slider"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(slider->sizePolicy().hasHeightForWidth());
        slider->setSizePolicy(sizePolicy1);
        slider->setOrientation(Qt::Horizontal);

        horizontalLayout_out->addWidget(slider);

        spacer2 = new QSpacerItem(40, 200, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_out->addItem(spacer2);


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
