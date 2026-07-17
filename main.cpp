#include "mainwindow.h"
//#include"viewstudents.h"
//#include"searchstudent.h"
#include <QApplication>
//#include "updatestudent.h"
#include <QFile>
#include <QTextStream>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    //ViewStudents w;
    //searchstudent w;
    //UpdateStudent w;

    QFile file("style.qss");

    if(file.open(QFile::ReadOnly))
    {
        QString style = file.readAll();
        a.setStyleSheet(style);
    }
    w.show();
    return QApplication::exec();
}
