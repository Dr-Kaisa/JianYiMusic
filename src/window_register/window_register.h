//
// Created by Dr.J on 2024/11/12.
//

#ifndef WINDOW_REGISTER_H
#define WINDOW_REGISTER_H

#include <QWidget>
#include <QFile>
#include <QTextStream>
#include "QDebug"


QT_BEGIN_NAMESPACE

namespace Ui {
    class Window_register;
}

QT_END_NAMESPACE

class Window_register : public QWidget {
    Q_OBJECT

public:
    explicit Window_register(QWidget *parent = nullptr);

    ~Window_register() override;

    // public slots:
    //     void on_btn_register_clicked();
    //
    //     void on_btn_login_clicked();

private:
    Ui::Window_register *ui;
};


#endif //WINDOW_REGISTER_H
