#ifndef MYWIDGET_H
#define MYWIDGET_H
#include "loginwidget.h"
#include <QWidget>

namespace Ui {
class MyWidget;
}

class MyWidget : public QWidget
{
    Q_OBJECT

public:
    QSqlDatabase *QtProjectDB = new QSqlDatabase; //move it from pravite to public

    void connClose()
    {
        QtProjectDB->close();
        QtProjectDB->removeDatabase(QSqlDatabase::defaultConnection);
    }


    bool connOpen()
    {
        *QtProjectDB = QSqlDatabase::addDatabase("QSQLITE");
        //We should use "/" to replace "\" here:
        QtProjectDB->setDatabaseName("C:/Users/intern/Desktop/QtPractice/DatabaseManagementProject/DatebaseManagement/DB/QtProjectDB.db");

        if(!QtProjectDB->open())
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
    explicit MyWidget(QWidget *parent = 0);
    ~MyWidget();
    void dealLoginReturnSignal();

private:
    Ui::MyWidget *ui;
    LoginWidget *login = new LoginWidget;
   // LoginWidget login;
};

#endif // MYWIDGET_H
