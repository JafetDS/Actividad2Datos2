#include "mainwindow.h"
#include "ui_mainwindow.h"
using namespace std;
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

string MainWindow::comprimir(string text){

    return text;
}

string MainWindow::descomprimir(string text){

    return text;
}



void MainWindow::on_comprimirB_clicked()
{
   string descompText = ui->textEdit_1->toPlainText().toStdString();
   string compresText = comprimir(descompText);
   ui->textEdit_2->setText(QString::fromStdString(compresText));
}


void MainWindow::on_descomprimirB_clicked()
{
    string compresText = ui->textEdit_1->toPlainText().toStdString();
    string descompText = descomprimir(compresText);
    ui->textEdit_2->setText(QString::fromStdString(descompText));

}

