#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "dashboard.h"
#include<QMessageBox>
#include <QIcon>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowIcon(QIcon(":/images/Images/Student.png"));
    setWindowTitle("Student Management System");
    QPixmap pix(":/images/Images/Logo.png");
    ui->label->setPixmap(
        pix.scaled(180,180,
                   Qt::KeepAspectRatio,
                   Qt::SmoothTransformation));
    ui->txtPassword->setEchoMode(QLineEdit::Password);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_chkShowPassword_toggled(bool Checked)     //CheckBox
{
    if(Checked)
        ui->txtPassword->setEchoMode(QLineEdit::Normal);
    else
        ui->txtPassword->setEchoMode(QLineEdit::Password);
}

void MainWindow::on_btnLogin_clicked()
{
    QString username = ui->txtUsername->text();
    QString password = ui->txtPassword->text();

    if(username=="admin" && password == "1234")
    {
        //QMessageBox::information(this,"Login","Login Successful");
        Dashboard *dashboard = new Dashboard();
        dashboard->show();
        this->hide();
    }
    else
    {
        QMessageBox::warning(this,"Login","Invalid Username or Password");
    }
}

void MainWindow::on_chkShowPassword_clicked()
{
    if(ui->chkShowPassword->isChecked())
    {
        ui->txtPassword->setEchoMode(QLineEdit::Normal);
    }
    else
    {
        ui->txtPassword->setEchoMode(QLineEdit::Password);
    }
}

void MainWindow::on_btnReset_clicked()
{
    ui->txtUsername->clear();
    ui->txtPassword->clear();

    ui->chkShowPassword->setChecked(false);

    ui->txtPassword->setEchoMode(QLineEdit::Password);

    ui->txtUsername->setFocus();  //This places the cursor back into the Username field.
                                  //Instead of clicking with the mouse, the user can immediately start typing.
                                  //This is a small touch that makes the application feel more professional.
}


void MainWindow::on_btnExit_clicked()
{
    QMessageBox::StandardButton reply;

    reply = QMessageBox::question(this,"Exit","Are you sure you want to exit?",QMessageBox::Yes|QMessageBox::No);

    if(reply == QMessageBox::Yes)
        close();
}

