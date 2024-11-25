//
// Created by Dr.J on 2024/11/14.
//

// You may need to build the project (run Qt uic code generator) to get "ui_Myfavo_list.h" resolved

#include "myfavo_list.h"
#include "ui_Myfavo_list.h"


Myfavo_list::Myfavo_list(QWidget *parent) : QWidget(parent), ui(new Ui::Myfavo_list) {
    ui->setupUi(this);
}

Myfavo_list::~Myfavo_list() {
    delete ui;
}
