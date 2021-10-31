/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.2.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QPushButton *descomprimirB;
    QPushButton *comprimirB;
    QTextEdit *textEdit_1;
    QTextEdit *textEdit_2;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1207, 512);
        MainWindow->setStyleSheet(QString::fromUtf8("\n"
"\n"
"background-color: rgb(255, 118, 64);\n"
""));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        descomprimirB = new QPushButton(centralwidget);
        descomprimirB->setObjectName(QString::fromUtf8("descomprimirB"));
        descomprimirB->setGeometry(QRect(520, 260, 121, 25));
        descomprimirB->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 186, 24);\n"
"color: rgb(0, 0, 0);"));
        comprimirB = new QPushButton(centralwidget);
        comprimirB->setObjectName(QString::fromUtf8("comprimirB"));
        comprimirB->setGeometry(QRect(520, 150, 111, 25));
        comprimirB->setStyleSheet(QString::fromUtf8("color: rgb(255, 186, 24);\n"
"background-color: rgb(61, 61, 61);"));
        textEdit_1 = new QTextEdit(centralwidget);
        textEdit_1->setObjectName(QString::fromUtf8("textEdit_1"));
        textEdit_1->setGeometry(QRect(30, 90, 461, 271));
        textEdit_1->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        textEdit_1->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
        textEdit_2 = new QTextEdit(centralwidget);
        textEdit_2->setObjectName(QString::fromUtf8("textEdit_2"));
        textEdit_2->setGeometry(QRect(670, 90, 441, 271));
        textEdit_2->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        textEdit_2->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1207, 25));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        descomprimirB->setText(QCoreApplication::translate("MainWindow", "Descomprimir", nullptr));
        comprimirB->setText(QCoreApplication::translate("MainWindow", "Comprimir", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
