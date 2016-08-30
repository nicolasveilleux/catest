#include "rejet.h"
#include "ui_rejet.h"
#include "global.h"

Rejet::Rejet(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Rejet)
{
    ui->setupUi(this);
    showFullScreen();
}

Rejet::~Rejet()
{
    delete ui;
}




void Rejet::on_pushButton_11_clicked()
{
    this->close();
}


void Rejet::on_pushButton_clicked()
{
   isFullScreen() ? showNormal() : showFullScreen();
}

void Rejet::on_pushButton_14_clicked()
{

}

void Rejet::on_pushButton_12_clicked()
{

}

void Rejet::on_pushButton_13_clicked()
{

}
