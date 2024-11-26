//
// Created by Dr.J on 2024/11/14.
//

// You may need to build the project (run Qt uic code generator) to get "ui_Local_list.h" resolved

#include "local_list.h"

#include <QPushButton>

#include "ui_Local_list.h"
#include "QDebug"


Local_list::Local_list(QList<Song> *localSongs, QWidget *parent) : QScrollArea(parent),
                                                                   ui(new Ui::Local_list) {
    ui->setupUi(this);
    //启用样式表,并从文件加载样式
    this->setAttribute(Qt::WA_StyledBackground);
    QFile file(":/style/local_list");
    if (file.open(QFile::ReadOnly)) {
        QTextStream stream(&file);
        QString styleSheet = stream.readAll();
        this->setStyleSheet(styleSheet);
    } else {
        qDebug() << "open :/style/local_list.css fail";
    }
    //初始样式设置
    this->setWidgetResizable(true); //允许子组件缩放
    this->ui->list_layout->setAlignment(Qt::AlignTop); //从上到下依次紧密排列
    this->ui->list_layout->addWidget(new List_item(Song("标题"), counter++, this));
    //
    // for (const Song &it: localSongs) {
    //     List_item *list_item = new List_item(it, counter++, this);
    //     itemArray->append(list_item);
    //     this->ui->list_layout->addWidget(list_item);
    // }
    load_songs(localSongs);
}

Local_list::~Local_list() {
    delete itemArray;
    delete ui;
}

void Local_list::load_songs(QList<Song> *localSongs) {
    qDebug() << "reload";
    //删除之前的
    // for (List_item *it: itemArray) {
    //     delete it;
    // }
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
        connect(list_item, &List_item::songSig, this, &Local_list::tranSlot1);
        connect(list_item, &List_item::favoSig, this, &Local_list::tranSlot2);
        itemArray->append(list_item); // 将 List_item 添加到 itemArray 中
        this->ui->list_layout->addWidget(list_item); // 将 List_item 添加到布局中
    }
}

void Local_list::tranSlot1(Song song) {
    qDebug() << "转发歌曲路径";
    emit tranSig(song);
}

void Local_list::tranSlot2(Song song) {
    qDebug() << "转发歌曲路径";
    emit favoSig(song);
}

