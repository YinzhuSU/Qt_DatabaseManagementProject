#include "mainviewwidget.h"
#include "ui_mainviewwidget.h"
#include <QMessageBox>
#include <QIcon>
#include <QFileDialog>
#include <QDateTime>

MainViewWidget::MainViewWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MainViewWidget)
{
    //一旦执行程序，这个就会被执行，点击login只是show了这个界面而已，并不是点击login这个界面才被创建出来
    ui->setupUi(this);
    this->setWindowIcon(QIcon(":/new/prefix1/database.jpg"));
    ///6//    QString username = this->windowTitle(); //why the username is "Form"??
    ///    qDebug() << username;
    /// Because at this time, the title haven't been set.
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

        QDateTime dateTime = QDateTime::currentDateTime();
        QString addedtime = dateTime.toString();

        if(!connOpen())
        {
            qDebug() << "Database is not open.";
        }
        QSqlQuery *qry = new QSqlQuery;
        qry->prepare("INSERT INTO EntertainmentData(Title, Content, Filename， AddedTime, LastModificationTime) "
                     "VALUES(:title, :content, :filename, :addedtime, :addedtime)");
        qry->bindValue(":title", title);
        qry->bindValue(":content", content);
        qry->bindValue(":filename", filename);
        qry->bindValue(":addedtime", addedtime);
        if(qry->exec())
        {
            QMessageBox::information(this, tr("Success!"), tr("Your data is imported into Database."));
            connClose();
            ui->pteTotalView->setPlainText(NULL); //Do not let the pteTotalView shows
        }
        else
        {
            QMessageBox::critical(this, tr("Error Message"),qry->lastError().text());
        }
    }
}

void MainViewWidget::on_btnSaveOne_clicked()
{
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

        QDateTime dateTime = QDateTime::currentDateTime();
        QString addedtime = dateTime.toString();

        if(!connOpen())
        {
            qDebug() << "Database is not open.";
        }

        QSqlQuery *qry = new QSqlQuery;
        qry->prepare("INSERT INTO EntertainmentData(Title, Content, Filename, AddedTime, LastModificationTime) "
                     "VALUES(:title, :content, :filename, :addedtime, :addedtime)");
        qry->bindValue(":title", title);
        qry->bindValue(":content", content);
        qry->bindValue(":filename", filename+".txt");
        qry->bindValue(":addedtime", addedtime);
        if(qry->exec())
        {
            QMessageBox::information(this, tr("Success!"), tr("Your data is imported into Database."));
            connClose();//We should close the connection of database when we finish the operations
            ui->pteTotalView->setPlainText(NULL); //Do not let the pteTotalView shows
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

            QDateTime dateTime = QDateTime::currentDateTime();
            QString addedtime = dateTime.toString();

            QSqlQuery *qry = new QSqlQuery;
            qry->prepare("INSERT INTO EntertainmentData(Title, Content, Filename, AddedTime, LastModificationTime) "
                         "VALUES(:title, :content, :filename, :addedtime, :addedtime)");
            qry->bindValue(":title", title);
            qry->bindValue(":content", content);
            qry->bindValue(":filename", filename+".txt");
            qry->bindValue(":addedtime", addedtime);
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
    ui->pteTotalView->setPlainText(NULL); //Do not let the pteTotalView shows
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
        QString clue = ui->leSearch->text();
        QSqlQuery *qry = new QSqlQuery;
        qry->prepare("SELECT * FROM EntertainmentData WHERE Title LIKE :clue OR Content LIKE :clue");
        qry->bindValue(":clue", "%"+clue+"%");
        if(qry->exec()){
            qry->first();
            if(!qry->next()){
                QMessageBox::information(this, "Nothing", "Nothing found. Please search again.");
            }
            while(qry->next()){
                QString searchResult = "File Name:" + qry->value(3).toString() +
                        "\n\n"
                        "---------------------------------------"
                        "\n\n"
                        "Title:" + qry->value(1).toString() +
                        "\n\n"
                        "---------------------------------------"
                        "\n\n"
                        "Content:" + qry->value(2).toString() +
                        "\n"
                        "===============================================\n"
                        "===============================================\n\n";
                ui->pteTotalView->insertPlainText(searchResult); //just like .append
            }

        }
    }

}

void MainViewWidget::on_btnView_clicked()
{
    if(ui->leViewFile->text() == NULL)
    {
        QMessageBox::warning(this, "Nothing to Operate", "Please enter the data name before click this button.");
    }
    else
    {
        QString filename = ui->leViewFile->text();

        if(!connOpen())
        {
            qDebug() << "Database is not open.";
        }
        QSqlQuery *qry = new QSqlQuery;
        qry->prepare("SELECT * FROM EntertainmentData WHERE Filename = :filename");
        qry->bindValue(":filename", filename+".txt");
        if(qry->exec())
        {
            if(qry->next()){
            ///8//这里不会出现输入001却读出002的情况，可能是因为一开始query是指在-1的位置，发生一次.next才到第0个（也就是第一个）的位置
                ui->pteTotalView->setPlainText(qry->value(1).toString() +"\n\n"+ qry->value(2).toString());
            }else{
                QString warningContent = "There is no file whose name is "+filename+" in your database."
                                                                                    "\n"
                                                                                    "Please import it first.";
                QMessageBox::warning(this, tr("No Data"), warningContent);
            }
            connClose();//We should close the connection of database when we finish the operations
        }
        else
        {
            QMessageBox::critical(this, tr("Error Message"),qry->lastError().text());
        }
    }
}

void MainViewWidget::on_btnUpdate_clicked()
{
    if(ui->leViewFile->text() == NULL)
    {
        QMessageBox::warning(this, "Nothing to Operate", "Please enter the data name before click this button.");
    }
    else
    {

        QString total;
        total = ui->pteTotalView->toPlainText();

        QString title = total.section("\n\n", 0, 0);
        QString content = total.section("\n\n", 1);
        QString filename = ui->leViewFile->text();

        QDateTime dateTime = QDateTime::currentDateTime();
        QString lastModificationTime = dateTime.toString();

        if(!connOpen())
        {
            qDebug() << "Database is not open.";
        }

        QSqlQuery *qry = new QSqlQuery;
        qry->prepare("UPDATE EntertainmentData SET Title = :title, Content = :content, LastModificationTime = :lastModificationTime "
                     "WHERE Filename = :filename");
        qry->bindValue(":title", title);
        qry->bindValue(":content", content);
        qry->bindValue(":lastModificationTime", lastModificationTime);
        qry->bindValue(":filename", filename+".txt");
        if(qry->exec())
        {
            QMessageBox::information(this, tr("Update Success"), tr("Your data is updated."));
            connClose();//We should close the connection of database when we finish the operations
        }
        else
        {
            QMessageBox::critical(this, tr("Error Message"),qry->lastError().text());
        }
    }
}

void MainViewWidget::on_btnDelete_clicked()
{
    if(ui->leViewFile->text() == NULL)
    {
        QMessageBox::warning(this, "Nothing to Operate", "Please enter the data name before click this button.");
    }else{


        QString filename = ui->leViewFile->text();
        if(!connOpen())
        {
            qDebug() << "Database is not open.";
        }
        QSqlQuery *qry = new QSqlQuery;
        qry->prepare("DELETE FROM EntertainmentData WHERE Filename = :filename");
        qry->bindValue(":filename", filename+".txt");
        if(qry->exec())
        {
            ui->pteTotalView->setPlainText(NULL);
            QMessageBox::information(this, tr("Delete Success"), ""+filename+".txt is deleted from your database");
            connClose();//We should close the connection of database when we finish the operations
        }
        else
        {
            QMessageBox::critical(this, tr("Error Message"),qry->lastError().text());
        }
    }
}

void MainViewWidget::on_btnDeleteAll_clicked()
{
    if(!connOpen())
    {
        qDebug() << "Database is not open.";
    }

    QSqlQuery *qry = new QSqlQuery;
    qry->prepare("DELETE FROM EntertainmentData");
    if(qry->exec())
    {
        QMessageBox::information(this, tr("Clear Success"), "All data has been deleted.");
        connClose();//We should close the connection of database when we finish the operations
    }
    else
    {
        QMessageBox::critical(this, tr("Error Message"),qry->lastError().text());
    }
}

void MainViewWidget::hideForMember()
{
    ui->btnUpdate->hide();
    ui->btnDelete->hide();
    ui->btnDeleteAll->hide();
}

void MainViewWidget::showForAdmin()
{
    ui->btnUpdate->show();
    ui->btnDelete->show();
    ui->btnDeleteAll->show();
}

void MainViewWidget::on_btnExport_clicked()
{
    if(ui->lblExportFile->text() == NULL){
        QMessageBox::warning(this, "Warning", "Please set your export location first");
    }else{
        QFile file(ui->lblExportFile->text());
        if(!file.open(QFile::WriteOnly | QFile::Text))
        {
            QMessageBox::warning(this,"File not open","Your file is not opened!");
        }
        QTextStream out(&file);
        QString text = ui->pteTotalView->toPlainText();
        out << text;
        file.flush();
        file.close();
        QMessageBox::information(this, "Export Success", "Congratulation! You have export your file!");
    }
}

void MainViewWidget::on_btnExportPath_clicked()
{
    QString filepass = QFileDialog::getSaveFileName(
                this,
                tr("Save File"),
                "C:/Users/intern/Desktop/QtPractice/DatabaseManagementProject/entertainment Data/",
                tr("Text File (*.txt)")
                );
    ui->lblExportFile->setText(filepass);
}
