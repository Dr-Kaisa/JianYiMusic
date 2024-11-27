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
    this->setGeometry(16 * vw, 14 * vh, 66 * vw, 66 * vh);
    side_bar = new Side_bar(this);
    top_bar = new Top_bar(this);
    //内容区域
    container = new QStackedWidget(this);
    Default_content *default_content = new Default_content(this);
    // Myfavo_list *myfavo_list = new Myfavo_list(this);
    container->addWidget(default_content);

    bottom_bar = new Bottom_bar(this);
    media_player = new QMediaPlayer(this);
    // container->setStyleSheet("QScrollArea{background-color:#f6f6f6;}");
    // container->setWidgetResizable(true); //允许子组件缩放

    // local_list->hide();
    // QStackedWidget *container_widget = new QStackedWidget(this);
    // // container_widget->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    //
    // Kaka *kaka = new Kaka(this);
    //


    // container->setWidget(default_content);
    // container->setWidget(myfavo_list);
    // container->setWidget(local_list);
    // local_list->hide();
    // this->setCurrentIndex(1);
    qDebug() << "qqqwm";
    //底栏

    connect(default_content, &Default_content::mySig, this, &Window_main::load_config);
    //
    connect(bottom_bar, &Bottom_bar::play, this, &Window_main::handlePlay);
    connect(bottom_bar, &Bottom_bar::last, this, &Window_main::handleLast);
    connect(bottom_bar, &Bottom_bar::next, this, &Window_main::handleNext);
    connect(bottom_bar, &Bottom_bar::favo, this, &Window_main::handleFavo);
    connect(bottom_bar, &Bottom_bar::circle, this, &Window_main::handleCircle);
    load_config();
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
        if (config["favoSongs"].IsDefined()) {
            // 遍历 'items' 数组
            for (const auto &item: config["favoSongs"]) {
                // 访问每个嵌套节点的值
                QString author = QString::fromStdString(item["author"].as<std::string>());
                QString title = QString::fromStdString(item["title"].as<std::string>());
                QString path = QString::fromStdString(item["path"].as<std::string>());
                favoSongs->append(Song(title, author, path, true));
            }
            qDebug() << favoSongs->at(0).get_path();
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
        local_list = new Local_list(songs, this);
        container->addWidget(local_list);
        connect(local_list, &Local_list::tranSig, this, &Window_main::play_target_song);
        connect(local_list, &Local_list::favoSig, this, &Window_main::handleFavoSig);
        connect(local_list, &Local_list::tranSig, bottom_bar, &Bottom_bar::handleSong);
        container->setCurrentIndex(1);
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
    container->setGeometry(20 * w, 10 * h, 80 * w, 75 * h);
    bottom_bar->setGeometry(0, 85 * h, 100 * w, 15 * h);
}

void Window_main::play_target_song(Song song) {
    qDebug() << "target" << song.get_path();
    media_player->setMedia(QUrl::fromLocalFile(song.get_path()));
    media_player->play();
    targetSong = songs->indexOf(song);
    qDebug() << song.get_path();
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

void Window_main::handleFavo() {
    //必须先播放过一首歌才能通过底栏收藏
    if (targetSong == -1) {
        return;
    }
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
}

void Window_main::handleFavoSig(Song favoSong) {
    YAML::Node config = YAML::LoadFile("user.yaml");
    if (!config["favoSongs"].IsDefined()) {
        config["favoSongs"] = YAML::Node(YAML::NodeType::Sequence);
    }

    // 创建一个新的项，包含三个字段
    YAML::Node newItem;
    newItem["title"] = favoSong.get_title().toStdString();
    newItem["author"] = favoSong.get_author().toStdString();
    newItem["path"] = favoSong.get_path().toStdString();

    // 将新的项添加到 "items" 数组中
    if (!isItemExist(config["favoSongs"], newItem)) {
        config["favoSongs"].push_back(newItem);
    }

    // 将修改后的数据写回 YAML 文件
    std::ofstream fout("user.yaml");
    fout << config;
    fout.close();
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
