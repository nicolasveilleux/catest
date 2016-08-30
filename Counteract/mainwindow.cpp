#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtSql/qsqldatabase.h>
#include <QtSql/qsqlquery.h>
#include <QtDebug>
#include <QTime>
#include <QtSql/qsqlquerymodel.h>
#include "global.h"

QTime myTimer;
int PartCount;
QString WOString;


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->lcdNumber_2->display(0);
    showFullScreen();


}

MainWindow::~MainWindow()
{
    delete ui;

}

void MainWindow::on_pushButton_pressed()
{
    double temps;
    if(myTimer.elapsed()==0)
    {
        myTimer.start();
    }
    temps = myTimer.elapsed()/1000.00;
    ui->lcdNumber->display(temps);
    myTimer.restart();
    QSqlQuery AddNewPart;
    AddNewPart.prepare("INSERT INTO `production_data` (`Controller#`, `WorkOrder#`, `CycleTime`, `Iteration`) VALUES ('A8404115C1C4', :WO, :ct, '1')");
    AddNewPart.bindValue(":ct",temps);
    AddNewPart.bindValue(":WO",WOString);

    if (temps != 0)
    {
       bool reussi = AddNewPart.exec();
        if(!reussi)
            {
            qDebug()<< "Query Error";
            }
        else
        {
            qDebug() <<"Query AddNewPart Successfull";
            PartCount+=1;
            ui->lcdNumber_2->display(PartCount);
        }
    }

}



void MainWindow::on_pushButton_3_pressed()
{

  QSqlQueryModel *WorkOrderList = new QSqlQueryModel;
   WorkOrderList->setQuery("SELECT `WorkOrder#` FROM `work_order_data`");

    ui->listView->setModel(WorkOrderList);

    QSqlQueryModel *ScrapReasonList = new QSqlQueryModel;
     ScrapReasonList->setQuery("SELECT `Reason` FROM `ScrapReason` WHERE `Enabled` = 1");

      ui->listView_2->setModel(ScrapReasonList);

        ui->label->setText(Global::Instance()->getmystring());


}

void MainWindow::on_pushButton_2_pressed()
{
    int reasonid;
    QSqlQuery RemovePartReasonID;
    QSqlQuery RemovePart;
    QString ReasonString;


    ReasonString.append(ui->listView_2->currentIndex().data().toString());
    RemovePartReasonID.prepare("SELECT ID FROM `scrapreason` WHERE Reason = \""+ReasonString+"\"");
    RemovePartReasonID.exec();
     qDebug()<< "Query Error" << RemovePartReasonID.lastQuery();
    RemovePartReasonID.next();
    reasonid = RemovePartReasonID.value(0).toInt();
    RemovePart.prepare("INSERT INTO `production_data` (`Controller#`, `WorkOrder#`, `CycleTime`,`Iteration Type`, `Iteration`, `ScrapReasonID`) VALUES ('A8404115C1C4', :WO, 0, 'Scrap', :nbscrap, :reasonid)");
    RemovePart.bindValue(":nbscrap",ui->spinBox->value());
    RemovePart.bindValue(":reasonid",reasonid);
    RemovePart.bindValue(":WO",WOString);

    if(ui->spinBox->value() != 0 && reasonid != 0)
    {

        bool reussi = RemovePart.exec();
        if(!reussi)
            {
            qDebug()<< "Query Error";
            }
        else
        {
            qDebug() <<"Query ScrapPart Successfull";
            PartCount= PartCount - ui->spinBox->value();
            ui->spinBox->setValue(0);
            ui->lcdNumber_2->display(PartCount);
        }
    }

}

void MainWindow::on_pushButton_4_pressed()
{
   isFullScreen() ? showNormal() : showFullScreen();
}

void MainWindow::on_pushButton_5_pressed()
{
    PartCount = 0;
    int iterationqty;
    QSqlQuery GetNumPartMade;
    QSqlQuery GetNumPartScrap;
    QSqlQuery QtyPartToDo;

    GetNumPartMade.prepare("SELECT Iteration FROM `production_data` WHERE `WorkOrder#` = \""+WOString+"\" AND `Iteration Type` = \"Part Made\"");
    GetNumPartMade.exec();
     qDebug()<< "Query Sent" << GetNumPartMade.lastQuery();
    while(GetNumPartMade.next())
    {
    iterationqty = GetNumPartMade.value(0).toInt();
    PartCount = PartCount + iterationqty;
    }
    GetNumPartScrap.prepare("SELECT Iteration FROM `production_data` WHERE `WorkOrder#` = \""+WOString+"\" AND `Iteration Type` = \"Scrap\"");
    GetNumPartScrap.exec();
     qDebug()<< "Query Sent" << GetNumPartScrap.lastQuery();
    while(GetNumPartScrap.next())
    {
    iterationqty = GetNumPartScrap.value(0).toInt();
    PartCount = PartCount - iterationqty;
    }


    QtyPartToDo.prepare("SELECT `Qty Cycle` FROM `work_order_data` WHERE `WorkOrder#` = \""+WOString+"\"");
    QtyPartToDo.exec();
        qDebug()<< "Query Sent" << QtyPartToDo.lastQuery();
    QtyPartToDo.next();
    ui->lcdNumber_3->display(QtyPartToDo.value(0).toInt());
    ui->lcdNumber_2->display(PartCount);


}

void MainWindow::on_listView_clicked(const QModelIndex &index)
{
    WOString.clear();
    WOString.append(ui->listView->currentIndex().data().toString());
}

void MainWindow::on_pushButton_6_clicked()
{
       wo = new WO(this);
       wo->show();
}


void MainWindow::on_pushButton_7_clicked()
{
    rejet = new Rejet(this);
    rejet->show();
}
