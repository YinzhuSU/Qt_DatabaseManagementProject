public class Bugs_and_problems {

    mywidget.cpp:      【已解决】//1//connect(login, &LoginWidget::returnButtonSignal, this, &MyWidget::dealLoginReturnSignal);
                              //注意！connect函数的第一项和第三项一定是pointer而不是object，如果是object就一定要加个&来取地址

                       【已解决】///4//如何让用户在点击完语言按钮之后，进到login界面里面的username和password都先默认为NULL、不留下上次输入的痕迹？
                              //只需要在loginView里面，设置点击return的时候就把已输入信息清空即可

    loginwidget.h:     【已解决】///2// *userInformation = QSqlDatabase::addDatabase("QSQLITE");
                             // what is this * gramma?

    loginwidget.cpp:   【已解决】///3//mainView->setWindowTitle("Welcome " + username+ " ! Manage your Database!");  //how to pass "username" to mainView's lblTitle?

    mainviewwidget.cpp:       ///5//However in this case, if you just input "1" instead of "001", it still gonna work. So is this a bug?
                              /// in other word, if there is a file named "1.txt", then you will never open it.
                              //解决方案：可以检查输入的数字的位数
}
