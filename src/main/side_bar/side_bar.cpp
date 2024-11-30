//
// Created by Dr.J on 2024/11/13.
//

// You may need to build the project (run Qt uic code generator) to get "ui_Side_bar.h" resolved

#include "side_bar.h"
#include "ui_Side_bar.h"
#include "QPainter"
#include "QDebug"


Side_bar::Side_bar(QWidget *parent) : QWidget(parent), ui(new Ui::Side_bar) {
    ui->setupUi(this);
    this->setAttribute(Qt::WA_StyledBackground);
    QFile file(":/style/side_bar");
    if (file.open(QFile::ReadOnly)) {
        QTextStream stream(&file);
        QString styleSheet = stream.readAll();
        this->setStyleSheet(styleSheet);
    } else {
        qDebug() << "open :/styles/side_bar.css fail";
    }
    connect(ui->myFavo, &QPushButton::clicked, this, [this]() { emit myFavo_clicked(ui->myFavo->text()); });
    connect(ui->local, &QPushButton::clicked, this, [this]() { emit local_clicked(ui->local->text()); });
}

Side_bar::~Side_bar() {
    delete ui;
}

void Side_bar::paintEvent(QPaintEvent *event) {
    QPainter painter = QPainter(this);
    // 调用样式系统绘制背景
    QStyleOption opt;
    opt.init(this); // 初始化样式选项
    style()->drawPrimitive(QStyle::PE_Widget, &opt, &painter, this);

    painter.drawPixmap(ui->logo->geometry(), QPixmap(":/img/logo"));
}


