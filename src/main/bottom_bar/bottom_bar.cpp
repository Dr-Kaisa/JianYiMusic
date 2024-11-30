//
// Created by 18160 on 2024/11/21.
//

// You may need to build the project (run Qt uic code generator) to get "ui_Bottom_bar.h" resolved

#include "bottom_bar.h"
#include "ui_Bottom_bar.h"
#include "../list_item/Song.h"


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
    ui->horizontalLayout->setAlignment(ui->btn_pause, Qt::AlignCenter);
    ui->placeholder->setFixedSize(200, 70);
    ui->btn_favo->setFixedSize(70, 70);
    ui->btn_last->setFixedSize(70, 70);
    ui->btn_pause->setFixedSize(70, 70);
    ui->btn_next->setFixedSize(70, 70);
    ui->btn_circle->setFixedSize(70, 70);
    ui->slider->setFixedSize(200, 70);
    favoPressed = false;
    lastPressed = false;
    pausePressed = false;
    nextPressed = false;
    circlePressed = false;
    connect(ui->slider, &QSlider::valueChanged, this, &Bottom_bar::valueChangedSlot);
}

Bottom_bar::~Bottom_bar() {
    delete ui;
}

void Bottom_bar::paintEvent(QPaintEvent *event) {
    QPainter painter = QPainter(this);
    if (thisSong && thisSong->is_favo()) {
        qDebug() << "是favo";
        painter.drawPixmap(ui->btn_favo->geometry(), QPixmap(":/icon/favo"));
    } else {
        painter.drawPixmap(ui->btn_favo->geometry(), QPixmap(":/icon/favo_no"));
    }
    if (favoPressed) {
        //先清除之前画的
        painter.fillRect(ui->btn_favo->geometry(), this->palette().window());
        painter.drawPixmap(ui->btn_favo->geometry(), QPixmap(":/icon/favo_press"));
    }
    if (isPlay && !pausePressed) {
        painter.drawPixmap(ui->btn_pause->geometry(), QPixmap(":/icon/play"));
    } else if (!isPlay && !pausePressed) {
        painter.drawPixmap(ui->btn_pause->geometry(), QPixmap(":/icon/pause"));
    }
    if (isPlay && pausePressed) {
        painter.drawPixmap(ui->btn_pause->geometry(), QPixmap(":/icon/play_press"));
    } else if (!isPlay && pausePressed) {
        painter.drawPixmap(ui->btn_pause->geometry(), QPixmap(":/icon/pause_press"));
    }

    painter.drawPixmap(ui->btn_last->geometry(),
                       QPixmap(lastPressed ? ":/icon/last_press" : ":/icon/last"));
    painter.drawPixmap(ui->btn_next->geometry(),
                       QPixmap(nextPressed ? ":/icon/next_press" : ":/icon/next"));
    painter.drawPixmap(ui->btn_circle->geometry(),
                       QPixmap(circlePressed ? ":/icon/circle_press" : ":/icon/circle"));
}

void Bottom_bar::mousePressEvent(QMouseEvent *event) {
    // 检测鼠标按下的位置并更新状态
    if (ui->btn_favo->geometry().contains(event->pos())) {
        favoPressed = true;
    } else if (ui->btn_last->geometry().contains(event->pos())) {
        lastPressed = true;
    } else if (ui->btn_pause->geometry().contains(event->pos())) {
        pausePressed = true;
    } else if (ui->btn_next->geometry().contains(event->pos())) {
        nextPressed = true;
    } else if (ui->btn_circle->geometry().contains(event->pos())) {
        circlePressed = true;
    }

    update(); // 触发重绘
    QWidget::mousePressEvent(event);
}

//释放时，其他子组件恢复状态，收藏组件看情况切换
void Bottom_bar::mouseReleaseEvent(QMouseEvent *event) {
    // 发送信号给父组件
    if (ui->btn_favo->geometry().contains(event->pos())) {
        if (thisSong && thisSong->is_favo() == true) {
            thisSong->set_favo(false);
            emit deFavo(*thisSong);
        } else if (thisSong && thisSong->is_favo() == false) {
            thisSong->set_favo(true);
            emit favo(*thisSong);
        }
    } else if (ui->btn_last->geometry().contains(event->pos())) {
        emit last();
    } else if (ui->btn_pause->geometry().contains(event->pos())) {
        if (isPlay) {
            isPlay = false;
        } else {
            isPlay = true;
        }
        emit play();
    } else if (ui->btn_next->geometry().contains(event->pos())) {
        emit next();
    } else if (ui->btn_circle->geometry().contains(event->pos())) {
        emit circle();
    }
    //清除按下状态
    favoPressed = false;
    lastPressed = false;
    pausePressed = false;
    nextPressed = false;
    circlePressed = false;
    update(); // 触发重绘
    QWidget::mouseReleaseEvent(event);
}

//底栏即使渲染当前播放的音乐
void Bottom_bar::set_this_song(Song *this_song) {
    thisSong = this_song;
    if (thisSong->is_favo()) { qDebug() << "yes"; }
    isPlay = true;
    update();
}

Song *Bottom_bar::get_this_song() {
    update();
    return thisSong;
}

void Bottom_bar::valueChangedSlot(int value) {
    emit bottom_bar_valueChange(value);
}
