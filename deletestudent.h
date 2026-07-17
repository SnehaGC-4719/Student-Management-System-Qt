#ifndef DELETESTUDENT_H
#define DELETESTUDENT_H

#include <QWidget>

namespace Ui {
class DeleteStudent;
}

class DeleteStudent : public QWidget
{
    Q_OBJECT

public:
    explicit DeleteStudent(QWidget *parent = nullptr);
    ~DeleteStudent();

private slots:
    void on_btnSearch_clicked();
    void on_btnDelete_clicked();
    void on_btnClose_clicked();

    void on_btnClear_clicked();

private:
    Ui::DeleteStudent *ui;
    void clearForm();
};

#endif // DELETESTUDENT_H
