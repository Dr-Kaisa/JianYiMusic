//
// Created by 18160 on 2024/11/21.
//

// You may need to build the project (run Qt uic code generator) to get "ui_Bottom_bar.h" resolved

#include "bottom_bar.h"
#include "ui_Bottom_bar.h"


Bottom_bar::Bottom_bar(QWidget *parent) : QWidget(parent), ui(new Ui::Bottom_bar) {
    ui->setupUi(this);
    this->setAttribute(Qt::WA_StyledBackground);
    QFile file(":/style/bottom_bar");
    if (file.open(QFile::ReadOnly)) {
        QTextStream stream(&file);
        QString styleSheet = stream.readAll();
        this->setStyleSheet(styleSheet);
    } else {
        qDebug() << "open :/style/bottom_.css fail";
    }

    ui->favo->setFixedSize(70, 70);
    ui->last->setFixedSize(70, 70);
    ui->pause->setFixedSize(70, 70);
    ui->next->setFixedSize(70, 70);
    ui->circle->setFixedSize(70, 70);
    favoPressed = false;
    lastPressed = false;
    pausePressed = false;
    nextPressed = false;
    circlePressed = false;
}

Bottom_bar::~Bottom_bar() {
    delete ui;
}

void Bottom_bar::paintEvent(QPaintEvent *event) {
    QPainter painter = QPainter(this);
    painter.drawPixmap(ui->favo->geometry(),
                       QPixmap(favoPressed ? ":/icon/favo_press" : ":/icon/favo"));
    painter.drawPixmap(ui->last->geometry(),
                       QPixmap(lastPressed ? ":/icon/last_press" : ":/icon/last"));
    painter.drawPixmap(ui->pause->geometry(),
                       QPixmap(pausePressed ? ":/icon/pause_press" : ":/icon/pause"));
    painter.drawPixmap(ui->next->geometry(),
                       QPixmap(nextPressed ? ":/icon/next_press" : ":/icon/next"));
    painter.drawPixmap(ui->circle->geometry(),
                       QPixmap(circlePressed ? ":/icon/circle_press" : ":/icon/circle"));
}

void Bottom_bar::mousePressEvent(QMouseEvent *event) {
    // 检测鼠标按下的位置并更新状态
    if (ui->favo->geometry().contains(event->pos())) {
        favoPressed = true;
    } else if (ui->last->geometry().contains(event->pos())) {
        lastPressed = true;
    } else if (ui->pause->geometry().contains(event->pos())) {
        pausePressed = true;
    } else if (ui->next->geometry().contains(event->pos())) {
        nextPressed = true;
    } else if (ui->circle->geometry().contains(event->pos())) {
        circlePressed = true;
    }

    update(); // 触发重绘
}

void Bottom_bar::mouseReleaseEvent(QMouseEvent *event) {
    // 鼠标释放时重置状态
    favoPressed = false;
    lastPressed = false;
    pausePressed = false;
    nextPressed = false;
    circlePressed = false;
    update(); // 触发重绘
}
