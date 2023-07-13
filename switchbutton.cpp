#include "switchbutton.h"
#include <QSettings>
#include <windows.h>
#include <QDebug>

// 鼠标当前模式
int g_MouseMode = 0;

SwitchButton::SwitchButton(QWidget *parent)
    : QPushButton{parent}
{
    QSettings settings("HKEY_CURRENT_USER\\Control Panel\\Mouse", QSettings::NativeFormat);
    g_MouseMode = settings.value("SwapMouseButtons").toInt();
}

/**
 * Click signal slot
 * @brief SwitchButton::handleButtonClick
 */
void SwitchButton::handleButtonClick(){
    if(g_MouseMode == 0 ){
        this -> switchMode(1);
        g_MouseMode = 1;
    }else{
        this -> switchMode(0);
        g_MouseMode = 0;
    }

    this -> changeText();
}

/**
 * Switch Model
 * @brief changeMode
 * @param modelVal
 */
void SwitchButton::switchMode(int modelVal){
    // 需要修改注册表，否则重启后设置的模式会失效
    QSettings settings("HKEY_CURRENT_USER\\Control Panel\\Mouse", QSettings::NativeFormat);
    settings.setValue("SwapMouseButtons", QString::number(modelVal));
    // 直接使用操作系统 API 来设置鼠标键的模式，不需要重启电脑快速生效
    int result = ::SystemParametersInfo(SPI_SETMOUSEBUTTONSWAP, modelVal, NULL, SPIF_SENDCHANGE);
    if (!result) {
        qDebug()<< "设置异常！";
    }
}


/**
 * Change Button Text
 * @brief SwitchButton::changeText
 */
void SwitchButton::changeText(){
    if(g_MouseMode == 0){
        this -> setText("左手模式");
    }else{
        this -> setText("右手模式");
    }
}
