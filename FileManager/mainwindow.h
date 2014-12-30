#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <aboutdlg.h>
#include <QWidget>


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    AboutDlg about;
    void InitSearchWidget();
    ~MainWindow();


private slots:
    void on_action_A_triggered();

    void on_action_S_triggered();

    void on_pushButton_2_clicked();

    void on_showSideBar_triggered();

private:
    Ui::MainWindow *ui;

    };

#endif // MAINWINDOW_H
