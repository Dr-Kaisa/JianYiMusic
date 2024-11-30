//
// Created by 18160 on 2024/11/18.
//

// You may need to build the project (run Qt uic code generator) to get "ui_List_item.h" resolved

#include "list_item.h"
#include <QPainter>
#include "QDebug"
#include "ui_List_item.h"


List_item::List_item(Song song, int num, QWidget *parent) : song(song), num(num), QWidget(parent),
                                                            ui(new Ui::List_item) {
    ui->setupUi(this);
    //启用样式表
    this->setAttribute(Qt::WA_StyledBackground);
    QFile file1(":/style/list_item_normal_odd");
    QFile file2(":/style/list_item_normal_even");
    QFile file3(":/style/list_item_press_odd");
    QFile file4(":/style/list_item_press_even");

    if (file1.open(QFile::ReadOnly)) {
        QTextStream stream(&file1);
        style_normal_odd = stream.readAll();
    }
    if (file2.open(QFile::ReadOnly)) {
        QTextStream stream(&file2);
        style_normal_even = stream.readAll();
    }
    if (file3.open(QFile::ReadOnly)) {
        QTextStream stream(&file3);
        style_press_odd = stream.readAll();
    }
    if (file4.open(QFile::ReadOnly)) {
        QTextStream stream(&file4);
        style_press_even = stream.readAll();
    }
    this->setFixedHeight(80);
    this->ui->favo->setFixedSize(40, 40);
    if (num) {
        ui->num->setText(QString::number(num));
    } else {
        ui->num->setText("序号");
    }
    //初始渲染的背景交替变化
    if (num % 2) {
        this->setStyleSheet(style_normal_odd);
    } else {
        this->setStyleSheet(style_normal_even);
    }

    ui->title->setText(song.get_title());
    ui->author->setText(song.get_author());
    if (song.get_title() == "标题") {
        ui->author->hide();
        this->setEnabled(false);
    }
    qDebug() << " list item done";
}

List_item::~List_item() {
    delete ui;
}

Song &List_item::get_song() {
    return song;
}

void List_item::set_song(const Song &song) {
    this->song = song;
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
        //根据歌曲是否为收藏渲染对应样式
        if (song.is_favo()) {
            painter.drawPixmap(ui->favo->geometry(), QPixmap(":/icon/favo"));
        } else {
            painter.drawPixmap(ui->favo->geometry(), QPixmap(":/icon/favo_no"));
        }
        changeFavo = false;
    }
    QWidget::paintEvent(event);
}

void List_item::mousePressEvent(QMouseEvent *event) {
    //点收藏图标就更新收藏图标，否者更新背景
    if (ui->favo->geometry().contains(event->pos())) {
        pressFavo = true;
        update();
        return;
    } else {
        //按下后背景变化
        if (num % 2) {
            this->setStyleSheet(style_press_odd);
        } else {
            this->setStyleSheet(style_press_even);
        }
        QWidget::mousePressEvent(event); // 保留父类的处理
    }
}

// 收藏区域松开则改变收藏图标，并在改变前改变favo属性，否者恢复样式
void List_item::mouseReleaseEvent(QMouseEvent *event) {
    if (ui->favo->geometry().contains(event->pos())) {
        changeFavo = true;
        if (song.is_favo()) {
            song.set_favo(false);
            emit deFavoSig(song);
        } else {
            song.set_favo(true);
            emit favoSig(song);
        }
    } else {
        if (num % 2) {
            this->setStyleSheet(style_normal_odd);
        } else {
            this->setStyleSheet(style_normal_even);
        }
    }
    update();
    QWidget::mouseReleaseEvent(event); // 保留父类的处理
}

//双击播放
void List_item::mouseDoubleClickEvent(QMouseEvent *event) {
    emit songSig(song);
    QWidget::mouseDoubleClickEvent(event);
}

