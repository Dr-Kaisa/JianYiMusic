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
    std::ofstream fout("user.yaml");
    fout << config;
    // // 清空数组,重新载入
    // if (config["songs"] && config["songs"].IsSequence()) {
    //     qDebug() << "clear";
    //     config.remove("songs");
    // }
    // // 开始生成 YAML 内容
    // YAML::Node items = YAML::Node(YAML::NodeType::Sequence);
    // QDirIterator it(path, QDir::Files, QDirIterator::Subdirectories);
    // while (it.hasNext()) {
    //     QString songPath = it.next().trimmed();
    //
    //     QFileInfo fileInfo(songPath);
    //     QString fileName = fileInfo.completeBaseName(); // 获取文件名（无扩展名）
    //
    //     // 分割文件名（假设格式为 "歌手 - 歌曲名"）
    //     QStringList parts = fileName.split(" - ");
    //
    //     //添加节点
    //     if (parts.size() == 2) {
    //         QString author = parts[0]; // 歌手
    //         QString title = parts[1]; // 歌曲名
    //         YAML::Node item;
    //         item["author"] = author.toStdString();
    //         item["title"] = title.toStdString();
    //         item["path"] = songPath.toStdString();
    //         items.push_back(item);
    //         songs->append(Song(title, author, songPath, false));
    //     } else {
    //         qDebug() << "Invalid format, unable to extract info.";
    //     }
    // }
    // config["songs"] = items;
    // // 写回修改后的数据到文件
    // std::ofstream fout("user.yaml");
    // fout << config;
    // fout.close();
    // local_list->load_songs();
    // container->setCurrentIndex(1);
    emit mySig(path);
}


