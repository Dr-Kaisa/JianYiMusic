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
#include "../main/song_list/song_list.h"

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
#include <QMediaPlayer>

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

    bool isItemExist(const YAML::Node &items, const YAML::Node &newItem);

    void closeEvent(QCloseEvent *event) override;

signals:
    void trans_bot_favoChange(Song song);

private slots:
    void load_config();

    void enableResizeEvent();


    void play_target_song(Song song);

    void handle_bot_favo(Song song);

    void handle_bot_deFavo(Song song);

    void handleLast();

    void handlePlay();

    void handleNext();

    void handleCircle();

    void handleFavoSig(Song targetSong);

    void handleDeFavoSig(Song targetSong);

    void changeContainer(QString target);

    void changeVolume(int value);

    void handleSearch(QString str);

private:
    Ui::Window_main *ui = nullptr;
    Side_bar *side_bar = nullptr;
    Top_bar *top_bar = nullptr;
    Bottom_bar *bottom_bar = nullptr;
    Song_list *local_list = nullptr;
    Song_list *myfavo_list = nullptr;
    std::shared_ptr<Song_list> result_list = nullptr;

    Song_list::FavoSongManager *favo_song_manager = nullptr;
    double vh;
    double vw;
    bool resizeEnabled = true;
    QTimer *resizeTimer = nullptr;
    QStackedWidget *container = nullptr;
    QMediaPlayer *media_player = nullptr;
    QList<Song> *favoSongs = new QList<Song>(); //收藏的歌曲
    QList<Song> *songs = new QList<Song>(); //全部歌曲
    QList<Song> *result_songs = nullptr; //搜索结果歌曲
    int targetSong = -1; //当前播放歌曲的索引
    QString userName;
    QString songPath;
};


#endif //WINDOW_MAIN_H
