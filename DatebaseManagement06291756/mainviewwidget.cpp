#include "mainviewwidget.h"
#include "ui_mainviewwidget.h"
#include <QIcon>

MainViewWidget::MainViewWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MainViewWidget)
{
    ui->setupUi(this);
    this->setWindowIcon(QIcon(":/new/prefix1/database.jpg"));
}



MainViewWidget::~MainViewWidget()
{
    delete ui;
}


//another way to replace "connect" function
void MainViewWidget::on_btnLogOut_clicked()
{
    emit returnSignal();
}
