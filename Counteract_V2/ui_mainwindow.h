/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.3.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QTabWidget *tabWidget;
    QWidget *tab;
    QPushButton *pushButton;
    QLCDNumber *lcdNumber;
    QLabel *label_6;
    QLabel *label_3;
    QLCDNumber *lcdNumber_2;
    QLabel *label_7;
    QLCDNumber *lcdNumber_3;
    QWidget *tab_2;
    QPushButton *pushButton_5;
    QListView *listView;
    QWidget *tab_3;
    QPushButton *pushButton_2;
    QLabel *label_4;
    QListView *listView_2;
    QSpinBox *spinBox;
    QWidget *tab_4;
    QPushButton *pushButton_4;
    QPushButton *pushButton_3;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_5;
    QLabel *label_8;
    QLabel *label_9;
    QLabel *label_10;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(800, 480);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setEnabled(true);
        tabWidget->setGeometry(QRect(0, 36, 800, 404));
        tabWidget->setStyleSheet(QLatin1String("QTabBar::tab {height: 115px; width: 100px;};\n"
"QTabWidget::pane {border: 1px solid #C4C4C3; top: -1px;}"));
        tabWidget->setTabPosition(QTabWidget::West);
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        pushButton = new QPushButton(tab);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(320, 55, 201, 51));
        lcdNumber = new QLCDNumber(tab);
        lcdNumber->setObjectName(QStringLiteral("lcdNumber"));
        lcdNumber->setGeometry(QRect(240, 55, 71, 51));
        QFont font;
        font.setBold(true);
        font.setWeight(75);
        lcdNumber->setFont(font);
        lcdNumber->setFrameShape(QFrame::WinPanel);
        lcdNumber->setFrameShadow(QFrame::Plain);
        lcdNumber->setLineWidth(1);
        lcdNumber->setSmallDecimalPoint(true);
        lcdNumber->setSegmentStyle(QLCDNumber::Flat);
        label_6 = new QLabel(tab);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(106, 60, 111, 39));
        QFont font1;
        font1.setPointSize(16);
        font1.setBold(true);
        font1.setWeight(75);
        label_6->setFont(font1);
        label_3 = new QLabel(tab);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(120, 150, 111, 41));
        label_3->setFont(font1);
        lcdNumber_2 = new QLCDNumber(tab);
        lcdNumber_2->setObjectName(QStringLiteral("lcdNumber_2"));
        lcdNumber_2->setGeometry(QRect(240, 140, 71, 51));
        QFont font2;
        font2.setPointSize(20);
        font2.setBold(true);
        font2.setWeight(75);
        lcdNumber_2->setFont(font2);
        lcdNumber_2->setFrameShape(QFrame::WinPanel);
        lcdNumber_2->setFrameShadow(QFrame::Plain);
        lcdNumber_2->setSmallDecimalPoint(true);
        lcdNumber_2->setSegmentStyle(QLCDNumber::Flat);
        lcdNumber_2->setProperty("intValue", QVariant(1));
        label_7 = new QLabel(tab);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(50, 210, 171, 41));
        label_7->setFont(font1);
        lcdNumber_3 = new QLCDNumber(tab);
        lcdNumber_3->setObjectName(QStringLiteral("lcdNumber_3"));
        lcdNumber_3->setGeometry(QRect(240, 200, 71, 51));
        lcdNumber_3->setFont(font2);
        lcdNumber_3->setFrameShape(QFrame::WinPanel);
        lcdNumber_3->setFrameShadow(QFrame::Plain);
        lcdNumber_3->setSmallDecimalPoint(true);
        lcdNumber_3->setSegmentStyle(QLCDNumber::Flat);
        lcdNumber_3->setProperty("intValue", QVariant(1));
        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        pushButton_5 = new QPushButton(tab_2);
        pushButton_5->setObjectName(QStringLiteral("pushButton_5"));
        pushButton_5->setGeometry(QRect(350, 140, 131, 131));
        pushButton_5->setFont(font1);
        listView = new QListView(tab_2);
        listView->setObjectName(QStringLiteral("listView"));
        listView->setGeometry(QRect(180, 140, 161, 131));
        listView->setFont(font1);
        tabWidget->addTab(tab_2, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QStringLiteral("tab_3"));
        pushButton_2 = new QPushButton(tab_3);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(510, 120, 101, 81));
        label_4 = new QLabel(tab_3);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(40, 140, 141, 31));
        label_4->setFont(font2);
        listView_2 = new QListView(tab_3);
        listView_2->setObjectName(QStringLiteral("listView_2"));
        listView_2->setGeometry(QRect(340, 120, 161, 81));
        spinBox = new QSpinBox(tab_3);
        spinBox->setObjectName(QStringLiteral("spinBox"));
        spinBox->setGeometry(QRect(180, 120, 131, 81));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(spinBox->sizePolicy().hasHeightForWidth());
        spinBox->setSizePolicy(sizePolicy);
        QFont font3;
        font3.setPointSize(24);
        font3.setBold(true);
        font3.setWeight(75);
        spinBox->setFont(font3);
        spinBox->setStyleSheet(QStringLiteral("QSpinBox::up-button{width: 32px;} QSpinBox::down-button{width: 32px;}"));
        spinBox->setMaximum(1000);
        tabWidget->addTab(tab_3, QString());
        tab_4 = new QWidget();
        tab_4->setObjectName(QStringLiteral("tab_4"));
        pushButton_4 = new QPushButton(tab_4);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));
        pushButton_4->setGeometry(QRect(250, 360, 141, 41));
        pushButton_3 = new QPushButton(tab_4);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setGeometry(QRect(390, 360, 161, 41));
        tabWidget->addTab(tab_4, QString());
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(650, 400, 151, 81));
        label->setPixmap(QPixmap(QString::fromUtf8("CALogosmall.png")));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(490, 10, 311, 21));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy1);
        QFont font4;
        font4.setPointSize(16);
        font4.setBold(true);
        font4.setItalic(true);
        font4.setWeight(75);
        label_2->setFont(font4);
        label_2->setLayoutDirection(Qt::RightToLeft);
        label_2->setStyleSheet(QStringLiteral("QLabel{qproperty-alignment: AlignRight;}"));
        label_5 = new QLabel(centralWidget);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(20, 0, 68, 31));
        label_5->setPixmap(QPixmap(QString::fromUtf8("WifiOFF.png")));
        label_8 = new QLabel(centralWidget);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(20, 0, 68, 31));
        label_8->setPixmap(QPixmap(QString::fromUtf8("WifiON.png")));
        label_9 = new QLabel(centralWidget);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(90, -10, 31, 51));
        label_9->setPixmap(QPixmap(QString::fromUtf8("databaseoff.png")));
        label_10 = new QLabel(centralWidget);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setGeometry(QRect(90, -10, 31, 51));
        label_10->setPixmap(QPixmap(QString::fromUtf8("databaseon.png")));
        MainWindow->setCentralWidget(centralWidget);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        pushButton->setText(QApplication::translate("MainWindow", "Cycle Time", 0));
        label_6->setText(QApplication::translate("MainWindow", "Cycle Time :", 0));
        label_3->setText(QApplication::translate("MainWindow", "Parts Done :", 0));
        label_7->setText(QApplication::translate("MainWindow", "Total Parts To Do:", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("MainWindow", "PRODUCTION", 0));
        pushButton_5->setText(QApplication::translate("MainWindow", "select WO#", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("MainWindow", "WORK ORDER", 0));
        pushButton_2->setText(QApplication::translate("MainWindow", "Remove", 0));
        label_4->setText(QApplication::translate("MainWindow", "Part Reject :", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QApplication::translate("MainWindow", "REJECT", 0));
        pushButton_4->setText(QApplication::translate("MainWindow", "toggle FS", 0));
        pushButton_3->setText(QApplication::translate("MainWindow", "CLOSE", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab_4), QApplication::translate("MainWindow", "CONFIG", 0));
        label->setText(QString());
        label_2->setText(QApplication::translate("MainWindow", "TextLabel", 0));
        label_5->setText(QString());
        label_8->setText(QString());
        label_9->setText(QString());
        label_10->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
