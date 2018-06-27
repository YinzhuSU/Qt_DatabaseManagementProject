#include "loginwidget.h"
#include "ui_loginwidget.h"

LoginWidget::LoginWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::LoginWidget)
{
    ui->setupUi(this);

//    connect(ui->btnReturn, &QPushButton::clicked,
//            [=](){
//        language.show();
//    });
    connect(ui->btnReturn, &QPushButton::clicked, this, &LoginWidget::sendSlot);

}

void LoginWidget::sendSlot()
{
    emit returnButtonSignal();
}

LoginWidget::~LoginWidget()
{
    delete ui;
}
