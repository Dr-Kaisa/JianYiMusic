//
// Created by 18160 on 2024/11/21.
//

#ifndef BOTTOM_BAR_H
#define BOTTOM_BAR_H

#include <QWidget>
#include <QPainter>
#include <QDebug>
#include <QMouseEvent>
#include <../src/main/list_item/Song.h>


QT_BEGIN_NAMESPACE

namespace Ui {
    class Bottom_bar;
}

QT_END_NAMESPACE

class Bottom_bar : public QWidget {
    Q_OBJECT

public:
    explicit Bottom_bar(QWidget *parent = nullptr);

    ~Bottom_bar() override;

    Song *get_this_song();

    void set_this_song(Song *this_song);

public slots:
    void paintEvent(QPaintEvent *event) override;

    void mousePressEvent(QMouseEvent *event) override;

    void mouseReleaseEvent(QMouseEvent *event) override;

    void valueChangedSlot(int value);


signals:
    void play();

    void next();

    void last();


    void circle();

    void favo(Song song);


    void deFavo(Song song);

    void bottom_bar_valueChange(int value);

private:
    Ui::Bottom_bar *ui;
    bool favoPressed = false;
    bool lastPressed = false;
    bool pausePressed = false;
    bool nextPressed = false;
    bool circlePressed = false;
    bool isPlay = false;
    Song *thisSong = nullptr;
};


#endif //BOTTOM_BAR_H
