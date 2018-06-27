#ifndef MAINVIEWWIDGET_H
#define MAINVIEWWIDGET_H

#include <QWidget>

namespace Ui {
class MainViewWidget;
}

class MainViewWidget : public QWidget
{
    Q_OBJECT

public:
    explicit MainViewWidget(QWidget *parent = 0);
    ~MainViewWidget();
    //void sendSlotForReturnToLogin();

signals:
    void returnSignal();

private slots:
    void on_btnLogOut_clicked();

private:
    Ui::MainViewWidget *ui;
};

#endif // MAINVIEWWIDGET_H
