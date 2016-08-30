#include "wo.h"
#include "ui_wo.h"
#include <QtDebug>
#include <QTime>
#include <QtSql/qsqlquerymodel.h>
#include <QtSql/qsqldatabase.h>
#include <QtSql/qsqlquery.h>
#include "global.h"

QString WOString2;
int PartCount2;


WO::WO(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::WO)
{
    ui->setupUi(this);
    showFullScreen();
}

WO::~WO()
{
    delete ui;
}

void WO::on_pushButton_clicked()
{
    isFullScreen() ? showNormal() : showFullScreen();
}


void WO::on_pushButton_8_clicked()
{
    this->close();
}



void WO::on_listView_clicked(const QModelIndex &index)
{
    WOString2.clear();
    WOString2.append(ui->listView->currentIndex().data().toString());
    Global::Instance()->setmystring(WOString2);

}

void WO::on_pushButton_3_clicked()
{
    QSqlQueryModel *WorkOrderList = new QSqlQueryModel;
     WorkOrderList->setQuery("SELECT `WorkOrder#` FROM `work_order_data`");

      ui->listView->setModel(WorkOrderList);


}

void WO::on_pushButton_5_clicked()
{
    PartCount2 = 0;
    int iterationqty;
    QSqlQuery GetNumPartMade;
    QSqlQuery GetNumPartScrap;
    QSqlQuery QtyPartToDo;

    GetNumPartMade.prepare("SELECT Iteration FROM `production_data` WHERE `WorkOrder#` = \""+WOString2+"\" AND `Iteration Type` = \"Part Made\"");
    GetNumPartMade.exec();
     qDebug()<< "Query Sent" << GetNumPartMade.lastQuery();
    while(GetNumPartMade.next())
    {
    iterationqty = GetNumPartMade.value(0).toInt();
    PartCount2 = PartCount2 + iterationqty;
    }
    GetNumPartScrap.prepare("SELECT Iteration FROM `production_data` WHERE `WorkOrder#` = \""+WOString2+"\" AND `Iteration Type` = \"Scrap\"");
    GetNumPartScrap.exec();
     qDebug()<< "Query Sent" << GetNumPartScrap.lastQuery();
    while(GetNumPartScrap.next())
    {
    iterationqty = GetNumPartScrap.value(0).toInt();
    PartCount2 = PartCount2 - iterationqty;
    }


    QtyPartToDo.prepare("SELECT `Qty Cycle` FROM `work_order_data` WHERE `WorkOrder#` = \""+WOString2+"\"");
    QtyPartToDo.exec();
        qDebug()<< "Query Sent" << QtyPartToDo.lastQuery();
    QtyPartToDo.next();
  //  ui->lcdNumber_3->display(QtyPartToDo.value(0).toInt());
   // ui->lcdNumber_2->display(PartCount);
}
