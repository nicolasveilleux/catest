#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QApplication>
#include <QtSql/qsqldatabase.h>
#include <QtSql/qsqlquery.h>
#include <QtDebug>
#include <QtSql/qsqlquerymodel.h>
#include "wo.h"
#include "rejet.h"
#include "global.h"
#include <qtabwidget.h>




int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("counteract.ddns.net");
    db.setDatabaseName("counteract");
    db.setUserName("root");
    db.setPassword("password1");

     db.open();
     if(db.open()){
         qDebug() << "Database Connection Opened!";
     }


    return a.exec();
}
