//
// Created by Dr.J on 2024/11/14.
//

#ifndef MYFAVO_LIST_H
#define MYFAVO_LIST_H

#include <QWidget>


QT_BEGIN_NAMESPACE
namespace Ui { class Myfavo_list; }
QT_END_NAMESPACE

class Myfavo_list : public QWidget {
Q_OBJECT

public:
    explicit Myfavo_list(QWidget *parent = nullptr);
    ~Myfavo_list() override;

private:
    Ui::Myfavo_list *ui;
};


#endif //MYFAVO_LIST_H
