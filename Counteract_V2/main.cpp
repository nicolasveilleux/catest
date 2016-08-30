#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QApplication>
#include <QtSql/qsqldatabase.h>
#include <QtSql/qsqlquery.h>
#include <QtDebug>
#include <QtSql/qsqlquerymodel.h>
#include "global.h"
#include <qtabwidget.h>




int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();




    return a.exec();
}
