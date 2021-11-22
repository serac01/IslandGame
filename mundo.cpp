#include "mundo.h"

using namespace std;

void Mundo::criaTabela(){
    //Numero de linhas
    arrayZonas = new Zona*[linha];

    //Numero de colunas
    for (int i = 0; i < linha; i++) {
        arrayZonas[i] = new Zona[coluna];
    }
}

void Mundo::prencheTabela(){
    //Prencher array
    const char *nomeZonas[6] = { "Deserto", "Pastagem","Floresta", "Montanha", "Pantano", "Zona-X" },
                *abrZonas[6] = { "dsr", "pas","flr", "mnt", "pnt", "znZ" };

    int v1;
    for (int i = 0; i < linha; i++) {
        for (int j = 0; j < coluna; j++) {
            v1 = rand() % 6;
            arrayZonas[i][j].setNome(nomeZonas[v1]);
            arrayZonas[i][j].setAbreviaturas(abrZonas[v1]);
        }
    }
}

int Mundo::prencheZonaTrabalhador(string nome){
    Trabalhador x;
    x.setnome(nome);

    for (int i = 0; i < linha; i++) {
        for (int j = 0; j < coluna; j++) {
            if(arrayZonas[i][j].setTrabalhador(x,i,j)){
                return 1;
            }
        }
    }
    return 0;
}

int Mundo::prencheZonaEdificio(string nome, string abr, int linha, int coluna){

    arrayZonas[linha][coluna].setEdificio(nome,abr,linha,coluna);

    return 1;
}

void Mundo::mostraTabela(){
    char myStr[]="    ";
    cout << "\n\n\n" << endl;
    for(int x=0;x<((coluna*5)+1);x++)
        cout << "*";
    //Mostrar o array
    for (int i = 0; i < linha; i++) {
        cout <<  "\n*";
        //Nome da Zona
        for (int j = 0; j < coluna; j++) {
            cout << arrayZonas[i][j].getAbreviaturas() << " *";
        }
        //Edificios
        cout <<  "\n*";
        for (int j = 0; j < coluna; j++) {
            cout << arrayZonas[i][j].getEdificio() << " " << "*";
        }
        //Trabalhadores
        cout <<  "\n*";
        for (int j = 0; j < coluna; j++) {
            arrayZonas[i][j].testfunc(myStr,i,j);
            //cout << "\n\t" << myStr << "\n\n" << endl;
            cout << myStr << "*";
        }
        cout <<  "\n*";
        //Conta Trabalhadores
        for (int j = 0; j < coluna; j++) {
            cout << arrayZonas[i][j].contraTrabalhadores(i,j) << "   " << "*";
        }
        cout << endl;
        for(int x=0;x<((coluna*5)+1);x++)
            cout << "*";
    }
    cout << "\n\n\n" << endl;
}