/********************************************************************************
** Form generated from reading UI file 'loginwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.11.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGINWIDGET_H
#define UI_LOGINWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_LoginWidget
{
public:
    QVBoxLayout *verticalLayout;
    QWidget *wTitle;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QLabel *lblLogin;
    QSpacerItem *horizontalSpacer_2;
    QWidget *wInputs;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_3;
    QWidget *widget_2;
    QGridLayout *gridLayout;
    QLabel *lblUsername;
    QLineEdit *leUsername;
    QLabel *lblPassword;
    QLineEdit *lePassword;
    QSpacerItem *horizontalSpacer_4;
    QWidget *wButtons;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer_5;
    QPushButton *btnLogin;
    QPushButton *btnReturn;
    QSpacerItem *horizontalSpacer_7;

    void setupUi(QWidget *LoginWidget)
    {
        if (LoginWidget->objectName().isEmpty())
            LoginWidget->setObjectName(QStringLiteral("LoginWidget"));
        LoginWidget->resize(283, 243);
        verticalLayout = new QVBoxLayout(LoginWidget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        wTitle = new QWidget(LoginWidget);
        wTitle->setObjectName(QStringLiteral("wTitle"));
        horizontalLayout = new QHBoxLayout(wTitle);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(102, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        lblLogin = new QLabel(wTitle);
        lblLogin->setObjectName(QStringLiteral("lblLogin"));

        horizontalLayout->addWidget(lblLogin);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        verticalLayout->addWidget(wTitle);

        wInputs = new QWidget(LoginWidget);
        wInputs->setObjectName(QStringLiteral("wInputs"));
        horizontalLayout_2 = new QHBoxLayout(wInputs);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalSpacer_3 = new QSpacerItem(29, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_3);

        widget_2 = new QWidget(wInputs);
        widget_2->setObjectName(QStringLiteral("widget_2"));
        gridLayout = new QGridLayout(widget_2);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        lblUsername = new QLabel(widget_2);
        lblUsername->setObjectName(QStringLiteral("lblUsername"));

        gridLayout->addWidget(lblUsername, 0, 0, 1, 1);

        leUsername = new QLineEdit(widget_2);
        leUsername->setObjectName(QStringLiteral("leUsername"));

        gridLayout->addWidget(leUsername, 0, 1, 1, 1);

        lblPassword = new QLabel(widget_2);
        lblPassword->setObjectName(QStringLiteral("lblPassword"));

        gridLayout->addWidget(lblPassword, 1, 0, 1, 1);

        lePassword = new QLineEdit(widget_2);
        lePassword->setObjectName(QStringLiteral("lePassword"));

        gridLayout->addWidget(lePassword, 1, 1, 1, 1);


        horizontalLayout_2->addWidget(widget_2);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_4);


        verticalLayout->addWidget(wInputs);

        wButtons = new QWidget(LoginWidget);
        wButtons->setObjectName(QStringLiteral("wButtons"));
        horizontalLayout_3 = new QHBoxLayout(wButtons);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalSpacer_5 = new QSpacerItem(31, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_5);

        btnLogin = new QPushButton(wButtons);
        btnLogin->setObjectName(QStringLiteral("btnLogin"));

        horizontalLayout_3->addWidget(btnLogin);

        btnReturn = new QPushButton(wButtons);
        btnReturn->setObjectName(QStringLiteral("btnReturn"));

        horizontalLayout_3->addWidget(btnReturn);

        horizontalSpacer_7 = new QSpacerItem(32, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_7);


        verticalLayout->addWidget(wButtons);


        retranslateUi(LoginWidget);

        QMetaObject::connectSlotsByName(LoginWidget);
    } // setupUi

    void retranslateUi(QWidget *LoginWidget)
    {
        LoginWidget->setWindowTitle(QApplication::translate("LoginWidget", "Form", nullptr));
        lblLogin->setText(QApplication::translate("LoginWidget", "Login", nullptr));
        lblUsername->setText(QApplication::translate("LoginWidget", "Username:", nullptr));
        lblPassword->setText(QApplication::translate("LoginWidget", "Password:", nullptr));
        btnLogin->setText(QApplication::translate("LoginWidget", "Login", nullptr));
        btnReturn->setText(QApplication::translate("LoginWidget", "Return", nullptr));
    } // retranslateUi

};

namespace Ui {
    class LoginWidget: public Ui_LoginWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGINWIDGET_H
