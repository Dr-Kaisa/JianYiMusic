//
// Created by Dr.J on 2024/11/14.
//

#ifndef LOCAL_LIST_H
#define LOCAL_LIST_H

#include <QScrollArea>
#include <QWidget>
#include "yaml.h"
#include "../list_item/list_item.h"


QT_BEGIN_NAMESPACE

namespace Ui {
    class Local_list;
}

QT_END_NAMESPACE

class Local_list : public QScrollArea {
    Q_OBJECT

public:
    explicit Local_list(QWidget *parent = nullptr);

    ~Local_list() override;

    void load_songs();

private:
    Ui::Local_list *ui;
    int counter = 0; //计数器
};


#endif //LOCAL_LIST_H
