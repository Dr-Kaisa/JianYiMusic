/********************************************************************************
** Form generated from reading UI file 'song_list.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SONG_LIST_H
#define UI_SONG_LIST_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Song_list
{
public:
    QWidget *inner_widget;
    QVBoxLayout *list_layout;

    void setupUi(QScrollArea *Song_list)
    {
        if (Song_list->objectName().isEmpty())
            Song_list->setObjectName(QString::fromUtf8("Song_list"));
        inner_widget = new QWidget();
        inner_widget->setObjectName(QString::fromUtf8("inner_widget"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(inner_widget->sizePolicy().hasHeightForWidth());
        inner_widget->setSizePolicy(sizePolicy);
        list_layout = new QVBoxLayout(inner_widget);
        list_layout->setSpacing(0);
        list_layout->setObjectName(QString::fromUtf8("list_layout"));
        list_layout->setContentsMargins(0, 0, 0, 0);
        Song_list->setWidget(inner_widget);

        retranslateUi(Song_list);

        QMetaObject::connectSlotsByName(Song_list);
    } // setupUi

    void retranslateUi(QScrollArea *Song_list)
    {
        (void)Song_list;
    } // retranslateUi

};

namespace Ui {
    class Song_list: public Ui_Song_list {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SONG_LIST_H
