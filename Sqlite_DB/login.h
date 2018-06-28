#ifndef LOGIN_H
#define LOGIN_H

#include <QMainWindow>
#include <QDebug>
//#include <QSql>//unnecessary
#include <QtSql>
#include <QFileInfo>
#include "employeeinfo.h"

namespace Ui {
class Login;
}

class Login : public QMainWindow
{
    Q_OBJECT

public:
    QSqlDatabase *mydb = new QSqlDatabase; //move it from pravite to public

    void connClose()
    {
        mydb->close();
        mydb->removeDatabase(QSqlDatabase::defaultConnection);
    }


    bool connOpen()
    {
        *mydb = QSqlDatabase::addDatabase("QSQLITE");
        mydb->setDatabaseName("C:/sqlite3/test1.db");

        if(!mydb->open())
        {
            qDebug() << "Failed to open the database.";
            return false;
        }
        else
        {
            qDebug() << "Database connected successfully!";
            return true;
        }
    }


public:
    explicit Login(QWidget *parent = 0);
    ~Login();

private slots:
    void on_btnLogin_clicked();

private:
    Ui::Login *ui;
    employeeInfo *empInfo = new employeeInfo;
};

#endif // LOGIN_H
