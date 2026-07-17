#include "dashboard.h"
#include "ui_dashboard.h"

#include "addstudent.h"
#include "searchstudent.h"
#include "deletestudent.h"
#include "updatestudent.h"
#include "viewstudents.h"
#include "login.h"
#include <QTimer>
#include <QDateTime>
#include <QIcon>

#include <QPixmap>
Dashboard::Dashboard(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Dashboard)
{
    ui->setupUi(this);
    setWindowTitle("Student Management System - Dashboard");

    QPixmap pix(":/images/Images/Edu.png");
    ui->label_2->setPixmap(pix.scaled(ui->label_2->size(),
                                    Qt::KeepAspectRatio,
                                    Qt::SmoothTransformation));

    timer = new QTimer(this);

    connect(timer, &QTimer::timeout,
            this, &Dashboard::updateDateTime);

    timer->start(1000);

    updateDateTime();

    ui->btnAdd->setIcon(QIcon(":/images/Images/Add.png"));
    ui->btnAdd->setIconSize(QSize(32,32));

    ui->btnSearch->setIcon(QIcon(":/images/Images/Search.png"));
    ui->btnSearch->setIconSize(QSize(32,32));

    ui->btnDelete->setIcon(QIcon(":/images/Images/Delete.png"));
    ui->btnDelete->setIconSize(QSize(32,32));

    ui->btnUpdate->setIcon(QIcon(":/images/Images/Update.png"));
    ui->btnUpdate->setIconSize(QSize(32,32));

    ui->btnView->setIcon(QIcon(":/images/Images/View.png"));
    ui->btnView->setIconSize(QSize(32,32));

    ui->btnLogout->setIcon(QIcon(":/images/Images/Logout.png"));
    ui->btnLogout->setIconSize(QSize(32,32));
}
Dashboard::~Dashboard()
{
    delete ui;
}

void Dashboard::on_btnAdd_clicked()
{
    addStudent *add = new addStudent();
    add->show();
}

void Dashboard::on_btnSearch_clicked()
{
    searchstudent *search = new searchstudent();
    search->show();
}

void Dashboard::on_btnDelete_clicked()
{
    DeleteStudent *dlt = new DeleteStudent();
    dlt->show();
}

void Dashboard::on_btnView_clicked()
{
    ViewStudents *view = new ViewStudents();
    view->show();
}

void Dashboard::on_btnUpdate_clicked()
{
    UpdateStudent *update = new UpdateStudent();
    update->show();
}

void Dashboard::on_btnLogout_clicked()
{
    Login *login = new Login();
    login->show();
    this->close();
}

void Dashboard::updateDateTime()
{
    ui->label_4->setText(
        QDateTime::currentDateTime().toString("dddd | dd MMM yyyy | hh:mm:ss AP"));
}
