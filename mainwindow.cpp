#include "mainwindow.h"

#include <switchbutton.h>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    // 创建一个按钮对象
    SwitchButton *btn = new SwitchButton(this);
    btn -> resize(100, 50);
    btn -> changeText();


    this -> setFixedSize(320,80);
    this -> setWindowTitle("鼠标模式切换 By tonycody");

    btn->move((this->width() - btn->width()) / 2, (this->height() - btn->height()) / 2);

    connect(btn, &SwitchButton::clicked, btn ,&SwitchButton::handleButtonClick);
}

MainWindow::~MainWindow()
{
}

