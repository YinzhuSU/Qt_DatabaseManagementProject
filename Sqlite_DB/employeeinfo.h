#ifndef EMPLOYEEINFO_H
#define EMPLOYEEINFO_H

#include <QWidget>
#include <QDebug>
#include <QtSql>
#include <QFileInfo>
//#include "login.h"


namespace Ui {
class employeeInfo;
}

class employeeInfo : public QWidget
{
    Q_OBJECT
public:
    QSqlDatabase *mydb = new QSqlDatabase;

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
    explicit employeeInfo(QWidget *parent = 0);
    ~employeeInfo();

private slots:
    void on_btnSave_clicked();

private:
    Ui::employeeInfo *ui;
};

#endif // EMPLOYEEINFO_H
