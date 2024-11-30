//
// Created by Dr.J on 2024/11/11.
//

#ifndef WINDOW_LOGIN_H
#define WINDOW_LOGIN_H

#include <QWidget>
#include "../window_register/window_register.h"
#include "../window_main/window_main.h"
#include <QPainter>
#include <QBrush>
#include <QPropertyAnimation>

QT_BEGIN_NAMESPACE

namespace Ui {
    class Window_login;
}

QT_END_NAMESPACE

class Window_login : public QWidget {
    Q_OBJECT

public:
    explicit Window_login(QWidget *parent = nullptr);

    ~Window_login() override;

public slots:
    void on_btn_register_clicked();

    void on_btn_login_clicked();

    void on_btn_loginByGuest_clicked();

private:
    Ui::Window_login *ui;

    Window_register *registerWindow = nullptr;
};


#endif //WINDOW_LOGIN_H
