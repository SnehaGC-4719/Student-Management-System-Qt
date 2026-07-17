#ifndef DASHBOARD_H
#define DASHBOARD_H

#include <QMainWindow>
#include <QTimer>
namespace Ui {
class Dashboard;
}

class Dashboard : public QMainWindow
{
    Q_OBJECT

public:
    explicit Dashboard(QWidget *parent = nullptr);
    ~Dashboard();

private slots:
    void on_btnAdd_clicked();

    void on_btnSearch_clicked();

    void on_btnDelete_clicked();

    void on_btnView_clicked();

    void on_btnUpdate_clicked();

    void on_btnLogout_clicked();

    void updateDateTime();

private:
    Ui::Dashboard *ui;
    QTimer *timer;
};

#endif // DASHBOARD_H
