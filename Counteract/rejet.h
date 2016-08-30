#ifndef REJET_H
#define REJET_H

#include <QMainWindow>

namespace Ui {
class Rejet;
}

class Rejet : public QMainWindow
{
    Q_OBJECT

public:
    explicit Rejet(QWidget *parent = 0);
    ~Rejet();

private slots:

    void on_pushButton_clicked();

    void on_pushButton_11_clicked();

    void on_pushButton_14_clicked();

    void on_pushButton_12_clicked();

    void on_pushButton_13_clicked();

private:
    Ui::Rejet *ui;
};

#endif // REJET_H
