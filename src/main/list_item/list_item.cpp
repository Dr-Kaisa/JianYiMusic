//
// Created by 18160 on 2024/11/18.
//

// You may need to build the project (run Qt uic code generator) to get "ui_List_item.h" resolved

#include "list_item.h"
#include <QPainter>
#include "QDebug"
#include "ui_List_item.h"


List_item::List_item(const Song &song, int num, QWidget *parent) : song(song), num(num), QWidget(parent),
                                                                   ui(new Ui::List_item) {
    ui->setupUi(this);
    //启用样式表,并从文件加载样式
    this->setAttribute(Qt::WA_StyledBackground);
    QFile file(":/style/list_item");
    if (file.open(QFile::ReadOnly)) {
        QTextStream stream(&file);
        QString styleSheet = stream.readAll();
        this->setStyleSheet(styleSheet);
    } else {
        qDebug() << "open :/style/list_item.css fail";
    }

    this->ui->favo->setFixedSize(30, 30);
    if (num) {
        ui->num->setText(QString::number(num));
    } else {
        ui->num->setText("序号");
    }
    if (num % 2) {
        this->setStyleSheet("#List_item{background-color: #fff4f4;}");
    } else {
        this->setStyleSheet("#List_item{background-color: #eee3e3;}");
    }
    ui->title->setText(song.get_title());
    ui->author->setText(song.get_author());
    if (song.get_title() == "标题") {
        ui->author->hide();
        this->setEnabled(false);
    }
}

List_item::~List_item() {
    delete ui;
}

void List_item::paintEvent(QPaintEvent *event) {
    QPainter painter(this);
    //列表头不渲染这些
    if (song.get_title() == "标题") {
        return;
    }
    //是收藏的歌曲，显示红心心，否则白心心
    if (song.is_favo()) {
        painter.drawPixmap(ui->favo->geometry(), QPixmap(":/icon/favo"));
    } else {
        painter.drawPixmap(ui->favo->geometry(), QPixmap(":/icon/favo_no"));
    }
    //按下收藏
    if (pressFavo) {
        painter.drawPixmap(ui->favo->geometry(), QPixmap(":/icon/favo_press"));
        pressFavo = false;
    }
    //取消/确定收藏，切换对应图标
    if (changeFavo) {
        //先清除之前画的
        painter.fillRect(ui->favo->geometry(), this->palette().window());
        if (song.is_favo()) {
            painter.drawPixmap(ui->favo->geometry(), QPixmap(":/icon/favo_no"));
            song.set_favo(false);
        } else {
            painter.drawPixmap(ui->favo->geometry(), QPixmap(":/icon/favo"));
            song.set_favo(true);
        }
        changeFavo = false;
    }
}

void List_item::mousePressEvent(QMouseEvent *event) {
    //点收藏图标就更新收藏图标，否者更新背景
    if (ui->favo->geometry().contains(event->pos())) {
        pressFavo = true;
        update();
    } else {
        if (num % 2) {
            this->setStyleSheet("#List_item{background-color: #ddd2d2;}");
        } else {
            this->setStyleSheet("#List_item{background-color: #ccc1c1;}");
        }
    }
    QWidget::mousePressEvent(event); // 保留父类的处理
}

// 收藏区域松开则改变收藏图标，，否者恢复样式
void List_item::mouseReleaseEvent(QMouseEvent *event) {
    if (ui->favo->geometry().contains(event->pos())) {
        changeFavo = true;
        emit favoSig(song);
        update();
    } else {
        if (num % 2) {
            this->setStyleSheet("#List_item{background-color: #fff4f4;}");
        } else {
            this->setStyleSheet("#List_item{background-color: #eee3e3;}");
        }
    }
    QWidget::mouseReleaseEvent(event); // 保留父类的处理
}

//双击播放
void List_item::mouseDoubleClickEvent(QMouseEvent *event) {
    emit songSig(song);
}

