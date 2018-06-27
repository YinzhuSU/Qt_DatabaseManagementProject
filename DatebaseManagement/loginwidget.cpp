#include "loginwidget.h"
#include "ui_loginwidget.h"
#include "signupwidget.h"
#include "mainviewwidget.h"

LoginWidget::LoginWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::LoginWidget)
{
    ui->setupUi(this);
    this->setWindowTitle("Login");

    //set Return button
    connect(ui->btnReturn, &QPushButton::clicked, this, &LoginWidget::sendSlotForReturn);
    //set SignUp button
    connect(ui->btnSignUp, &QPushButton::clicked, signUp, &SignUpWidget::show);
    //set Login button
    connect(ui->btnLogin, &QPushButton::clicked, this, &LoginWidget::switchToMainView);
    //deal with mainView's return signal
    connect(mainView, &MainViewWidget::returnSignal, this, &LoginWidget::dealMainViewReturnSignal);
}

void LoginWidget::sendSlotForReturn()
{
    emit returnButtonSignal();
}

void LoginWidget::switchToMainView()
{
    this->hide();
    mainView->show();
}

void LoginWidget::dealMainViewReturnSignal()
{
    mainView->hide();
    this->show();
}

LoginWidget::~LoginWidget()
{
    delete ui;
}
