//
// Created by Dr.J on 2024/11/12.
//

// You may need to build the project (run Qt uic code generator) to get "ui_Window_register.h" resolved

#include "window_register.h"
#include "ui_Window_register.h"


Window_register::Window_register(QWidget *parent) : QWidget(parent), ui(new Ui::Window_register) {
    ui->setupUi(this);
    //启用样式表,并从文件加载样式
    this->setAttribute(Qt::WA_StyledBackground);
    QFile file(":/style/window_register");
    if (file.open(QFile::ReadOnly)) {
        QTextStream stream(&file);
        QString styleSheet = stream.readAll();
        this->setStyleSheet(styleSheet);
    } else {
        qDebug() << "open :/style/window_login.css fail";
    }
}

Window_register::~Window_register() {
    delete ui;
}
