#ifndef LOGINWIDGET_H
#define LOGINWIDGET_H
#include "signupwidget.h"
#include "mainviewwidget.h"
#include <QWidget>
#include <QSql>
#include <QtSql>
#include <QDebug>

namespace Ui {
class LoginWidget;
}

class LoginWidget : public QWidget
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
        ///2// what is this * gramma?
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
    explicit LoginWidget(QWidget *parent = 0);
    ~LoginWidget();
    void sendSlotForReturn();
    void dealMainViewReturnSignal();

signals:
    void returnButtonSignal();

private slots:
    void on_btnLogin_clicked();

private:
    Ui::LoginWidget *ui;
    SignUpWidget *signUp = new SignUpWidget;
    MainViewWidget *mainView = new MainViewWidget;
    QSqlDatabase *userInformation = new QSqlDatabase;
};

#endif // LOGINWIDGET_H
