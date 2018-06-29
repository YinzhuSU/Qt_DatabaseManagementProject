#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDebug>
#include <QtSql>
#include <QFileInfo>
#include <QDebug>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:

    QSqlDatabase *QtProjectDB = new QSqlDatabase;

    void connClose()
    {
        QtProjectDB->close();
        QtProjectDB->removeDatabase(QSqlDatabase::defaultConnection);
    }


    bool connOpen()
    {
        *QtProjectDB = QSqlDatabase::addDatabase("QSQLITE");
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
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_btnWrite_clicked();

    void on_btnRead_clicked();

    void on_btnSave_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
