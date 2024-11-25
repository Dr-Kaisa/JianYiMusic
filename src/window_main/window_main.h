//
// Created by Dr.J on 2024/11/12.
//

#ifndef WINDOW_MAIN_H
#define WINDOW_MAIN_H

#include "QStackedWidget"
#include "QResizeEvent"
#include "QScreen"
#include "QDebug"
#include "QTimer"
#include "../main/local_list/local_list.h"
#include "../main/myfavo_list/myfavo_list.h"

#include <QGroupBox>
#include <QScrollArea>

#include "../main/side_bar/side_bar.h"
#include "../main/top_bar/top_bar.h"
#include "../main/bottom_bar/bottom_bar.h"
#include "../main/default_content/default_content.h"
#include "../main/list_item/Song.h"
#include  "yaml.h"
#include  "iostream"
#include <fstream>

QT_BEGIN_NAMESPACE

namespace Ui {
    class Window_main;
}

QT_END_NAMESPACE

class Window_main : public QStackedWidget {
    Q_OBJECT

public:
    explicit Window_main(QWidget *parent = nullptr);

    ~Window_main() override;

    void resizeEvent(QResizeEvent *event) override;

    void resizeWindow(double width, double height);

    void load_config();

private slots:
    void enableResizeEvent();

    void getMusic(QString path);

    void play(Song song);

private:
    Ui::Window_main *ui = nullptr;
    Side_bar *side_bar = nullptr;
    Top_bar *top_bar = nullptr;
    Bottom_bar *bottom_bar = nullptr;
    double vh;
    double vw;
    bool resizeEnabled = true;
    QTimer *resizeTimer = nullptr;
    QStackedWidget *container = nullptr;
    QList<Song> songs; //保存所以歌曲信息
    QString userName;
    QString songPath;
};


#endif //WINDOW_MAIN_H
