//
// Created by Dr.J on 2024/11/12.
//

// You may need to build the project (run Qt uic code generator) to get "ui_Window_main.h" resolved

#include "window_main.h"


#include "ui_Window_main.h"


Window_main::Window_main(QWidget *parent) : QStackedWidget(parent), ui(new Ui::Window_main) {
    ui->setupUi(this);
    resizeTimer = new QTimer(this);
    resizeTimer->setInterval(500); // 每 500 毫秒触发一次
    resizeTimer->setSingleShot(true); // 只触发一次
    connect(resizeTimer, &QTimer::timeout, this, &Window_main::enableResizeEvent);

    vh = this->screen()->size().height() / 100;
    vw = this->screen()->size().width() / 100;
    this->setGeometry(12 * vw, 10 * vh, 77 * vw, 66 * vh);
    side_bar = new Side_bar(this);
    connect(side_bar, &Side_bar::local_clicked, this, &Window_main::changeContainer);
    connect(side_bar, &Side_bar::myFavo_clicked, this, &Window_main::changeContainer);
    top_bar = new Top_bar(this);
    //内容区域
    container = new QStackedWidget(this);
    Default_content *default_content = new Default_content(this);
    connect(default_content, &Default_content::mySig, this, &Window_main::load_config);
    container->addWidget(default_content);

    bottom_bar = new Bottom_bar(this);
    connect(bottom_bar, &Bottom_bar::favo, this, &Window_main::handle_bot_favo);
    connect(bottom_bar, &Bottom_bar::deFavo, this, &Window_main::handle_bot_deFavo);
    connect(bottom_bar, &Bottom_bar::play, this, &Window_main::handlePlay);
    connect(bottom_bar, &Bottom_bar::last, this, &Window_main::handleLast);
    connect(bottom_bar, &Bottom_bar::next, this, &Window_main::handleNext);
    connect(bottom_bar, &Bottom_bar::circle, this, &Window_main::handleCircle);

    connect(bottom_bar, &Bottom_bar::bottom_bar_valueChange, this, &Window_main::changeVolume);
    media_player = new QMediaPlayer(this);

    load_config();
    qDebug() << "mw done";
}

Window_main::~Window_main() {
    delete ui;
}

//载入用户配置
/*
 *歌曲文件夹路径存在，则将本地音乐和yaml里收藏的音乐分别加载进来，并直接显示本地音乐界面，否则去默认页面提示用户选择路径
*/
void Window_main::load_config() {
    YAML::Node config = YAML::LoadFile("user.yaml");
    userName = QString::fromStdString(config["userName"].as<std::string>());
    top_bar->setUserName(userName);
    //yaml中加载本地音乐路径
    if (config["songPath"].IsDefined()) {
        //从yaml中加载收藏歌曲

        if (config["favoSongs"].IsDefined() && !config["favoSongs"].size() == 0) {
            // 遍历 'items' 数组
            for (const auto &item: config["favoSongs"]) {
                // 访问每个嵌套节点的值
                QString author = QString::fromStdString(item["author"].as<std::string>());
                QString title = QString::fromStdString(item["title"].as<std::string>());
                QString path = QString::fromStdString(item["path"].as<std::string>());
                favoSongs->append(Song(title, author, path, true));
            }
        }
        //加载全部歌曲进内存
        songPath = QString::fromStdString(config["songPath"].as<std::string>());
        QDirIterator it(songPath, QDir::Files, QDirIterator::Subdirectories);
        while (it.hasNext()) {
            QString path = it.next().trimmed();
            // 获取文件信息
            QFileInfo fileInfo(path);
            // 获取文件名（无扩展名）
            QString fileName = fileInfo.completeBaseName();
            // 分割文件名（假设格式为 "歌手 - 歌曲名"）
            QStringList parts = fileName.split(" - ");
            if (parts.size() == 2) {
                QString author = parts[0]; // 歌手
                QString title = parts[1]; // 歌曲名
                //如果歌曲已被收藏，则favo=true
                if (favoSongs->contains(Song(title, author, path, true))) {
                    songs->append(Song(title, author, path, true));
                } else {
                    songs->append(Song(title, author, path, false));
                }
            }
        }
        myfavo_list = new Song_list(favoSongs, this);
        connect(myfavo_list, &Song_list::tranSig, this, &Window_main::play_target_song);
        connect(myfavo_list, &Song_list::deFavoSig, this, &Window_main::handleDeFavoSig);
        connect(this, &Window_main::trans_bot_favoChange, myfavo_list, &Song_list::bot_favoChange);
        container->addWidget(myfavo_list);
        favo_song_manager = new Song_list::FavoSongManager(myfavo_list);


        local_list = new Song_list(songs, this);
        container->addWidget(local_list);
        connect(local_list, &Song_list::tranSig, this, &Window_main::play_target_song);
        connect(local_list, &Song_list::favoSig, this, &Window_main::handleFavoSig);
        connect(local_list, &Song_list::deFavoSig, this, &Window_main::handleDeFavoSig);
        connect(myfavo_list, &Song_list::deFavoSig, local_list, &Song_list::changeFavoIcon); //收藏页面直接告诉本地音乐页面改变图标
        connect(this, &Window_main::trans_bot_favoChange, local_list, &Song_list::bot_favoChange);

        //默认打开本地页面
        container->setCurrentIndex(2);
    } else {
        container->setCurrentIndex(0);
    }
}


void Window_main::resizeEvent(QResizeEvent *event) {
    // 在定时器未启动时启动它
    if (!resizeTimer->isActive()) {
        resizeTimer->start();
    }
    if (resizeEnabled) {
        resizeEnabled = false;
        resizeWindow(event->size().width(), event->size().height());
    }


    QWidget::resizeEvent(event); // 确保默认行为被调用
}

void Window_main::enableResizeEvent() {
    resizeEnabled = true; // 恢复 resizeEvent 的处理
    resizeWindow(this->width(), this->height());
}

void Window_main::resizeWindow(double width, double height) {
    double w = width / 100.0;
    double h = height / 100.0;

    side_bar->setGeometry(0, 0, 20 * w, 85 * h);
    top_bar->setGeometry(20 * w, 0, 80 * w, 10 * h);
    container->setGeometry(20 * w, 10 * h, 80 * w, 76 * h);
    bottom_bar->setGeometry(0, 85 * h, 100 * w, 15 * h);
}

void Window_main::play_target_song(Song song) {
    media_player->setMedia(QUrl::fromLocalFile(song.get_path()));
    media_player->play();
    targetSong = songs->indexOf(song);
    //传给底栏
    bottom_bar->set_this_song(new Song(song));
}

//播放或暂停
void Window_main::handlePlay() {
    QMediaPlayer::State state = media_player->state();

    if (state == QMediaPlayer::PlayingState) {
        media_player->pause();
    } else if (state == QMediaPlayer::PausedState) {
        media_player->play();
    } else if (state == QMediaPlayer::StoppedState) {
        if (!songs->isEmpty() && songs->size() > targetSong - 1) {
            media_player->setMedia(QUrl(songs->at(++targetSong).get_path()));
            media_player->play();
        }
    }
}

//处理底栏收藏信号
void Window_main::handle_bot_favo(Song song) {
    //转发给收藏列表
    emit trans_bot_favoChange(song);
    YAML::Node config = YAML::LoadFile("user.yaml");
    if (!config["favoSongs"].IsDefined()) {
        config["favoSongs"] = YAML::Node(YAML::NodeType::Sequence);
    }
    // 创建一个新的项，包含三个字段
    YAML::Node newItem;
    newItem["title"] = songs->at(targetSong).get_title().toStdString();
    newItem["author"] = songs->at(targetSong).get_author().toStdString();
    newItem["path"] = songs->at(targetSong).get_path().toStdString();

    // 将新的项添加到 "items" 数组中
    if (!isItemExist(config["favoSongs"], newItem)) {
        config["favoSongs"].push_back(newItem);
    }

    // 将修改后的数据写回 YAML 文件
    std::ofstream fout("user.yaml");
    fout << config;
    fout.close();
    //更改收藏页面
    favo_song_manager->addSong(song);
}

//处理底栏取消收藏
void Window_main::handle_bot_deFavo(Song song) {
    //转发给收藏列表
    emit trans_bot_favoChange(song);
    //载入并修改配置文件
    YAML::Node config = YAML::LoadFile("user.yaml");
    // 确保 "favoSongs" 存在并是一个数组
    if (config["favoSongs"] && config["favoSongs"].IsSequence()) {
        YAML::Node favoSongs = config["favoSongs"]; // 使用值而非引用

        // 遍历数组，找到需要移除的元素
        for (size_t i = 0; i < favoSongs.size(); ++i) {
            const YAML::Node &song = favoSongs[i];

            //根据 paht 匹配要移除的歌曲
            if (song["path"] && song["path"].as<std::string>() == songs->at(targetSong).get_path().toStdString()) {
                // 移除匹配的元素
                favoSongs.remove(i);
                break;
            }
        }

        // 更新修改后的数组到原始节点
        config["favoSongs"] = favoSongs;
    }

    // 保存修改后的 YAML 文件
    std::ofstream fout("user.yaml");
    fout << config;

    //更新收藏页面
    favo_song_manager->deleteSong(song);
}


//处理列表收藏信号
//在列表取消收藏的时候会调用Song_list::FavoSongManager::addSong向收藏页面添加歌
void Window_main::handleFavoSig(Song thisSong) {
    YAML::Node config = YAML::LoadFile("user.yaml");
    //如果列表收藏的歌曲是当前播放的歌曲，发送信号给底栏通知改变
    if (songs->indexOf(thisSong) == targetSong) {
        bottom_bar->get_this_song()->set_favo(true);
    }
    if (!config["favoSongs"].IsDefined()) {
        config["favoSongs"] = YAML::Node(YAML::NodeType::Sequence);
    }

    // 创建一个新的项，包含三个字段
    YAML::Node newItem;
    newItem["title"] = thisSong.get_title().toStdString();
    newItem["author"] = thisSong.get_author().toStdString();
    newItem["path"] = thisSong.get_path().toStdString();

    // 将新的项添加到 "items" 数组中
    if (!isItemExist(config["favoSongs"], newItem)) {
        config["favoSongs"].push_back(newItem);
    }

    // 将修改后的数据写回 YAML 文件
    std::ofstream fout("user.yaml");
    fout << config;
    fout.close();
    //更改收藏页面
    favo_song_manager->addSong(thisSong);
}

//处理列表的取消收藏
//在列表取消收藏的时候会调用Song_list::FavoSongManager::deleteSong删除收藏页面的歌
void Window_main::handleDeFavoSig(Song thisSong) {
    YAML::Node config = YAML::LoadFile("user.yaml");
    // 确保 "favoSongs" 存在并是一个数组
    if (config["favoSongs"] && config["favoSongs"].IsSequence()) {
        YAML::Node favoSongs = config["favoSongs"]; // 使用值而非引用
        if (songs->indexOf(thisSong) == targetSong) {
            bottom_bar->get_this_song()->set_favo(false);
        }
        // 遍历数组，找到需要移除的元素
        for (size_t i = 0; i < favoSongs.size(); ++i) {
            const YAML::Node &song = favoSongs[i];

            //根据 paht 匹配要移除的歌曲
            if (song["path"] && song["path"].as<std::string>() == thisSong.get_path().toStdString()) {
                // 移除匹配的元素
                favoSongs.remove(i);
                break;
            }
        }

        // 更新修改后的数组到原始节点
        config["favoSongs"] = favoSongs;
    }

    // 保存修改后的 YAML 文件
    std::ofstream fout("user.yaml");
    fout << config;
    //更新收藏页面

    qDebug() << "要删除的歌" << thisSong.get_path();
    favo_song_manager->deleteSong(thisSong);
    qDebug() << "成功执行" << thisSong.get_path();
}

void Window_main::handleLast() {
    if (!songs->isEmpty() && targetSong > 0) {
        media_player->setMedia(QUrl(songs->at(--targetSong).get_path()));
        media_player->play();
    }
}

void Window_main::handleNext() {
    if (!songs->isEmpty() && songs->size() > targetSong - 1) {
        media_player->setMedia(QUrl(songs->at(++targetSong).get_path()));
        media_player->play();
    }
}

void Window_main::handleCircle() {
}

//判断是否已经收藏某个歌曲了
bool Window_main::isItemExist(const YAML::Node &items, const YAML::Node &newItem) {
    // 遍历 items 数组，检查是否已有相同的元素
    for (std::size_t i = 0; i < items.size(); i++) {
        if (items[i]["title"].as<std::string>() == newItem["title"].as<std::string>() &&
            items[i]["author"].as<std::string>() == newItem["author"].as<std::string>() &&
            items[i]["path"].as<std::string>() == newItem["path"].as<std::string>()) {
            return true; // 如果找到相同的元素，返回 true
        }
    }
    return false; // 如果没有找到相同的元素，返回 false
}

void Window_main::changeContainer(QString target) {
    if (myfavo_list && (target == "我的收藏")) {
        container->setCurrentIndex(1);
    }
    if (local_list && (target == "本地音乐")) {
        container->setCurrentIndex(2);
    }
}

//处理底栏音量变化信号
void Window_main::changeVolume(int value) {
    qDebug() << value;
    media_player->setVolume(value);
}
