#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFile>
#include <QTextStream>
#include <QMessageBox>
#include <QDebug>
#include <QtSql/QSql>
#include <QFileInfo>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_btnWrite_clicked()
{
    QFile file("C:/Users/intern/Desktop/QtPractice/day05/QFilePracticemy/File.txt");
    if(!file.open(QFile::WriteOnly | QFile::Text))
    {
        QMessageBox::warning(this,"File not open","Your file is not opened!");
    }
    QTextStream out(&file);
    QString text = ui->plainTextEdit->toPlainText();
    out << text;
    file.flush();
    file.close();
}

void MainWindow::on_btnRead_clicked()
{
    QFile file("C:/Users/intern/Desktop/QtPractice/DatabaseManagementProject/entertainment Data/003.txt");
    if(!file.open(QFile::ReadOnly | QFile::Text)) //these enums are important
    {
        QMessageBox::warning(this,"File not open","Your file is not opened!");
    }
    QTextStream in(&file);
    QString text = in.readAll();
    ui->plainTextEdit->setPlainText(text);
    file.close();
}

void MainWindow::on_btnSave_clicked()
{

    QString content;
    content = ui->plainTextEdit->toPlainText();

    if(!connOpen())
    {
        qDebug() << "Database is not open.";
    }
    QSqlQuery *qry = new QSqlQuery;
    qry->prepare("INSERT INTO EntertainmentData(Content) VALUES('"+content+"')");
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
