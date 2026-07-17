#ifndef VIEWSTUDENTS_H
#define VIEWSTUDENTS_H

#include <QWidget>

namespace Ui {
class ViewStudents;
}

class ViewStudents : public QWidget
{
    Q_OBJECT

public:
    explicit ViewStudents(QWidget *parent = nullptr);
    ~ViewStudents();

private slots:
    void on_btnClose_clicked();

    void on_btnRefresh_clicked();

private:
    Ui::ViewStudents *ui;
    void loadStudents();
};

#endif // VIEWSTUDENTS_H
