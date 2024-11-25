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

    // container->setStyleSheet("QScrollArea{background-color:#f6f6f6;}");
    // container->setWidgetResizable(true); //允许子组件缩放
    Default_content *default_content = new Default_content(this);
    // Myfavo_list *myfavo_list = new Myfavo_list(this);
    Local_list *local_list = new Local_list(this);
    // local_list->hide();
    // QStackedWidget *container_widget = new QStackedWidget(this);
    // // container_widget->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    //
    // Kaka *kaka = new Kaka(this);
    //
    container->addWidget(default_content);
    container->addWidget(local_list);


    // container->setWidget(default_content);
    // container->setWidget(myfavo_list);
    // container->setWidget(local_list);
    // local_list->hide();
    // this->setCurrentIndex(1);

    //底栏
    bottom_bar = new Bottom_bar(this);
    // this->setFocusPolicy(Qt::StrongFocus);
    connect(default_content, &Default_content::mySig, this, &Window_main::getMusic);
    load_config();
}

Window_main::~Window_main() {
    delete ui;
}

//载入用户配置
void Window_main::load_config() {
    YAML::Node config = YAML::LoadFile("user.yaml");
    userName = QString::fromStdString(config["userName"].as<std::string>());
    top_bar->setUserName(userName);
    if (config["songs"].IsDefined()) {
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

void Window_main::getMusic(QString path) {
    // 创建 YAML::Emitter 对象
    YAML::Emitter out;
    // 开始生成 YAML 内容
    out << YAML::BeginMap;
    out << YAML::Key << "songs" << YAML::BeginSeq;
    QDirIterator it(path, QDir::Files, QDirIterator::Subdirectories);
    while (it.hasNext()) {
        QString songPath = it.next().trimmed();

        QFileInfo fileInfo(songPath);
        QString fileName = fileInfo.completeBaseName(); // 获取文件名（无扩展名）

        // 分割文件名（假设格式为 "歌手 - 歌曲名"）
        QStringList parts = fileName.split(" - ");


        if (parts.size() == 2) {
            QString author = parts[0]; // 歌手
            QString title = parts[1]; // 歌曲名
            out << YAML::BeginMap;
            out << YAML::Key << "author" << YAML::Value << author.toStdString();
            out << YAML::Key << "title" << YAML::Value << title.toStdString();
            out << YAML::Key << "path" << YAML::Value << songPath.toStdString();
            out << YAML::EndMap;
        } else {
            qDebug() << "Invalid format, unable to extract info.";
        }
    }
    std::ofstream fout("user.yaml", std::ios::app);
    fout << out.c_str() << std::endl; // 将生成的 YAML 内容写入文件
    fout.close();
}

