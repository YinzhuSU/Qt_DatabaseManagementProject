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
    explicit LoginWidget(QWidget *parent = 0);
    ~LoginWidget();
    void sendSlotForReturn();
    void switchToMainView();
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
