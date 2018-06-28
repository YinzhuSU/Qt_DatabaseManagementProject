#include "mainviewwidget.h"
#include "ui_mainviewwidget.h"

MainViewWidget::MainViewWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MainViewWidget)
{
    ui->setupUi(this);
    //this->setWindowTitle("Database Management");
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
