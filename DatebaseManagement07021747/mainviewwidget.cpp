#include "mainviewwidget.h"
#include "ui_mainviewwidget.h"
#include <QMessageBox>
#include <QIcon>
#include <QFileDialog>

MainViewWidget::MainViewWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MainViewWidget)
{
    ui->setupUi(this);
    this->setWindowIcon(QIcon(":/new/prefix1/database.jpg"));
}



MainViewWidget::~MainViewWidget()
{
    delete ui;
}


//another way to replace "connect" function
void MainViewWidget::on_btnLogOut_clicked()
{
    emit returnSignal();
}

void MainViewWidget::on_btnImportFile_clicked()
{
    QString filepass = QFileDialog::getOpenFileName(
                this,
                tr("Open File"),
                "C:/Users/intern/Desktop/QtPractice/DatabaseManagementProject/entertainment Data/",
                tr("Text File (*.txt);;All files (*.*)")
                );
    ui->leImportFile->setText(filepass);

    //
    QFile file(filepass);
    if(!file.open(QFile::ReadOnly | QFile::Text)) //these enums are important
    {
        QMessageBox::warning(this,"File not open","Your file is not opened!");
    }else{
        QTextStream in(&file);
        QString text = in.readAll();
        ui->pteTotalView->setPlainText(text);
        file.close();

        //save to database:
        QString total;
        total = ui->pteTotalView->toPlainText();

        QString title = total.section("\n\n", 0, 0);
        QString content = total.section("\n\n", 1);

        qDebug() << filepass;
        QString filename = filepass.section("/", -1, -1);

        if(!connOpen())
        {
            qDebug() << "Database is not open.";
        }
        QSqlQuery *qry = new QSqlQuery;
        qry->prepare("INSERT INTO EntertainmentData(Title, Content, Filename) VALUES(:title, :content, :filename)");
        qry->bindValue(":title", title);
        qry->bindValue(":content", content);
        qry->bindValue(":filename", filename);
        if(qry->exec())
        {
            QMessageBox::information(this, tr("Success!"), tr("Your data is imported into Database."));
            connClose();
        }
        else
        {
            QMessageBox::critical(this, tr("Error Message"),qry->lastError().text());
        }
    }
}

void MainViewWidget::on_btnSaveOne_clicked()
{
    //read file:
    QString filename = ui->leFilename->text();
    QFile file("C:/Users/intern/Desktop/QtPractice/DatabaseManagementProject/entertainment Data/"+filename+".txt");
    if(!file.open(QFile::ReadOnly | QFile::Text)) //these enums are important
    {
        QMessageBox::warning(this,"File not open","Your file is not opened!");
    }else{
        QTextStream in(&file);
        QString text = in.readAll();
        ui->pteTotalView->setPlainText(text);
        file.close();

        //save to database:
        QString total;
        total = ui->pteTotalView->toPlainText();

        QString title = total.section("\n\n", 0, 0);
        QString content = total.section("\n\n", 1);
        QString filename = ui->leFilename->text();

        if(!connOpen())
        {
            qDebug() << "Database is not open.";
        }
        QSqlQuery *qry = new QSqlQuery;
        qry->prepare("INSERT INTO EntertainmentData(Title, Content, Filename) VALUES(:title, :content, :filename)");
        qry->bindValue(":title", title);
        qry->bindValue(":content", content);
        qry->bindValue(":filename", filename+".txt");
        if(qry->exec())
        {
            QMessageBox::information(this, tr("Success!"), tr("Your data is imported into Database."));
            connClose();//We should close the connection of database when we finish the operations
        }
        else
        {
            QMessageBox::critical(this, tr("Error Message"),qry->lastError().text());
        }
    }
}

QString MainViewWidget::preProcessingFilename(int input)
{
    QString filename;
    if(input < 10) {
        filename = QString("00%1").arg(input);
    }else if(input < 100) {
        filename = QString("0%1").arg(input);
    }else{
        filename = QString::number(input);
    }
    return filename;
}

void MainViewWidget::on_btnSaveAll_clicked()
{
    int from = ui->leFrom->text().toInt();
    int to = ui->leTo->text().toInt();
    ///5//However in this case, if you just input "1" instead of "001", it still gonna work. So is this a bug?
    /// in other word, if there is a file named "1.txt", then you will never open it.

    if(!connOpen())
    {
        qDebug() << "Database is not open.";
    }

    for(int i = from; i <= to; i++) { //注意这里是从i = 1开始！
        //pre-pocessing EACH document's name:
        QString filename = preProcessingFilename(i);

        //read file:
        QFile file("C:/Users/intern/Desktop/QtPractice/DatabaseManagementProject/entertainment Data/"+filename+".txt");
        if(!file.open(QFile::ReadOnly | QFile::Text)) //these enums are important
        {
            QMessageBox::warning(this,"File not open","Your file is not opened!");
        }else{
            QTextStream in(&file);
            QString text = in.readAll();
            ui->pteTotalView->setPlainText(text);
            file.close();

            //save file into database:
            QString total;
            total = ui->pteTotalView->toPlainText();

            QString title = total.section("\n\n", 0, 0);
            QString content = total.section("\n\n", 1);

            QSqlQuery *qry = new QSqlQuery;
            qry->prepare("INSERT INTO EntertainmentData(Title, Content, Filename) VALUES(:title, :content, :filename)");
            qry->bindValue(":title", title);
            qry->bindValue(":content", content);
            qry->bindValue(":filename", filename+".txt");
            if(qry->exec())
            {
                qDebug()<< "Writing file "+filename+".txt into Database...";
            }
            else
            {
                QMessageBox::critical(this, tr("Error Message"),qry->lastError().text());
            }
        }
    }
    QMessageBox::information(this, tr("Save Success!"), tr("Your data is imported into Database."));
    connClose();
}


void MainViewWidget::on_btnSearch_clicked()
{
    if(ui->leSearch->text() == NULL){
        QMessageBox::warning(this, "Warning", "Please enter what you want to search before click 'Search'.");

    }else{
        if(!connOpen())
        {
            qDebug() << "Database is not open.";
        }
        QSqlQuery *qry = new QSqlQuery;
        qry->prepare("INSERT INTO EntertainmentData(Title, Content, Filename) VALUES(:title, :content, :filename)");
    }

}
