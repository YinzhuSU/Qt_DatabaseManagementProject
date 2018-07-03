public class Bugs_and_problems {

    mywidget.cpp:      【已解决】//1//connect(login, &LoginWidget::returnButtonSignal, this, &MyWidget::dealLoginReturnSignal);
                              //注意！connect函数的第一项和第三项一定是pointer而不是object，如果是object就一定要加个&来取地址

                       【已解决】///4//如何让用户在点击完语言按钮之后，进到login界面里面的username和password都先默认为NULL、不留下上次输入的痕迹？
                              //只需要在loginView里面，设置点击return的时候就把已输入信息清空即可

    loginwidget.h:     【已解决】///2// *userInformation = QSqlDatabase::addDatabase("QSQLITE");
                             // what is this * gramma?

                       【已解决】///7//how to control mainView's ui buttons on LoginView:
                             //目前看来无法直接操作subclass的ui界面里的控件，但是可以让subclass写个public的函数自己控制自己的ui里的控件，然后在super class里面调用subclass的函数即可

    loginwidget.cpp:   【已解决】///3//mainView->setWindowTitle("Welcome " + username+ " ! Manage your Database!");  //how to pass "username" to mainView's lblTitle?

    mainviewwidget.cpp:       ///5//However in this case, if you just input "1" instead of "001", it still gonna work. So is this a bug?
                              /// in other word, if there is a file named "1.txt", then you will never open it.
                              //解决方案：可以检查输入的数字的位数

                        【已解决】///6// QString username = this->windowTitle(); //why the username is "Form"??
                              /// qDebug() << username;
                              /// Because at this time, the title haven't been set.注意！对于我的code，窗口的【创造】顺序不等于窗口的show顺序！

                              ///8//这里不会出现输入001却读出002的情况，可能是因为一开始query是指在-1的位置，发生一次.next才到第0个（也就是第一个）的位置

}
