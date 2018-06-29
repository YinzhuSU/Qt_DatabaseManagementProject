#include "signupwidget.h"
#include "ui_signupwidget.h"
#include <QMessageBox>
#include <QIcon>

SignUpWidget::SignUpWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SignUpWidget)
{
    ui->setupUi(this);
    this->setWindowTitle("Sign Up");
    this->setWindowIcon(QIcon(":/new/prefix1/register.png"));
    //set Warning label
    ui->lblWarning->setStyleSheet("QLabel{ background-color : white; color : red;}");
    ui->lblWarning->setFont(QFont("Timers", 12, QFont::Bold));
    ui->lblWarning->hide();

    ui->cbAuthority->addItem(QWidget::tr("Admin"));
    ui->cbAuthority->addItem(QWidget::tr("Member"));
}

SignUpWidget::~SignUpWidget()
{
    delete ui;
}

void SignUpWidget::on_btnSignUp_clicked()
{
    QString username, password, reenter, nickname, authority;
    username = ui->leUsername->text();
    password = ui->lePassword->text();
    reenter = ui->leReenter->text();
    nickname = ui->leNickname->text();
    authority = ui->cbAuthority->currentText();



    if(username == NULL || password == NULL || reenter == NULL)
    {
        ui->lblWarning->show();
        ui->lblWarning->setText("Please fill in all the blanks.");
    }else if(password != reenter)
    {   ui->lblWarning->show();
        ui->lblWarning->setText("You have typed two different passwords.");
    }else{

        if(!connOpen())
        {
            qDebug() << "Database is not open.";
        }

        QSqlQuery *qry = new QSqlQuery;
        if(qry->exec("SELECT * FROM UserInfo WHERE Username = '"+ username +"'"))
        {
            int count = 0;
            while(qry->next())
            {
                count++;
            }

            if(count >= 1) //means there is more than 0 rows
            {
                QMessageBox::critical(this, tr("Username Already Exists"),tr("This username already exists, please choose another one."));
                //ui->lblWarning->setText("This username already exists, please choose another one.");
                ui->leUsername->setText(NULL);
                ui->lePassword->setText(NULL);
                ui->leReenter->setText(NULL);
                ui->leNickname->setText(NULL);
            }
            else
            {
                //qry->prepare();
                if(qry->exec("INSERT INTO UserInfo(Username, Password, Nickname, Authority) VALUES('"+username+"','"+password+"','"+nickname+"','"+authority+"')")) //means "If the query executes"
                {
                    ui->lblWarning->setText(NULL);
                    QMessageBox::about(this, tr("Success"), tr("Congratulation! You have signed up successfully!"));

                    connClose();//We should close the connection of database when we finish the operations
                    ui->leUsername->setText(NULL);
                    ui->lePassword->setText(NULL);
                    ui->leReenter->setText(NULL);
                    ui->leNickname->setText(NULL);
                    this->hide();
                }
                else
                {
                    QMessageBox::critical(this, tr("INSERT Error Message"),qry->lastError().text());
                }
            }

        }
        else
        {
            QMessageBox::critical(this, tr("SELECT Error Message"),qry->lastError().text());
        }


    }
}
