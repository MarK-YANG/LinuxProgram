#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <aboutdlg.h>
#include <QWidget>
#include <vector>
#include "CFileNode.h"

using namespace std;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    AboutDlg about;

    //temp valuable
    vector<CFileNode*> result;//file dir
    vector<string> currentPath;//store current path

    //store filenode
    vector<CFileNode*> allFiles;

    vector<CFileNode*> makeAllFileDir(char *dir);
    void InitSearchWidget();
    ~MainWindow();


private slots:
    void on_action_A_triggered();

    void on_action_S_triggered();

    void on_pushButton_2_clicked();

    void on_showSideBar_triggered();

    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;

    };

#endif // MAINWINDOW_H
