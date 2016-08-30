#ifndef WO_H
#define WO_H

#include <QMainWindow>


namespace Ui {
class WO;
}

class WO : public QMainWindow
{
    Q_OBJECT

public:
    explicit WO(QWidget *parent = 0);
    ~WO();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_8_clicked();

    void on_listView_clicked(const QModelIndex &index);

    void on_pushButton_3_clicked();

    void on_pushButton_5_clicked();

private:
    Ui::WO *ui;

};

#endif // WO_H
