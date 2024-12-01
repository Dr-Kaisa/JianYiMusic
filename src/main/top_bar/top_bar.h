//
// Created by Dr.J on 2024/11/14.
//

#ifndef TOP_BAR_H
#define TOP_BAR_H

#include <QWidget>
#include "QPainter"

QT_BEGIN_NAMESPACE

namespace Ui {
    class Top_bar;
}

QT_END_NAMESPACE

class Top_bar : public QWidget {
    Q_OBJECT

public:
    explicit Top_bar(QWidget *parent = nullptr);

    void paintEvent(QPaintEvent *event) override;

    ~Top_bar() override;

    void setUserName(const QString &name);

signals:
    void search(QString str);

public slots:
    void on_go_search_clicked();

private:
    Ui::Top_bar *ui;
};


#endif //TOP_BAR_H
