//
// Created by Dr.J on 2024/11/14.
//

// You may need to build the project (run Qt uic code generator) to get "ui_Song_list.h" resolved

#include "song_list.h"

#include <QPushButton>

#include "ui_Song_list.h"
#include "QDebug"


Song_list::Song_list(QList<Song> *localSongs, QWidget *parent) : QScrollArea(parent),
                                                                 ui(new Ui::Song_list) {
    ui->setupUi(this);

    QScrollBar *vScrollBar = this->verticalScrollBar();

    // 设置滚动条属性
    vScrollBar->setRange(0, 200); // 垂直方向滚动范围
    vScrollBar->setSingleStep(20); // 垂直单步滚动————上/下键每次移动的步长，对鼠标无效
    //启用样式表,并从文件加载样式
    this->setAttribute(Qt::WA_StyledBackground);
    QFile file(":/style/song_list");
    if (file.open(QFile::ReadOnly)) {
        QTextStream stream(&file);
        QString styleSheet = stream.readAll();
        this->setStyleSheet(styleSheet);
    } else {
        qDebug() << "open :/style/song_list.css fail";
    }
    //初始样式设置
    this->setWidgetResizable(true); //允许子组件缩放
    this->ui->list_layout->setAlignment(Qt::AlignTop); //从上到下依次紧密排列
    this->ui->list_layout->addWidget(new List_item(Song("标题"), counter++, this));

    load_songs(localSongs);
}

Song_list::~Song_list() {
    delete itemArray;
    delete ui;
}

void Song_list::load_songs(QList<Song> *localSongs) {
    //重新填充

    for (const Song &it: *localSongs) {
        if (!localSongs) {
            qDebug() << "localSongs is null!";
            return;
        }
        if (localSongs->isEmpty()) {
            qDebug() << "localSongs is empty!";
        } else {
            qDebug() << "localSongs contains" << localSongs->size() << "songs.";
        }
        // 解引用 shared_ptr 获取 QList<Song>
        List_item *list_item = new List_item(it, counter++, this);
        connect(list_item, &List_item::songSig, this, &Song_list::tranSlot1);
        connect(list_item, &List_item::favoSig, this, &Song_list::tranSlot2);
        connect(list_item, &List_item::deFavoSig, this, &Song_list::tranSlot3);
        itemArray->append(list_item); // 将 List_item 添加到 itemArray 中
        this->ui->list_layout->addWidget(list_item); // 将 List_item 添加到布局中
    }
}

void Song_list::tranSlot1(Song song) {
    qDebug() << "转发播放信号";
    emit tranSig(song);
}

void Song_list::tranSlot2(Song song) {
    qDebug() << "转发收藏信号";
    emit favoSig(song);
}

void Song_list::tranSlot3(Song song) {
    qDebug() << "Song_list::tranSlot3: emit deFavoSig" << song.get_path();
    emit deFavoSig(song);
    // emit changeLocalIcon(song);
}

//更新对应表项
void Song_list::bot_favoChange(Song song) {
    for (List_item *it: *itemArray) {
        if (it->get_song().get_path() == song.get_path()) {
            it->set_song(song);
            it->update();
        }
    }
}

// 响应收藏页面收藏的信号
void Song_list::changeFavoIcon(Song song) {
    for (List_item *it: *itemArray) {
        if (it->get_song().get_path() == song.get_path()) {
            it->get_song().set_favo(song.is_favo());
            it->update();
        }
    }
}


Song_list::FavoSongManager::FavoSongManager(Song_list *parent) : parent(parent) {
}

//收藏管理模块
//添加至收藏页面
void Song_list::FavoSongManager::addSong(Song song) {
    List_item *list_item = new List_item(song, parent->counter++, parent);
    parent->itemArray->append(list_item);
    parent->ui->list_layout->addWidget(list_item);
    connect(list_item, &List_item::songSig, parent, &Song_list::tranSlot1);
    connect(list_item, &List_item::favoSig, parent, &Song_list::tranSlot2);
    connect(list_item, &List_item::deFavoSig, parent, &Song_list::tranSlot3);
}

//从收藏页面移除
void Song_list::FavoSongManager::deleteSong(Song song) {
    parent->counter--;
    for (List_item *it: *(parent->itemArray)) {
        if (it->get_song().get_path() == song.get_path()) {
            parent->itemArray->removeOne(it);
            it->deleteLater();
            break;
        }
    }
}




