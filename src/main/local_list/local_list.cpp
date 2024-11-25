//
// Created by Dr.J on 2024/11/14.
//

// You may need to build the project (run Qt uic code generator) to get "ui_Local_list.h" resolved

#include "local_list.h"

#include <QPushButton>

#include "ui_Local_list.h"
#include "QDebug"


Local_list::Local_list(QWidget *parent) : QScrollArea(parent), ui(new Ui::Local_list) {
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

    this->setWidgetResizable(true); //允许子组件缩放

    this->ui->list_layout->setAlignment(Qt::AlignTop); //从上到下依次紧密排列
    this->ui->list_layout->addWidget(new List_item(Song("标题"), counter++, this));

    load_songs();
}

Local_list::~Local_list() {
    qDebug() << "end";
    delete ui;
}

void Local_list::load_songs() {
    YAML::Node config = YAML::LoadFile("user.yaml");

    // 遍历 'items' 数组
    for (const auto &item: config["songs"]) {
        // 访问每个嵌套节点的值
        QString author = QString::fromStdString(item["author"].as<std::string>());
        QString title = QString::fromStdString(item["title"].as<std::string>());
        QString path = QString::fromStdString(item["path"].as<std::string>());
        qDebug() << title + " - " + author;
        List_item *list_item = new List_item(Song(title, author, path, true), counter++, this);
        connect(list_item, &List_item::songSig, this, &Local_list::tranSlots);
        this->ui->list_layout->addWidget(list_item);
    }
}

void Local_list::tranSlots(Song song) {
    emit tranSig(song);
}

