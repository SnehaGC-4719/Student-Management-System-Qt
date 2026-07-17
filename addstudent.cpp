#include "addstudent.h"
#include "ui_addstudent.h"
#include <QMessageBox>
#include <QFile>
#include <QTextStream>
#include <QIcon>
addStudent::addStudent(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::addStudent)
{
    ui->setupUi(this);
    setWindowIcon(QIcon(":/images/Images/Student.png"));
    setWindowTitle("Student Management System");

    ui->btnSave->setIcon(QIcon(":/images/Images/Save.png"));
    ui->btnClear->setIcon(QIcon(":/images/Images/Clear.png"));
    ui->btnBack->setIcon(QIcon(":/images/Images/Back.png"));
}
void addStudent::clearForm()
{
    ui->txtStundentId->clear();
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

    ui->txtStundentId->setFocus();
}

addStudent::~addStudent()
{
    delete ui;
}

void addStudent::on_btnSave_clicked()
{
    QString studentID = ui->txtStundentId->text();
    QString name = ui->txtName->text();
    QString age = ui->txtAge->text();
    QString phone = ui->txtPhone->text();
    QString email = ui->txtEmail->text();

    QString department = ui->cmbDepartment->currentText();

    QString address = ui->txtAddress->toPlainText();

    QString gender;

    if(ui->rdoMale->isChecked())
    {
        gender = "Male";
    }
    if(ui->rdoFemale->isChecked())
    {
        gender = "Female";
    }

    if(studentID.isEmpty())
    {
        QMessageBox::warning(this,"Input Error","Please Enter Student ID.");

        ui->txtStundentId->setFocus();
        return;
    }
    if(name.isEmpty())
    {
        QMessageBox::warning(this,"Input Error","Please Enter Name");
        ui->txtName->setFocus();
        return;
    }
    if(age.isEmpty()){
        QMessageBox::warning(this,"Input Error","Please Enter Age");
        ui->txtAge->setFocus();
        return;
    }
    if(phone.isEmpty())
    {
        QMessageBox::warning(this,"Input Error","Please Enter phone number");
        ui->txtPhone->setFocus();
        return;
    }
    if(email.isEmpty()){
        QMessageBox::warning(this,"Input Error","Please Enter email ID");
        ui->txtEmail->setFocus();
        return;
    }
    if(address.isEmpty()){
        QMessageBox::warning(this,"Input Error","Please Enter Address");
        ui->txtAddress->setFocus();
        return;
    }
    if(gender.isEmpty()){
        QMessageBox::warning(this,"Input Error","Please Enter Gender");
        return;
    }
    if(ui->cmbDepartment->currentIndex()==0)
    {
        QMessageBox::warning(this,"Input Error","Please Mark The Department");
        ui->cmbDepartment->setFocus();
        return;
    }
    bool ok;
    age.toInt(&ok);
    //int ageValue = age.toInt(&ok);

    if(!ok)
    {
        QMessageBox::warning(this,"Input Error","Age Must Be A Number.");
        ui->txtAge->setFocus();
        return;
    }
    if(phone.length() != 10)
    {
        QMessageBox::warning(this,"Input Error","Phone Number Must Contain Exactly 10 Digits.");
        ui->txtPhone->setFocus();
        return;
    }
    if(!email.contains("@"))
    {
        QMessageBox::warning(this,"Input Error","Invalid Email Address.");
        ui->txtEmail->setFocus();
        return;
    }

    QFile file("Student.txt");

    if(file.open(QIODevice::ReadOnly))
    {
        QTextStream in(&file);

        while(!in.atEnd())
        {
            QString line = in.readLine();

            QStringList data = line.split(",");

            if(data[0] == studentID && !data.isEmpty())
            {
                QMessageBox::warning(this,"Duplicate","Student ID Already Exists.");
                file.close();
                ui->txtStundentId->setFocus();
                return;
            }
        }
        file.close();
    }

    QMessageBox::information(this,"Student",
                             studentID+"\n"+
                                 name+"\n"+
                                 age+"\n"+
                                 gender+"\n"+
                                 department+"\n"+
                                 phone+"\n"+
                                 email+"\n"+
                                 address);

    if(file.open(QIODevice::Append))
    {
        //QMessageBox::information(this,"Success","File Opened Successfully");
        QTextStream out(&file);

        out << studentID << ","
            << name << ","
            << age << ","
            << gender << ","
            << department << ","
            << phone << ","
            << email << ","
            << address << "\n";

        file.close();
        QMessageBox::information(this,"Success","Stuedent Saved Successfully");
        clearForm();
    }
    else
    {
        QMessageBox::warning(this,"Error","File Cannot Be Opened");
    }
}


void addStudent::on_btnClear_clicked()
{
    clearForm();
}


void addStudent::on_btnBack_clicked()
{
    close();
}
