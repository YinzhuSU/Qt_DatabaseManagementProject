public class Bugs_and_problems {

    mywidget.cpp:  【已解决】//1//connect(login, &LoginWidget::returnButtonSignal, this, &MyWidget::dealLoginReturnSignal);
                            //注意！connect函数的第一项和第三项一定是pointer而不是object，如果是object就一定要加个&来取地址


}