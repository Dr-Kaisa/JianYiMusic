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
        qDebug() << "open :/style/bottom_.css fail";
    }
    scrollTimer = new QTimer(this);
    connect(scrollTimer, &QTimer::timeout, [=]() {
        int x_title = ui->title->x();
        int x_author = ui->author->x();
        // ui->title->move(x - 2, ui->title->y()); // 每次滚动 2 个像素
        // ui->title->setGeometry(x, y, a += 2, 70);
        // ui->title->setFixedWidth(a += 2);
        if (ui->title_wrap->width() < ui->title->width()) {
            if (x_title + ui->title->width() <= 0) {
                ui->title->move(0, ui->title->y()); // 重置
            } else {
                ui->title->move(x_title - 1, ui->title->y()); // 每次滚动 2 个像素
            }
        } else {
            ui->title->move(0, 0); // 复原
        }
        if (ui->author_wrap->width() < ui->author->width()) {
            if (x_author + ui->author->width() <= 0) {
                ui->author->move(ui->separator->width(), ui->author->y()); // 重置
            } else {
                ui->author->move(x_author - 1, ui->author->y()); // 每次滚动 2 个像素
            }
        } else {
            ui->author->move(ui->separator->x() + ui->author_wrap->width() < ui->author->width(), ui->title->y()); // 复原
        }
    });
    // ui->title->setFixedWidth(1000);
    scrollTimer->start(20); // 每 30 毫秒更新一次

    // ui->title->setElideMode(Qt::ElideNone);
    // ui->author->setT
    // ui->horizontalLayout_1->setAlignment(Qt::AlignLeft);
    // ui->title->setFixedHeight(40);
    // ui->separator->setFixedHeight(40);
    // ui->author->setFixedHeight(40);
    ui->title_wrap->setFixedSize(100, 70);
    ui->author_wrap->setFixedSize(100, 70);
    ui->title->setFixedSize(700, 70);
    ui->author->setFixedSize(700, 70);
    ui->horizontalLayout_out->setAlignment(ui->btn_pause, Qt::AlignCenter);
    ui->song_info->setFixedSize(250, 70);
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
    isPlay = true;


    // 获取当前字体
    QFont title_font = ui->title->font();
    QFontMetrics title_fm(title_font);
    // 计算文本的宽度
    int title_textWidth = title_fm.horizontalAdvance(this_song->get_title());
    //调整显示区域大小
    ui->title->setFixedWidth(title_textWidth + 10); //留点余量
    //再把文本设置上去
    ui->title->setText(this_song->get_title());

    ui->separator->setText("-");

    // 获取当前字体
    QFont author_font = ui->author->font();
    QFontMetrics author_fm(author_font);
    // 计算文本的宽度
    int author_textWidth = author_fm.horizontalAdvance(this_song->get_author());
    //调整显示区域大小
    ui->author->setFixedWidth(author_textWidth + 10);
    //再把文本设置上去
    ui->author->setText(this_song->get_author());
    qDebug() << ui->author->width();
    qDebug() << ui->title->width();

    update();
}

Song *Bottom_bar::get_this_song() {
    update();
    return thisSong;
}

void Bottom_bar::valueChangedSlot(int value) {
    emit bottom_bar_valueChange(value);
}
