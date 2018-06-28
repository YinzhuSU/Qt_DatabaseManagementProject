#include "employeeinfo.h"
#include "ui_employeeinfo.h"
//#include "login.h"
#include <QMessageBox>

employeeInfo::employeeInfo(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::employeeInfo)
{
    ui->setupUi(this);
/// can only be done if the  employeeinfo is a Dialog
///
/// 如果不执行下面这些语句，是否也可以将此页面与数据库连接？？？
//    Login conn;
    //这个构造函数在什么时候被执行？
    //看来一个数据库可以被执行多次open()?
    if(!connOpen())
    {
        ui->lblSecStatus->setText("Failed to open the database.");
    }
    else
    {
        ui->lblSecStatus->setText("Database connected successfully!");
    }
}


employeeInfo::~employeeInfo()
{
    delete ui;
}



void employeeInfo::on_btnSave_clicked()
{
    QString eid, name, surname, age;
    eid = ui->leEID->text();
    name = ui->leName->text();
    surname = ui->leSurname->text();
    age = ui->leAge->text();

    if(!connOpen())
    {
        qDebug() << "Database is not open.";
    }

    connOpen();
    QSqlQuery *qry = new QSqlQuery;
    qry->prepare("INSERT INTO employee(EmployeeID, Name, Surename, Age) VALUES('"+eid+"','"+name+"','"+surname+"','"+age+"')");

    if(qry->exec()) //means "If the query executes"
    {
        QMessageBox::information(this, tr("Save"), tr("Your data is saved."));
        connClose();//We should close the connection of database when we finish the operations
    }
    else
    {
        QMessageBox::critical(this, tr("Error Message"),qry->lastError().text());
    }
}
