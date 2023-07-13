#ifndef SWITCHBUTTON_H
#define SWITCHBUTTON_H

#include <QPushButton>
#include <QWidget>

class SwitchButton : public QPushButton
{
    Q_OBJECT
public:
    explicit SwitchButton(QWidget *parent = nullptr);

signals:

public slots:
    void handleButtonClick();

    void changeText();

    void switchMode(int modelVal);
};

#endif // SWITCHBUTTON_H
