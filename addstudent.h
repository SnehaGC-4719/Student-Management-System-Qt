#ifndef ADDSTUDENT_H
#define ADDSTUDENT_H

#include <QWidget>

namespace Ui {
class addStudent;
}

class addStudent : public QWidget
{
    Q_OBJECT

public:
    explicit addStudent(QWidget *parent = nullptr);
    ~addStudent();

private slots:
    void on_btnSave_clicked();

    void on_btnClear_clicked();

    void on_btnBack_clicked();

private:
    Ui::addStudent *ui;
    void clearForm();
};

#endif // ADDSTUDENT_H
