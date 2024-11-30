//
// Created by Dr.J on 2024/11/13.
//

#ifndef SIDE_BAR_H
#define SIDE_BAR_H

#include <QLabel>
#include <QWidget>
#include <QFile>
#include <QStyleOption>
#include <QDebug>


QT_BEGIN_NAMESPACE

namespace Ui {
    class Side_bar;
}

QT_END_NAMESPACE

class Side_bar : public QWidget {
    Q_OBJECT

public:
    explicit Side_bar(QWidget *parent = nullptr);


    ~Side_bar() override;

    void paintEvent(QPaintEvent *event) override;

signals:
    void myFavo_clicked(QString target);

    void local_clicked(QString target);

private:
    Ui::Side_bar *ui;
};


#endif //SIDE_BAR_H
