//
// Created by 18160 on 2024/11/21.
//

#ifndef DEFAULT_CONTENT_H
#define DEFAULT_CONTENT_H

#include <QWidget>
#include <QFile>
#include <QTextStream>
#include <QDebug>
#include <QFileDialog>
#include <QDirIterator>
#include  "yaml.h"
#include <fstream>
#include <QDropEvent>
#include <QDragEnterEvent>
#include <QMimeData>
#include <QDir>
// #include <iostream>


QT_BEGIN_NAMESPACE

namespace Ui {
    class Default_content;
}

QT_END_NAMESPACE

class Default_content : public QWidget {
    Q_OBJECT

public:
    explicit Default_content(QWidget *parent = nullptr);

    ~Default_content() override;

    void dragEnterEvent(QDragEnterEvent *event) override;

    void dropEvent(QDropEvent *event) override;

public slots:
    void on_btn_clicked();

signals:
    void mySig(); //音乐文件夹路径信号

private:
    Ui::Default_content *ui;
};


#endif //DEFAULT_CONTENT_H
