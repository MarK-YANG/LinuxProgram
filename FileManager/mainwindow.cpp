#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QGridLayout>
#include <QLabel>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    about.setWindowTitle("关于File Manager");
    ui->searchWidget->hide();
    ui->leftWidget->hide();

}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_action_A_triggered()//show the about dialog
{
    about.show();
}

void MainWindow::on_action_S_triggered()
{
    ui->searchWidget->show();
    ui->curLabel->hide();

}


void MainWindow::on_pushButton_2_clicked()
{
    ui->searchWidget->hide();
    ui->curLabel->show();
}

void MainWindow::on_showSideBar_triggered()
{
    if(!ui->showSideBar->isChecked())
    {
        ui->leftWidget->close();
    }else
    {
        ui->leftWidget->show();
    }
}
