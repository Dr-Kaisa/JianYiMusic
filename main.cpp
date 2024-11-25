#include <QApplication>
#include <QPushButton>
#include "yaml.h"
#include "src/window_login/window_login.h"


/*  打开程序后，有三种情况
 *  - 配置文件不存在，直接打开登录页面
 *  - 配置文件存在，登录方式为游客，直接打开主界面
 *  - 配置文件存在，登录方式为账号密码，验证账号密码登录
 *
 */
int main(int argc, char *argv[]) {
    QApplication a(argc, argv);

    try {
        // 尝试加载 YAML 文件
        YAML::Node config = YAML::LoadFile("user.yaml");
        // 如果文件加载成功
        QString loginType = QString::fromStdString(config["loginType"].as<std::string>());
        if (loginType == "Guest") {
            qDebug() << "go_main";
            Window_main *window_main = new Window_main;
            window_main->show();
        } else if (loginType == "Account") {
            qDebug() << "checkAccount";
        }
    } catch (const std::exception &e) {
        //配置文件不存在，或不存在登录方式字段
        Window_login *window_login = new Window_login;
        window_login->setMinimumSize(800, 600);
        qDebug() << "gologin";
        window_login->show();
    }


    return QApplication::exec();
}
