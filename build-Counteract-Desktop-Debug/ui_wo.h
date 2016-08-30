/********************************************************************************
** Form generated from reading UI file 'wo.ui'
**
** Created by: Qt User Interface Compiler version 5.3.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WO_H
#define UI_WO_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QListView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_WO
{
public:
    QWidget *centralwidget;
    QPushButton *pushButton;
    QPushButton *pushButton_8;
    QPushButton *pushButton_3;
    QListView *listView;
    QPushButton *pushButton_5;

    void setupUi(QMainWindow *WO)
    {
        if (WO->objectName().isEmpty())
            WO->setObjectName(QStringLiteral("WO"));
        WO->resize(800, 480);
        centralwidget = new QWidget(WO);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(450, 90, 101, 31));
        pushButton_8 = new QPushButton(centralwidget);
        pushButton_8->setObjectName(QStringLiteral("pushButton_8"));
        pushButton_8->setGeometry(QRect(0, 30, 150, 100));
        QFont font;
        font.setPointSize(16);
        font.setBold(true);
        font.setWeight(75);
        pushButton_8->setFont(font);
        pushButton_3 = new QPushButton(centralwidget);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setGeometry(QRect(550, 280, 131, 31));
        listView = new QListView(centralwidget);
        listView->setObjectName(QStringLiteral("listView"));
        listView->setGeometry(QRect(380, 280, 161, 131));
        pushButton_5 = new QPushButton(centralwidget);
        pushButton_5->setObjectName(QStringLiteral("pushButton_5"));
        pushButton_5->setGeometry(QRect(550, 380, 131, 31));
        WO->setCentralWidget(centralwidget);

        retranslateUi(WO);

        QMetaObject::connectSlotsByName(WO);
    } // setupUi

    void retranslateUi(QMainWindow *WO)
    {
        WO->setWindowTitle(QApplication::translate("WO", "MainWindow", 0));
        pushButton->setText(QApplication::translate("WO", "Full Screen", 0));
        pushButton_8->setText(QApplication::translate("WO", "PRODUCTION", 0));
        pushButton_3->setText(QApplication::translate("WO", "update", 0));
        pushButton_5->setText(QApplication::translate("WO", "select WO#", 0));
    } // retranslateUi

};

namespace Ui {
    class WO: public Ui_WO {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WO_H
