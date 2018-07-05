#include "mywidget.h"
#include <QApplication>
#include <QDebug>
#include <QInputDialog>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    ///9//能否把处理语言的操作放到选择语言的欢迎界面里进行？但是这个a.installTranslator(&t);里的a好像只有在main.cpp这里才有
    QTranslator t;
    QTranslator guiTranslator;
    QStringList languages;
    languages << "English" << "中文";

    QString lang = QInputDialog::getItem(NULL, "Select Language", "Language", languages);

    if(lang == "中文")
    {
        t.load(":/chinese.qm");
        guiTranslator.load("C:/Users/intern/Downloads/RuanJian/Qt/5.11.1/mingw53_32/translations/qt_zh_CN.qm");
        a.installTranslator(&t);
        a.installTranslator(&guiTranslator);
    }


    MyWidget w;
    w.show();

    return a.exec();
}
