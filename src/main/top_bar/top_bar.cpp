//
// Created by Dr.J on 2024/11/14.
//

// You may need to build the project (run Qt uic code generator) to get "ui_Top_bar.h" resolved

#include "top_bar.h"

#include <qfile.h>

#include "qDebug"
#include "ui_Top_bar.h"


Top_bar::Top_bar(QWidget *parent) : QWidget(parent), ui(new Ui::Top_bar) {
    ui->setupUi(this);

    this->setAttribute(Qt::WA_StyledBackground);
    // 加载 .qss 文件
    QFile file(":/style/top_bar");
    if (file.open(QFile::ReadOnly)) {
        QTextStream stream(&file);
        QString styleSheet = stream.readAll();
        this->setStyleSheet(styleSheet);
    } else {
        qDebug() << "open :/styles/top_bar.css fail";
    }
    // ui->go_search->setStyleSheet("border-radius: 20%;");
    ui->avatar->setFixedSize(70, 70);
    ui->name->setFixedSize(150, 50);
}

Top_bar::~Top_bar() {
    delete ui;
}

void Top_bar::on_go_search_clicked() {
    emit search(ui->input->text());
    // ui->go_search->setStyleSheet("border-radius: 20%;");
}

void Top_bar::paintEvent(QPaintEvent *event) {
    QPainter *painter = new QPainter(this);
    painter->drawPixmap(QRect(ui->avatar->pos().x(), ui->avatar->pos().y(), 70, 70), QPixmap(":/img/a1"));
    painter->end();
}

//把接口暴露给父组件进行设置
void Top_bar::setUserName(const QString &name) {
    ui->name->setText(name); // 假设 ui->name 是 QLineEdit
}




