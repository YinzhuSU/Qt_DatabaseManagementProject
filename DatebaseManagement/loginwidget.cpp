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
    ui->lblNotice->setStyleSheet("QLabel{ background-color : white; color : red;}");
    ui->lblNotice->setFont(QFont("Timers", 12, QFont::Bold));
    ui->lblNotice->hide();

    //set Return button and go back to Choosing Language view
    connect(ui->btnReturn, &QPushButton::clicked,
            [=](){
        this->sendSlotForReturn();
        ui->leUsername->setText(NULL);
        ui->lePassword->setText(NULL);
    });


    //set SignUp button and go to SignUp view
    connect(ui->btnSignUp, &QPushButton::clicked,
            [=](){
        ui->leUsername->setText(NULL);
        ui->lePassword->setText(NULL);
        signUp->show();
    });

    //deal with mainView's return signal(return from MainView when clicked LogOut button
    connect(mainView, &MainViewWidget::returnSignal, this, &LoginWidget::dealMainViewReturnSignal);


    connOpen();
}

void LoginWidget::sendSlotForReturn()
{
    emit returnButtonSignal();
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

void LoginWidget::on_btnLogin_clicked()
{
    QString username, password;
    username = ui->leUsername->text();
    password = ui->lePassword->text();

    if(username == NULL || password == NULL)
    {
        ui->lblNotice->show();
        ui->lblNotice->setText("Please enter both username and password.");
    }else{

        if(!connOpen())
        {
            qDebug() << "Database is not open.";
        }

        QSqlQuery *qry = new QSqlQuery;
        if(qry->exec("SELECT * FROM UserInfo WHERE Username = '"+ username +"' and Password = '"+ password +"'"))
        {
            int count = 0;
            while(qry->next())
            {
                count++;
            }

            if(count >= 1) //correct username and password, in fact, it cannot more than 1
            {
                ui->lblNotice->setText("Username and password is correct!");
                ///3//how to pass "username" to mainView's lblTitle?
                ///solved:
                qry->first();
                mainView->setWindowTitle("Welcome " + qry->value(1).toString() + " ! Manage your Database!"); //there should add name not username
                this->hide();
                ui->lblNotice->hide();
                ui->leUsername->setText(NULL);
                ui->lePassword->setText(NULL);
                mainView->show();
            }
            else
            {
                ui->lblNotice->show();
                ui->lblNotice->setText("Username or password is NOT correct.");
            }
        }
    }
}
