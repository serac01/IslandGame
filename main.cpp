#include "includes.h"
#include "mundo.h"
#include "interface.h"

int main(){
    srand(time(NULL));

    int lin,col;

    cout << "Diga o numero de linhas: ";
    cin >> lin;
    cout << "Diga o numero de colunas: ";
    cin >> col;


    Mundo m(lin,col);

    m.criaTabela();
    m.prencheTabela();
    m.mostraTabela();

    //Limpar
    cin.clear();
    cin.ignore(256,'\n');

    Interface interf(m);
    interf.pedirComandos();


    return 0;
}