/********************************************************************************
** Form generated from reading UI file 'rejet.ui'
**
** Created by: Qt User Interface Compiler version 5.3.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REJET_H
#define UI_REJET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Rejet
{
public:
    QWidget *centralwidget;
    QPushButton *pushButton_11;
    QPushButton *pushButton;

    void setupUi(QMainWindow *Rejet)
    {
        if (Rejet->objectName().isEmpty())
            Rejet->setObjectName(QStringLiteral("Rejet"));
        Rejet->resize(800, 480);
        centralwidget = new QWidget(Rejet);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        pushButton_11 = new QPushButton(centralwidget);
        pushButton_11->setObjectName(QStringLiteral("pushButton_11"));
        pushButton_11->setGeometry(QRect(0, 30, 150, 100));
        QFont font;
        font.setPointSize(16);
        font.setBold(true);
        font.setWeight(75);
        pushButton_11->setFont(font);
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(80, 180, 101, 31));
        Rejet->setCentralWidget(centralwidget);

        retranslateUi(Rejet);

        QMetaObject::connectSlotsByName(Rejet);
    } // setupUi

    void retranslateUi(QMainWindow *Rejet)
    {
        Rejet->setWindowTitle(QApplication::translate("Rejet", "MainWindow", 0));
        pushButton_11->setText(QApplication::translate("Rejet", "PRODUCTION", 0));
        pushButton->setText(QApplication::translate("Rejet", "FullScreen", 0));
    } // retranslateUi

};

namespace Ui {
    class Rejet: public Ui_Rejet {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REJET_H
