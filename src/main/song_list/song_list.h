//
// Created by Dr.J on 2024/11/14.
//

#ifndef Song_list_H
#define Song_list_H

#include <QScrollArea>
#include <QWidget>
#include "yaml.h"
#include <QList>
#include <QScrollBar>
#include "../list_item/list_item.h"


QT_BEGIN_NAMESPACE

namespace Ui {
    class Song_list;
}

QT_END_NAMESPACE

class Song_list : public QScrollArea {
    Q_OBJECT

public:
    explicit Song_list(QList<Song> *localSongs, QWidget *parent = nullptr);

    ~Song_list() override;

    void load_songs(QList<Song> *localSongs);

    class FavoSongManager {
    private:
        Song_list *parent;

    public:
        FavoSongManager(Song_list *parent);


        void addSong(Song song);

        void deleteSong(Song song);
    };

signals:
    void tranSig(Song song);

    void favoSig(Song song);

    void deFavoSig(Song song);

    void changeLocalIcon(Song song);

public slots:
    void tranSlot1(Song song);

    void tranSlot2(Song song);

    void tranSlot3(Song song);

    void bot_favoChange(Song song);

    void changeFavoIcon(Song song);

private:
    Ui::Song_list *ui;
    QList<List_item *> *itemArray = new QList<List_item *>;
    int counter = 0; //计数器
};


#endif //Song_list_H
