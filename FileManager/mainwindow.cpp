#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QGridLayout>
#include <QLabel>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#include <sys/stat.h>
#include "CFileNode.h"

using namespace std;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    about.setWindowTitle("关于File Manager");
    ui->searchWidget->hide();
    ui->leftWidget->hide();
    allFiles = makeAllFileDir("/home");

}

MainWindow::~MainWindow()
{
    delete ui;
}

vector<CFileNode*> MainWindow::makeAllFileDir(char *dir)
{
    DIR *dp;
    struct dirent *entry;
    struct stat statbuf;
    if((dp = opendir(dir)) == NULL)
    {
        result.clear();
        return result;
    }

    chdir(dir);
    string strPath = dir;
    strPath = strPath + "/";
    currentPath.push_back(strPath);

    while((entry = readdir(dp)) != NULL)
    {
        lstat(entry->d_name,&statbuf);

        //hiden files & folder will not display
        if (!strncasecmp(entry->d_name, ".", 1)) {
            continue;
        }

        if(S_ISDIR(statbuf.st_mode))  //Is folder
        {


            if(strcmp(".",entry->d_name) == 0 || strcmp("..",entry->d_name) == 0)
            {
                continue;
            }



            CFileNode* node = new CFileNode();
            node->setNodeName(entry->d_name);
            string strPath;
            for (int i = 0; i < currentPath.size(); ++i)
            {
                strPath += currentPath[i];
            }
            node->setNodePath(strPath);
            node->setNodeType(2);
            result.push_back(node);

            makeAllFileDir(entry->d_name);


        }
        else    //Is file
        {
            CFileNode* node = new CFileNode();
            node->setNodeName(entry->d_name);
            string strPath;
            for (int i = 0; i < currentPath.size(); ++i)
            {
                strPath += currentPath[i];
            }
            node->setNodePath(strPath);
            node->setNodeType(0);
            result.push_back(node);
        }
    }

    currentPath.pop_back();
    chdir("..");
    closedir(dp);

    return result;
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



void MainWindow::on_pushButton_clicked()
{
   string outPut ="";
   string searchWord = ui->lineEdit_2->text().toStdString();

   if(searchWord == "")
   {
       ui->outPutListWidget->clear();
       /*for(int i = 0; i < result.size(); ++i)
       {
            outPut = result[i]->getNodeName()+"\t\t"+result[i]->getNodePath();
            ui->outPutListWidget->addItem((QString(QString::fromLocal8Bit(outPut.c_str()))));
       }*/
       outPut = "Please input a keyword :)";
       ui->outPutListWidget->addItem((QString(QString::fromLocal8Bit(outPut.c_str()))));
   }
   else
   {
       ui->outPutListWidget->clear();

       for(int i = 0; i < result.size(); ++i)
       {
           if(result[i]->containKeyWord(searchWord))
           {
                outPut = result[i]->getNodeName()+"\t"+result[i]->getNodePath();
                ui->outPutListWidget->addItem((QString(QString::fromLocal8Bit(outPut.c_str()))));
           }
       }
   }

   if(ui->outPutListWidget->count() == 0)
   {
       outPut = "No result :(";
       ui->outPutListWidget->addItem((QString(QString::fromLocal8Bit(outPut.c_str()))));
   }
   //ui->lOutput->setText(QString(QString::fromLocal8Bit(outPut.c_str())));
}


void MainWindow::on_outPutListWidget_itemDoubleClicked(QListWidgetItem *item)
{

    string text = item->text().toStdString();
    if(text.find('\t') == text.npos)
    {
        return;
    }
    else
    {
        int iConsor = text.find('\t');
        string sName = text.substr(0,iConsor);
        string sPath = text.substr(iConsor+1, text.length());

        string command = "nautilus " + sPath + sName;

        system(command.c_str());
    }

    //result[iNum]-> openCurrent();
}
