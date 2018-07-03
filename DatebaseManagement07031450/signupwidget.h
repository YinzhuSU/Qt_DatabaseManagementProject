#ifndef SIGNUPWIDGET_H
#define SIGNUPWIDGET_H

#include <QWidget>
#include <QDebug>
#include <QtSql>
#include <QFileInfo>

namespace Ui {
class SignUpWidget;
}

class SignUpWidget : public QWidget
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
    explicit SignUpWidget(QWidget *parent = 0);
    ~SignUpWidget();

private slots:
    void on_btnSignUp_clicked();

private:
    Ui::SignUpWidget *ui;
};

#endif // SIGNUPWIDGET_H
