//
// Created by Dr.J on 2024/11/11.
//

// You may need to build the project (run Qt uic code generator) to get "ui_Window_login.h" resolved

#include "window_login.h"
#include "ui_Window_login.h"


Window_login::Window_login(QWidget *parent) : QWidget(parent), ui(new Ui::Window_login) {
    ui->setupUi(this);
    //启用样式表,并从文件加载样式
    this->setAttribute(Qt::WA_StyledBackground);
    QFile file(":/style/window_login");
    if (file.open(QFile::ReadOnly)) {
        QTextStream stream(&file);
        QString styleSheet = stream.readAll();
        this->setStyleSheet(styleSheet);
    } else {
        qDebug() << "open :/style/window_login.css fail";
    }
}

Window_login::~Window_login() {
    delete ui;
}


void Window_login::on_btn_register_clicked() {
    if (!registerWindow) {
        // 如果窗口尚未创建
        registerWindow = new Window_register(); // 用成员变量创建新窗口
    }
    registerWindow->show(); // 显示窗口
    this->close(); // 关闭当前窗口
}

void Window_login::on_btn_login_clicked() {
    this->close();
    Window_main *main_window = new Window_main;
    main_window->show();
}

void Window_login::on_btn_loginByGuest_clicked() {
    //写入配置文件
    YAML::Emitter out;
    out << YAML::BeginMap;
    out << YAML::Key << "loginType" << YAML::Value << "Guest";
    out << YAML::Key << "userName" << YAML::Value << "游客";
    std::ofstream fout("user.yaml", std::ios::out);
    fout << out.c_str() << std::endl; // 将生成的 YAML 内容写入文件
    fout.close();
    //跳转页面
    this->close();
    Window_main *window_main = new Window_main;
    window_main->show();
}
