#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui
{
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_pushButtonInsert_clicked();

    void on_pushButtonDelete_clicked();

    void on_pushButtonSearch_clicked();

    void on_pushButtonUpdate_clicked();

    void on_action_Exit_triggered();

    void on_action_FileOut_triggered();

    void on_asc_sort_byScore_clicked();

    void on_desc_sort_byScore_clicked();

    void on_asc_sort_byNum_clicked();

    void on_desc_sort_byNum_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
