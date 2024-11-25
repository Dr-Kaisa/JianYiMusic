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
    emit mySig(path);
}


