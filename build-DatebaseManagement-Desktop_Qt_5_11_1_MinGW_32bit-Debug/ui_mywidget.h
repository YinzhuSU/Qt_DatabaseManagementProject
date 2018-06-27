/********************************************************************************
** Form generated from reading UI file 'mywidget.ui'
**
** Created by: Qt User Interface Compiler version 5.11.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MYWIDGET_H
#define UI_MYWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MyWidget
{
public:
    QGridLayout *gridLayout;
    QWidget *wTitle;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer;
    QLabel *lblLanguage;
    QSpacerItem *horizontalSpacer_2;
    QWidget *wButtons;
    QHBoxLayout *horizontalLayout;
    QPushButton *btnEnglish;
    QPushButton *btnChinese;

    void setupUi(QWidget *MyWidget)
    {
        if (MyWidget->objectName().isEmpty())
            MyWidget->setObjectName(QStringLiteral("MyWidget"));
        MyWidget->resize(357, 162);
        gridLayout = new QGridLayout(MyWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        wTitle = new QWidget(MyWidget);
        wTitle->setObjectName(QStringLiteral("wTitle"));
        horizontalLayout_2 = new QHBoxLayout(wTitle);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalSpacer = new QSpacerItem(82, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        lblLanguage = new QLabel(wTitle);
        lblLanguage->setObjectName(QStringLiteral("lblLanguage"));

        horizontalLayout_2->addWidget(lblLanguage);

        horizontalSpacer_2 = new QSpacerItem(81, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);


        gridLayout->addWidget(wTitle, 0, 0, 1, 1);

        wButtons = new QWidget(MyWidget);
        wButtons->setObjectName(QStringLiteral("wButtons"));
        horizontalLayout = new QHBoxLayout(wButtons);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        btnEnglish = new QPushButton(wButtons);
        btnEnglish->setObjectName(QStringLiteral("btnEnglish"));

        horizontalLayout->addWidget(btnEnglish);

        btnChinese = new QPushButton(wButtons);
        btnChinese->setObjectName(QStringLiteral("btnChinese"));

        horizontalLayout->addWidget(btnChinese);


        gridLayout->addWidget(wButtons, 1, 0, 1, 1);


        retranslateUi(MyWidget);
        QObject::connect(btnEnglish, SIGNAL(clicked()), MyWidget, SLOT(hide()));
        QObject::connect(btnChinese, SIGNAL(clicked()), MyWidget, SLOT(hide()));

        QMetaObject::connectSlotsByName(MyWidget);
    } // setupUi

    void retranslateUi(QWidget *MyWidget)
    {
        MyWidget->setWindowTitle(QApplication::translate("MyWidget", "MyWidget", nullptr));
        lblLanguage->setText(QApplication::translate("MyWidget", "Please choose your language", nullptr));
        btnEnglish->setText(QApplication::translate("MyWidget", "English", nullptr));
        btnChinese->setText(QApplication::translate("MyWidget", "\344\270\255\346\226\207", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MyWidget: public Ui_MyWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MYWIDGET_H
