#include "deletestudent.h"
#include "ui_deletestudent.h"

#include <QMessageBox>
#include <QFile>
#include <QTextStream>
#include <QIcon>
DeleteStudent::DeleteStudent(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::DeleteStudent)
{
    ui->setupUi(this);
    setWindowIcon(QIcon(":/images/Images/Student.png"));
    setWindowTitle("Student Management System");

    ui->btnClose->setIcon(QIcon(":/images/Images/Back.png"));
    ui->btnDelete->setIcon(QIcon(":/images/Images/Delete.png"));
    ui->btnSearch->setIcon(QIcon(":/images/Images/Search.png"));
    ui->btnClear->setIcon(QIcon(":/images/Images/Clear.png"));
}

DeleteStudent::~DeleteStudent()
{
    delete ui;
}

void DeleteStudent::clearForm()
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


void DeleteStudent::on_btnSearch_clicked()
{
    QString studentID = ui->txtStudentID->text();

    if(studentID.isEmpty())
    {
        QMessageBox::warning(this,"Input Error","Please Enter Student ID.");
        ui->txtStudentID->setFocus();
        return;
    }

    QFile file("Student.txt");

    if(file.open(QIODevice::ReadOnly))
    {
        QTextStream in(&file);

        bool found = false;

        while(!in.atEnd())
        {
            QString line = in.readLine();

            if(line.trimmed().isEmpty())
            {
                continue;
            }

            QStringList data = line.split(",");

            if(data[0] == studentID)
            {
                found = true;

                ui->txtName->setText(data[1]);
                ui->txtAge->setText(data[2]);

                if(data[3] == "Male")
                    ui->rdoMale->setChecked(true);
                else
                    ui->rdoFemale->setChecked(true);

                ui->cmbDepartment->setCurrentText(data[4].trimmed());

                ui->txtPhone->setText(data[5]);
                ui->txtEmail->setText(data[6]);
                ui->txtAddress->setPlainText(data[7]);

                // Enable fields
                ui->txtName->setEnabled(true);
                ui->txtAge->setEnabled(true);
                ui->rdoMale->setEnabled(true);
                ui->rdoFemale->setEnabled(true);
                ui->cmbDepartment->setEnabled(true);
                ui->txtPhone->setEnabled(true);
                ui->txtEmail->setEnabled(true);
                ui->txtAddress->setEnabled(true);

                // Enable Delete button
                ui->btnDelete->setEnabled(true);

                break;
            }
        }

        file.close();

        if(!found)
        {
            QMessageBox::information(this,"Search","Student Not Found.");
            ui->txtStudentID->setFocus();
            clearForm();
        }
    }
    else
    {
        QMessageBox::warning(this,"File Error","Unable to open Student.txt");
    }
}

void DeleteStudent::on_btnDelete_clicked()
{
    QString studentID = ui->txtStudentID->text();

    QMessageBox::StandardButton reply;

    reply = QMessageBox::question(this,"Delete Student","Are You Sure You Want To Delete.",QMessageBox::Yes | QMessageBox::No);

    if(reply == QMessageBox::No)
    {
        return;
    }
    QFile inputFile("Student.txt");
    QFile tempFile("Temp.txt");

    if(inputFile.open(QIODevice::ReadOnly) &&
        tempFile.open(QIODevice::WriteOnly))
    {
        QTextStream in(&inputFile);
        QTextStream out(&tempFile);

        while(!in.atEnd())
        {
            QString line = in.readLine();

            if(line.trimmed().isEmpty())
            {
                continue;
            }

            QStringList data = line.split(",");

            if(data[0] == studentID)
            {
                continue;
            }
            else
            {
                out << line << "\n";
            }
        }

        inputFile.close();
        tempFile.close();

        QFile::remove("Student.txt");
        QFile::rename("Temp.txt","Student.txt");

        QMessageBox::information(this,
                                 "Success",
                                 "Student Deleted Successfully.");
       // clearForm();
        //close();
    }
    else
    {
        QMessageBox::warning(this,
                             "File Error",
                             "Unable to open file.");
    }
}

void DeleteStudent::on_btnClose_clicked()
{
    close();
}


void DeleteStudent::on_btnClear_clicked()
{
     clearForm();
}

