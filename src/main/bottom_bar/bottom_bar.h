//
// Created by 18160 on 2024/11/21.
//

#ifndef BOTTOM_BAR_H
#define BOTTOM_BAR_H

#include <QWidget>
#include <QPainter>
#include <QDebug>
#include <QMouseEvent>


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

    void paintEvent(QPaintEvent *event) override;

    void mousePressEvent(QMouseEvent *event) override;

    void mouseReleaseEvent(QMouseEvent *event) override;

private:
    Ui::Bottom_bar *ui;
    bool favoPressed;
    bool lastPressed;
    bool pausePressed;
    bool nextPressed;
    bool circlePressed;
};


#endif //BOTTOM_BAR_H
