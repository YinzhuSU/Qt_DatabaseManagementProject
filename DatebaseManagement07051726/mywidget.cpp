#include "mywidget.h"
#include "ui_mywidget.h"
#include "loginwidget.h"
#include <QIcon>
#include <QDebug>
#include <QTranslator>
#include <QApplication>

MyWidget::MyWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MyWidget)
{
    //qDebug() << "B";
    ui->setupUi(this);
    this->setWindowTitle("Welcome!");
    this->setWindowIcon(QIcon(":/new/prefix1/Images/language.png"));


    //set English button and Chinese button
    ///4//如何让用户在点击完语言按钮之后，进到login界面里面的username和password都先默认为NULL、不留下上次输入的痕迹？
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

void MyWidget::on_btnChinese_clicked()
{
    qDebug() << "You have choosed Chinese.";
}
