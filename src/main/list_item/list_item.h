//
// Created by 18160 on 2024/11/18.
//

#ifndef LIST_ITEM_H
#define LIST_ITEM_H

#include <QWidget>
#include <QFile>
#include "Song.h"
#include "QMouseEvent"


QT_BEGIN_NAMESPACE

namespace Ui {
    class List_item;
}

QT_END_NAMESPACE

class List_item : public QWidget {
    Q_OBJECT

public:
    explicit List_item(const Song &song, int num, QWidget *parent = nullptr);

    void paintEvent(QPaintEvent *event) override;

    void mousePressEvent(QMouseEvent *event) override;

    void mouseReleaseEvent(QMouseEvent *event) override;

    void mouseDoubleClickEvent(QMouseEvent *event) override;

    ~List_item() override;

signals:
    void songSig(Song song);


    // public slots:
    //     void on_pushButton_cliked();

private:
    Ui::List_item *ui;
    Song song; //歌曲
    int num; //序号
    bool pressFavo; //按下收藏图标
    bool changeFavo; //改变收藏图标
};


#endif //LIST_ITEM_H
