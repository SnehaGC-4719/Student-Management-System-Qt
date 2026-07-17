#include "login.h"
#include "ui_login.h"
#include "dashboard.h"
#include <QMessageBox>
#include <QIcon>
Login::Login(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Login)
{
    ui->setupUi(this);
    setWindowIcon(QIcon(":/images/Images/Student.png"));
    setWindowTitle("Student Management System");

    ui->btnLogin->setIcon(QIcon(":/images/Images/Login.png"));
    ui->btnExit->setIcon(QIcon(":/images/Images/Exit.png"));
}

Login::~Login()
{
    delete ui;
}

void Login::on_btnLogin_clicked()
{
    QString username = ui->txtUsername->text();
    QString password = ui->txtPassword->text();

    if(username == "admin" && password == "1234")
    {
        Dashboard *dashboard = new Dashboard;
        dashboard->show();

        close();
    }
    else
    {
        QMessageBox::warning(this,"Login failed","Invalid Username or Password.");

        ui->txtPassword->clear();
        ui->txtPassword->setFocus();
    }
}


void Login::on_btnExit_clicked()
{
    close();
}

