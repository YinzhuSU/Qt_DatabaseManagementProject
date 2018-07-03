public class Instructions {

    /*Followings are the basic requirements of the task.
    To make it easier, I’ve attached a set of texts for you.
    You can treat the first line as the topic and the rest as content.
    Therefore you don’t need to spend time on searching for data to use.*/

    Feature Requirements:
    To implement a database management program containing textual information with following features:

    1.  【OK】A user control with two types of users, admin and normal user.
            Normal users can only search data and export data. Admin user can import, modify and delete records.

    2.  【OK】Textual information searching.

    3.  【OK】Data import from text file.

    4.  【OK】Selected records export to file.

    5.  【OK】Records modification and deletion.

    6.  Graphical user interfaces that support multi language (English and Chinese) display selection.
        You don't need to have too many displays that need to be translated.

    7.  System log, which will record briefly each of admin's data deletion and modification operation.
        The log will contains information including operator's name, when he/she does the deletion/modification
        and how many records are deleted/modified. This log is also stored in the database.

    8.  For each record, there should be two time stamps stored in the database, one for when it is added and
        one for its last modification date time.


    Other Requirements:
    1.【OK】 The program should be implemented using Qt and C++.
    2.【OK】 Use QWidget to create at least three pages.
    3. Use QTranslator to implement the multi-language support.
    4.【OK】Use SQLite.
    5. A good design following SOLID and MVC will be a BIG PLUS.

    Expected Outcome:
    1. A brief relational database model design of your program.
    2. An Executable program that can run on either Windows or Linux.
    3. Other useful documents will be a plus, but not mandatary.



Views：
四个QWidget pages：
1. Choose Chinese or English (or translate during anytime?)
2. 【OK】Register
    2.1 【OK】Register Success
    2.2 【OK】The username is already taken. Please directly login.
3. 【OK】Login
    3.1 【OK】Login success. Welcome XXX (admin/member)!
    3.2 【OK】The username doesn't exist. Please re-enter your username.
    3.3 【OK】Wrong password. Please re-enter your password.
4. MainView
4.1 【OK】Textual information searching.
4.2 Data display view.
4.3 Buttons
    4.3.1 import
    4.3.2 export


【OK】两个数据库：
1.【OK】 Users information
2.【OK】 Entertainment data

}
