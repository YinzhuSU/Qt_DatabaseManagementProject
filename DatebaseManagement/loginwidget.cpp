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

    //set Return button and go back to Choosing Language view
    connect(ui->btnReturn, &QPushButton::clicked, this, &LoginWidget::sendSlotForReturn);
    //set SignUp button and go to SignUp view
    connect(ui->btnSignUp, &QPushButton::clicked, signUp, &SignUpWidget::show);
    //deal with mainView's return signal(return from MainView when clicked LogOut button
    connect(mainView, &MainViewWidget::returnSignal, this, &LoginWidget::dealMainViewReturnSignal);


    ///2// what is this * gramma?
    *userInformation = QSqlDatabase::addDatabase("QSQLITE");
    userInformation->setDatabaseName("C:/sqlite3/test1.db");

    if(!userInformation->open())
    {
        ui->lblNotice->setText("Failed to open the database.");
    }
    else
    {
        ui->lblNotice->setText("Database connected successfully!");
    }


    ui->lblNotice->setStyleSheet("QLabel{ background-color : white; color : red;}");
    ui->lblNotice->setFont(QFont("Timers", 12, QFont::Bold));
    ui->lblNotice->hide();
    //set Login button
    //connect(ui->btnLogin, &QPushButton::clicked, this, &LoginWidget::switchToMainView);
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

void LoginWidget::on_btnLogin_clicked()
{
    QString username, password;
    username = ui->leUsername->text();
    password = ui->lePassword->text();

    if(!userInformation->open())
    {
        qDebug() << "Database is not open.";
        return;//could not exist?
    }

    QSqlQuery *qry = new QSqlQuery;
    if(qry->exec("SELECT * FROM employee WHERE username = '"+ username +"' and password = '"+ password +"'"))
    {
        //QString name = qry->exec("SELECT name FROM employee WHERE username = '"+ username +"'");
        int count = 0;
        while(qry->next())
        {
            count++;
        }

        if(count == 1) //correct username and password
        {
            ui->lblNotice->setText("Username and password is correct!");
            ///3//how to pass "username" to mainView's lblTitle?
            mainView->setWindowTitle("Welcome " + username + " ! Manage your Database!"); //there should add name not username
            this->switchToMainView();
        }
        else if(count > 1)
        {
            ui->lblNotice->show();
            ui->lblNotice->setText("Duplicate username and password."); //This part should be used when register
        }
        else
        {
            ui->lblNotice->show();
            ui->lblNotice->setText("Username or password is NOT correct.");
        }
    }
}
