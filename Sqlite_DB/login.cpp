#include "login.h"
#include "ui_login.h"

Login::Login(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Login)
{
    ui->setupUi(this);
    
    if(!connOpen())
    {
        ui->label->setText("Failed to open the database.");
    }
    else
    {
        ui->label->setText("Database connected successfully!");
    }
}


Login::~Login()
{
    delete ui;
}

void Login::on_btnLogin_clicked()
{
    QString username, password;
    username = ui->leUsername->text();
    password = ui->lePassword->text();

    if(!connOpen())
    {
        qDebug() << "Database is not open.";
    }

    connOpen();
    QSqlQuery *qry = new QSqlQuery;
    qry->prepare("SELECT * FROM employee WHERE username = '"+ username +"' and password = '"+ password +"'");


    if(qry->exec())
    {
        int count = 0;
        while(qry->next())
        {
            count++;
        }

        if(count == 1)
        {
            ui->label->setText("Username and password is correct!");

            connClose(); ///
            this->hide();
//            employeeInfo empInfo;
//            empInfo.setModal(true);
//            empInfo.exec(); //这样产生的对话框一定是模态对话框，show()产生的不一定，取决于modal属性
            empInfo->show();
        }
        else if(count > 1)
        {
            ui->label->setText("Duplicate username and password.");
        }
        else
        {
            ui->label->setText("Username and password is NOT correct.");
        }
    }
}
