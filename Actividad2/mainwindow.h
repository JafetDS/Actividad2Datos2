#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <iostream>
#include <vector>
#include <sstream>
#include <string>
#include <vector>
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE
using namespace std;
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    string comprimir(string);
    string descomprimir(string);
    string compresLZ77(string);
    string descompres(string);
    vector <string> split(string, char);

    ~MainWindow();

private slots:
    void on_comprimirB_clicked();

    void on_descomprimirB_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
