//
// Created by 18160 on 2024/11/21.
//

// You may need to build the project (run Qt uic code generator) to get "ui_Default_content.h" resolved

#include "default_content.h"

#include <iostream>

#include "ui_Default_content.h"


Default_content::Default_content(QWidget *parent) : QWidget(parent), ui(new Ui::Default_content) {
    ui->setupUi(this);
    QFile file(":/style/default_content");
    setAcceptDrops(true); // 启用拖拽功能
    if (file.open(QFile::ReadOnly)) {
        QTextStream stream(&file);
        QString styleSheet = stream.readAll();
        this->setStyleSheet(styleSheet);
    } else {
        qDebug() << "open :/styles/top_bar.css fail";
    }
}

Default_content::~Default_content() {
    delete ui;
}

void Default_content::on_btn_clicked() {
    QString path = QFileDialog::getExistingDirectory();
    YAML::Node config = YAML::LoadFile("user.yaml");

    config["songPath"] = path.toStdString();
    qDebug() << path;
    std::ofstream fout("user.yaml");
    fout << config;
    fout.close();
    emit mySig();
}

void Default_content::dragEnterEvent(QDragEnterEvent *event) {
    if (event->mimeData()->hasUrls()) {
        // 检查是否拖拽的是文件夹
        QList<QUrl> urls = event->mimeData()->urls();
        if (urls.size() > 0 && QDir(urls.first().toLocalFile()).exists()) {
            event->acceptProposedAction(); // 接受拖拽
        }
    }
}


//放置事件
void Default_content::dropEvent(QDropEvent *event) {
    QList<QUrl> urls = event->mimeData()->urls();
    if (!urls.isEmpty()) {
        QString path = urls.first().toLocalFile(); // 获取文件夹路径
        if (QDir(path).exists()) {
            YAML::Node config = YAML::LoadFile("user.yaml");

            config["songPath"] = path.toStdString();
            qDebug() << path;
            std::ofstream fout("user.yaml");
            fout << config;
            fout.close();
            emit mySig();
        }
    }
}


