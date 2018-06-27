#include "signupwidget.h"
#include "ui_signupwidget.h"
#include <QMessageBox>

SignUpWidget::SignUpWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SignUpWidget)
{
    ui->setupUi(this);
    this->setWindowTitle("Sign Up");

    //set Warning label
    ui->lblWarning->setStyleSheet("QLabel{ background-color : white; color : red;}");
    ui->lblWarning->setFont(QFont("Timers", 15, QFont::Bold));
    ui->lblWarning->hide();


    //sign up success message box
    connect(ui->btnSignUp, &QPushButton::clicked,
            [=](){
        QMessageBox::about(this, "Sign Up Success", "Congratulation! You have signed up successfully!");

    });
    //一点击上面的关于对话框里的OK键就直接关闭sign up的界面：
    connect(ui->btnSignUp, &QPushButton::clicked,
            [=](){
        this->hide();
    });
}

SignUpWidget::~SignUpWidget()
{
    delete ui;
}
