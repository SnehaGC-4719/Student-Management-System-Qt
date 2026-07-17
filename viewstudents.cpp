#include "viewstudents.h"
#include "ui_viewstudents.h"
#include <QFile>
#include <QTextStream>
#include <QHeaderView>
#include <QAbstractItemView>
ViewStudents::ViewStudents(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::ViewStudents)
{
    ui->setupUi(this);
    setWindowIcon(QIcon(":/images/Images/Student.png"));
    setWindowTitle("Student Management System");

    ui->btnRefresh->setIcon(QIcon(":/images/Images/Refresh.png"));
    ui->btnClose->setIcon(QIcon(":/images/Images/Clear.png"));

    ui->tableWidget->setColumnCount(8);

    QStringList headers;

    headers <<"Student ID"
            << "Name"
            << "Age"
            << "Gender"
            << "Department"
            << "Phone"
            << "Email"
            << "Address";

    ui->tableWidget->setHorizontalHeaderLabels(headers);

    ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableWidget->setAlternatingRowColors(true);
    ui->tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableWidget->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableWidget->verticalHeader()->setVisible(false);

    loadStudents();
}

ViewStudents::~ViewStudents()
{
    delete ui;
}

void ViewStudents::loadStudents()
{
    //Clear Old Data Before Loading Again
    ui->tableWidget->setRowCount(0);

    //open file
    QFile file("Student.txt");

    if(file.open(QIODevice::ReadOnly))
    {
        QTextStream in(&file);

        int row = 0;

        while(!in.atEnd())
        {
            QString line = in.readLine();

            if(line.trimmed().isEmpty())
            {
                continue;
            }

            QStringList data = line.split(",");

            //create one empty row
            ui->tableWidget->insertRow(row);

            //Fill that row with data
            for(int col = 0; col < data.size(); col++)
            {
                ui->tableWidget->setItem(row,col,new QTableWidgetItem(data[col]));
            }
            row++;

        }
        file.close();
    }
}

void ViewStudents::on_btnClose_clicked()
{
    close();
}

void ViewStudents::on_btnRefresh_clicked()
{
    loadStudents();
}

