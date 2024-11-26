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
    explicit Local_list(QList<Song> *localSongs, QWidget *parent = nullptr);

    ~Local_list() override;

    void load_songs(QList<Song> *localSongs);

signals:
    void tranSig(Song song);

    void favoSig(Song song);

public slots:
    void tranSlot1(Song song);

    void tranSlot2(Song song);

private:
    Ui::Local_list *ui;
    QList<List_item *> *itemArray = new QList<List_item *>;
    int counter = 0; //计数器
};


#endif //LOCAL_LIST_H
