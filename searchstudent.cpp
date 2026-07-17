#include "searchstudent.h"
#include "ui_searchstudent.h"
#include <QMessageBox>
#include <QFile>
#include <QTextStream>
#include <QIcon>
searchstudent::searchstudent(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::searchstudent)
{
    ui->setupUi(this);
    setWindowIcon(QIcon(":/images/Images/Student.png"));
    setWindowTitle("Student Management System");

    ui->btnSearch->setIcon(QIcon(":/images/Images/Search.png"));
}

searchstudent::~searchstudent()
{
    delete ui;
}

void searchstudent::clearform()
{
    ui->txtStudentID->clear();
    ui->txtName->clear();
    ui->txtAge->clear();
    ui->txtPhone->clear();
    ui->txtEmail->clear();
    ui->txtAddress->clear();

    ui->rdoFemale->setAutoExclusive(false);
    ui->rdoMale->setAutoExclusive(false);
    ui->rdoFemale->setChecked(false);
    ui->rdoMale->setChecked(false);
    ui->rdoFemale->setAutoExclusive(true);
    ui->rdoMale->setAutoExclusive(true);

    ui->cmbDepartment->setCurrentIndex(0);

    ui->txtStudentID->setFocus();
}


void searchstudent::on_btnSearch_clicked()
{
    //Read Student ID Entered By The User
    QString studentID = ui->txtStudentID->text();

    //Check If Student ID Is Empty
    if(studentID.isEmpty())
    {
        QMessageBox::warning(this,"Input Error","Please Enter Student ID.");
        ui->txtStudentID->setFocus();
        return;
    }

    //Open Student.txt File
    QFile file("Student.txt");

    if(file.open(QIODevice::ReadOnly))
    {
        QTextStream in(&file);
        bool found = false;

        //Read File Line By Line
        while(!in.atEnd())
        {
            QString line = in.readLine();

            //skip empty lines
            if(line.trimmed().isEmpty())
            {
                continue;
            }

            //Split Line Into Fields
            QStringList data = line.split(",");

            //Compare Entere Student ID With File Student ID
            if(data[0] == studentID)
            {
                found = true;

                //Display data
                ui->txtName->setText(data[1]);
                ui->txtAge->setText(data[2]);

                if(data[3] == "Male")
                    ui->rdoMale->setChecked(true);
                else
                    ui->rdoFemale->setChecked(true);

                ui->cmbDepartment->setCurrentText(data[4]);

                ui->txtPhone->setText(data[5]);
                ui->txtEmail->setText(data[6]);
                ui->txtAddress->setPlainText(data[7]);

                break;
            }
        }

        file.close();

        //Student not found
        if(!found)
        {
            QMessageBox::information(this,"Search","Student Not Found.");

            ui->txtStudentID->setFocus();

            clearform();
        }
    }
    else
    {
        QMessageBox::warning(this,"File Error","Unable to open student.txt.");
    }

}

