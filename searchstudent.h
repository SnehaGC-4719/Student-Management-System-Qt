#ifndef SEARCHSTUDENT_H
#define SEARCHSTUDENT_H

#include <QWidget>

namespace Ui {
class searchstudent;
}

class searchstudent : public QWidget
{
    Q_OBJECT

public:
    explicit searchstudent(QWidget *parent = nullptr);
    ~searchstudent();

private slots:
    void on_btnSearch_clicked();

private:
    Ui::searchstudent *ui;
    void clearform();
};

#endif // SEARCHSTUDENT_H
