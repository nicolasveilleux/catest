#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "wo.h"
#include "rejet.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_pushButton_pressed();

    void on_pushButton_3_pressed();

    void on_pushButton_2_pressed();

    void on_pushButton_4_pressed();

    void on_pushButton_5_pressed();

    void on_listView_clicked(const QModelIndex &index);

    void on_pushButton_6_clicked();

    void on_pushButton_7_clicked();

private:
    Ui::MainWindow *ui;
    WO *wo;
    Rejet *rejet;
};

#endif // MAINWINDOW_H
