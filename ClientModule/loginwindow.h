//  CLASSE LoginWindow - v0.1.3a
#ifndef LOGINWINDOW_H
#define LOGINWINDOW_H
#include <QMainWindow>
#include <QtGui>            //QPoint
#include <QtSql>            //SQL
#include <QSqlDatabase>     //SQL
#include "versioninfo.h"    //Needed to show the current version of the software
#include "regwindow.h"      //For switching to the registration window
#include "startmenu.h"      //For switching to the startmenu window
#include "myClient.h"
#include <deque>
#include "json.hpp"
#include "jsonUtility.h"
#include <boost/asio.hpp>

QT_BEGIN_NAMESPACE
namespace Ui { class LoginWindow; }
QT_END_NAMESPACE

//Class LoginWindow --> This class show a bordless window used to allow the user to log in
class LoginWindow : public QMainWindow{
    Q_OBJECT

public:
    LoginWindow(QWidget *parent = nullptr); //Constructor
    ~LoginWindow();                         //Destructor

private slots:
    void on_exitButton_clicked();
    void on_ForgotPasswordButton_clicked();
    void on_LoginButton_clicked();
    void on_RegistratiButton_clicked();
    void on_LoginAdmin_clicked();

public slots:
    void setStatus(bool newStatus);
    void showFormPopup(QString result, QString title, QString msg);

private:
    Ui::LoginWindow *ui;                    //"ui" (user interface)
    QSqlDatabase db;
    //For mouse related event
    QPoint oldPos;                          //This "oldPos" object is used to save the old position of the windows for the translation of windows
    VersionInfo v1;
    QString qstr = v1.getVersion();
    myClient *client;

protected:
    //Function for mouse related event
    void mousePressEvent(QMouseEvent *evt);
    void mouseMoveEvent(QMouseEvent *evt);

};
#endif // LOGINWINDOW_H
