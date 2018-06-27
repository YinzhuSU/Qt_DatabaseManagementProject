#include "mywidget.h"
#include "ui_mywidget.h"
#include "loginwidget.h"

MyWidget::MyWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MyWidget)
{
    ui->setupUi(this);
    this->setWindowTitle("Choose Language");


    //set English button and Chinese button
    connect(ui->btnEnglish, &QPushButton::clicked,
            [=](){
        login->show();
    });

    connect(ui->btnChinese, &QPushButton::clicked,
            [=](){
        login->show();
    });

    //deal with signal from loginWidget:
    ///1//
    connect(login, &LoginWidget::returnButtonSignal, this, &MyWidget::dealLoginReturnSignal);
    //注意！connect函数的第一项和第三项一定是pointer而不是object，如果是object就一定要加个&来取地址

}

void MyWidget::dealLoginReturnSignal()
{
    login->hide();
    show();
}

MyWidget::~MyWidget()
{
    delete ui;
}
