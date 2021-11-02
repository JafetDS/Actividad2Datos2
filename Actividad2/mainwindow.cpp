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


vector <string> MainWindow::split(string str, char delimiter) {
    vector<string> res;
    stringstream ss(str);
    string s;
    while (getline(ss, s, delimiter)) {
        res.push_back(s);
    }
    return res;
}

string MainWindow::comprimir(string text){

    string result;
    result = compresLZ77(text);
    return result;


}

string MainWindow::descomprimir(string input){
    string res;
    vector<string> inputSplit = split(input,'|');
    for(auto & i : inputSplit){

        vector<string> inputSegment = split(i,',');

        int p = stoi(inputSegment[0]), l = stoi(inputSegment[1]);
        string c;

        if(inputSegment[2][0] == '0'){
            c = ' ';
        }else{
            c = inputSegment[2];
        }

        if(p != 0){
            int resLength = (int)res.length();
            for(int j = 0; j < l; j++){
                res += res[resLength - p + j];
            }
        }
        if(c[0] != '0' || c[0] != NULL){
            res += c;
        }
    }
    return res;

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

string MainWindow::descompres(string input)
{


    string result;
    return result;


}

string MainWindow::compresLZ77(string input)
{
    // Initialized variables
    string result;
    int length, char_info_selc = 0;
   // string input = "cabracadabrarrarrad";
    length = (int)input.length();
    vector<vector<string>> result_ary( 3 , vector<string> (length, "0"));
    vector<vector<string>> char_info( 3 , vector<string> (length, "0"));

    // establece la informacin del primer elemento (0,0,'<first char>')
        result_ary[0][0] = "0";
        result_ary[1][0] = "0";
        result_ary[2][0] = input[0];

    // Set result counter
    int result_count = 1;

    // Hace operaciones en cada elemento del string
    for (int i = 1; i < length; i++)
    {
        // verifica si el elmento de en la posiciÃ³n i es igual a un elemento anterior
        for (int j = 0; j < i; j++)
        {

            if (input[i] == input[j])
            {

                char_info[0][char_info_selc] = to_string(i - j);

                char_info_selc++;
            }

        }

        for (int j = 0; j < length; j++)
        {
            if (char_info[0][j] != "0")
            {
                int start = i - stoi(char_info[0][j]);

                int count = 1;

                for (int k = 0; k < length; k++)
                {
                    if (input[start + count] == input[i + count])
                        count++;
                    else
                    {
                        char_info[1][j] = to_string(count);

                        if (i != (length - 1))
                        {

                            if (stoi(char_info[0][j]) + count == length)
                                char_info[2][j] = "0";
                            else
                                char_info[2][j] = input[stoi(char_info[0][j]) + count];
                        }
                        else
                            char_info[2][j] = " ";

                        break;
                    }
                }
            }
        }


        int large = 0;

        for (int k = 1; k < length; k++)
        {
            if (char_info[1][large] == char_info[1][k])
                large = k;
            else if (char_info[1][large] < char_info[1][k])
                large = k;
        }

        if (char_info[1][large] == "0")
            char_info[2][large] = input[i];
        else
        {
            i += stoi(char_info[1][large]);
            char_info[2][large] = input[i];
        }

        // Set final result info
        result_ary[0][result_count] = char_info[0][large];
        result_ary[1][result_count] = char_info[1][large];
        result_ary[2][result_count] = char_info[2][large];

        result_count++;

        for (int z = 0; z < 2; z++)
        {
            for (int j = 0; j < length; j++)
                char_info[z][j] = "0";
        }

        char_info_selc = 0;
    }

    //Resultado final
    string z;
    for (int j = 0; j < length; j++)
    {
        if (result_ary[0][j] == "0" && result_ary[1][j] == "0")
        {
            if ( result_ary[2][j] != "0")  //result_ary[2][j] != " " ||
            {
                z = result_ary[2][j];
                result += result_ary[0][j] + "," + result_ary[1][j] + "," + z + "|";
            }
        }
        else
        {
            z = result_ary[2][j];
          //  cout<<z<<endl;
            if (z != "0"){
                result += result_ary[0][j] + "," + result_ary[1][j] + "," + z + "|";
            }


        }
    }
    result.pop_back();

    cout<<result<<endl;
    return result;


}
