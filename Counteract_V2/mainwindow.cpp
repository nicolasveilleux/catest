#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtSql/qsqldatabase.h>
#include <QtSql/qsqlquery.h>
#include <QtDebug>
#include <QTime>
#include <QTimer>
#include <QDate>
#include <QtSql/qsqlquerymodel.h>
#include "global.h"
#include <QProcess>
#include <QtNetwork/QNetworkInterface>

QTime myTimer;
int PartCount;
QString WOString;

QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    int dbConnected;

    db.setHostName("counteract.ddns.net");
    db.setDatabaseName("counteract");
    db.setUserName("root");
    db.setPassword("password1");
    dbConnected =  db.open();
    if(dbConnected){
        qDebug() << "Database Connection Opened!";
    }

    QTimer *Timer = new QTimer(this);
    connect(Timer,SIGNAL(timeout()),this,SLOT(update()));
    Timer->start(1000);
    QTime clock = QTime :: currentTime();
    QString CurrentTime;
    CurrentTime = clock.toString();
    ui->setupUi(this);
    ui->lcdNumber_2->display(0);
    ui->tabWidget->setStyle(new CustomTabStyle);
    //QApplication::setOverrideCursor(Qt::BlankCursor);
    QString MACString;
    QNetworkInterface *Network = new QNetworkInterface;
    foreach(QNetworkInterface interface,Network->allInterfaces())
    {
         MACString = interface.humanReadableName();
         if(MACString == "wlan0")
            {
                MACString = interface.hardwareAddress();
                qDebug()<< "MAC:" << MACString;
            }



    }


    showFullScreen();



}

MainWindow::~MainWindow()
{
    delete ui;

}

void MainWindow :: update(){

    if(db.isOpen()){
        ui->label_10->setVisible(1);
        ui->label_9->setVisible(0);

    }
    else{
        ui->label_10->setVisible(0);
        ui->label_9->setVisible(1);
        db.open();
    }

    int wifiStatus = QProcess::execute("ping",QStringList() << "-c 1" << "www.google.com");
    if(wifiStatus == 0){
        ui->label_8->setVisible(1);
        ui->label_5->setVisible(0);

    }
    else{
        ui->label_8->setVisible(0);
        ui->label_5->setVisible(1);
    }
    QTime clock = QTime :: currentTime();
    QString CurrentTime;
    CurrentTime = clock.toString();
    ui->label_2->setText(QDateTime::currentDateTime().toString());


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



void MainWindow::on_tabWidget_tabBarClicked(int index)
{
    if(index == 1){
    QSqlQueryModel *WorkOrderList = new QSqlQueryModel;
     WorkOrderList->setQuery("SELECT `WorkOrder#` FROM `work_order_data`");

      ui->listView->setModel(WorkOrderList);
      qDebug() <<"WO Update succes";
    }
    if(index == 2){
        QSqlQueryModel *ScrapReasonList = new QSqlQueryModel;
         ScrapReasonList->setQuery("SELECT `Reason` FROM `ScrapReason` WHERE `Enabled` = 1");

          ui->listView_2->setModel(ScrapReasonList);

          qDebug() <<"Rejet Update succes";
    }
}

void MainWindow::on_pushButton_3_clicked()
{
    close();
}

void event(QEvent *event)
{

    if (event->type() == event->RequestSoftwareInputPanel)
    {
       qDebug() <<"CLAVIER";
       event->accept();
    }
}
