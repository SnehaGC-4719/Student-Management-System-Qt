#include "updatestudent.h"
#include "ui_updatestudent.h"
#include <QMessageBox>
#include <QFile>
#include <QTextStream>
#include <QIcon>
UpdateStudent::UpdateStudent(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::UpdateStudent)
{
    ui->setupUi(this);
    setWindowIcon(QIcon(":/images/Images/Student.png"));
    setWindowTitle("Student Management System");

    ui->btnSearch->setIcon(QIcon(":/images/Images/Search.png"));
    ui->btnClose->setIcon(QIcon(":/images/Images/Back.png"));
    ui->btnUpdate->setIcon(QIcon(":/images/Images/Update.png"));
    ui->btnClear->setIcon(QIcon(":/images/Images/Clear.png"));
}

UpdateStudent::~UpdateStudent()
{
    delete ui;
}

void UpdateStudent::clearForm()
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

void UpdateStudent::on_btnSearch_clicked()
{
    QString studentID = ui->txtStudentID->text();

    if(studentID.isEmpty()){
        QMessageBox::warning(this,"Input Error","Please Enter Student ID.");
        ui->txtStudentID->setFocus();
        return;
    }

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

            //Compare Enter Student ID With File Student ID
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

                //Enable All Fields For Editing
                ui->txtName->setEnabled(true);
                ui->txtAge->setEnabled(true);
                ui->rdoFemale->setEnabled(true);
                ui->rdoMale->setEnabled(true);
                ui->cmbDepartment->setEnabled(true);
                ui->txtPhone->setEnabled(true);
                ui->txtEmail->setEnabled(true);
                ui->txtAddress->setEnabled(true);

                //Enable update button
                ui->btnUpdate->setEnabled(true);

                break;
            }
        }

        file.close();

        //Student not found
        if(!found)
        {
            QMessageBox::information(this,"Search","Student Not Found.");

            ui->txtStudentID->setFocus();

            clearForm();
        }
    }
    else
    {
        QMessageBox::warning(this,"File Error","Unable to open student.txt.");
    }
}

void UpdateStudent::on_btnUpdate_clicked(){
    QString studentID = ui->txtStudentID->text();
    QString name = ui->txtName->text();
    QString age = ui->txtAge->text();

    QString gender;

    if(ui->rdoMale->isChecked())
    {
        gender = "Male";
    }
    else
    {
        gender = "Female";
    }

    QString department = ui->cmbDepartment->currentText();
    QString phone = ui->txtPhone->text();
    QString email = ui->txtEmail->text();
    QString address = ui->txtAddress->toPlainText();

    QFile inputFile("Student.txt");
    QFile tempFile("Temp.txt");

    if(inputFile.open(QIODevice::ReadOnly) && tempFile.open(QIODevice::WriteOnly))
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
                out << studentID << ","
                    << name << ","
                    << age << ","
                    << gender << ","
                    << department << ","
                    << phone << ","
                    << email << ","
                    << address << "\n";
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

        QMessageBox::information(this,"Success","Student Updated Successfully.");
        //clearForm();
    }
}
void UpdateStudent::on_btnClose_clicked()
{
    close();
}


void UpdateStudent::on_btnClear_clicked()
{
    clearForm();
}

