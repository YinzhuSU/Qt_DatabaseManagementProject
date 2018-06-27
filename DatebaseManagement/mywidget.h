#ifndef MYWIDGET_H
#define MYWIDGET_H
#include "loginwidget.h"
#include <QWidget>

namespace Ui {
class MyWidget;
}

class MyWidget : public QWidget
{
    Q_OBJECT

public:
    explicit MyWidget(QWidget *parent = 0);
    ~MyWidget();
    void dealLoginReturnSignal();

private:
    Ui::MyWidget *ui;
    //LoginWidget *login = new LoginWidget;
    LoginWidget login;

    LoginWidget *another;

};

#endif // MYWIDGET_H
