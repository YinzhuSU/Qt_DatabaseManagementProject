#ifndef MAINVIEWWIDGET_H
#define MAINVIEWWIDGET_H

#include <QWidget>
#include <QDebug>
#include <QtSql>
#include <QFileInfo>

namespace Ui {
class MainViewWidget;
}

class MainViewWidget : public QWidget
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
    explicit MainViewWidget(QWidget *parent = 0);
    ~MainViewWidget();
    //void sendSlotForReturnToLogin();

signals:
    void returnSignal();

private slots:
    void on_btnLogOut_clicked();

    void on_btnSaveOne_clicked();

    void on_btnSaveAll_clicked();

    void on_btnSearch_clicked();

    void on_btnImportFile_clicked();

private:
    Ui::MainViewWidget *ui;
    QString preProcessingFilename(int input);
//    void functionTest(QFile file);
};

#endif // MAINVIEWWIDGET_H
