#include "interface.h"
#include <time.h>
#include "mainwindow.h"
#include <QApplication>

using namespace std;

int main(int argc, char *argv[]){

    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();/*

    srand(time(NULL));
    int lin,col;

    do{
        cout << "Diga o numero de linhas: ";
        cin >> lin;
        cout << "Diga o numero de colunas: ";
        cin >> col;
    } while ((lin < 3 || lin > 8) || (col < 3 || col > 16));


    Mundo m(lin,col);

    m.criaTabela();
    m.mostraTabela();

    //Limpar
    cin.clear();
    cin.ignore(256,'\n');

    Interface interf(m);
    interf.pedirComandos();

    m.mostraTabela();

    return 0;*/
}