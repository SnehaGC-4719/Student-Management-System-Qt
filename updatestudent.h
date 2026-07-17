#ifndef UPDATESTUDENT_H
#define UPDATESTUDENT_H

#include <QWidget>

namespace Ui {
class UpdateStudent;
}

class UpdateStudent : public QWidget
{
    Q_OBJECT

public:
    explicit UpdateStudent(QWidget *parent = nullptr);
    ~UpdateStudent();

private slots:
    void on_btnSearch_clicked();
    void on_btnUpdate_clicked();
    void on_btnClose_clicked();

    void on_btnClear_clicked();

private:
    Ui::UpdateStudent *ui;
     void clearForm();
};

#endif // UPDATESTUDENT_H
