#include "mundo.h"
#include "zonas.h"

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

    int v1, flag=0;
    for (int i = 0; i < linha; i++) {
        for (int j = 0; j < coluna; j++) {
            v1 = rand() % 6;
            arrayZonas[i][j].setNome(nomeZonas[v1]);
            arrayZonas[i][j].setAbreviaturas(abrZonas[v1]);
            arrayZonas[i][j].setId(v1);
        }
    }
}

void Mundo::mostraTabela(){
    cout << "\n\n\n" << endl;
    for(int x=0;x<((coluna*5)+1);x++)
        cout << "*";
    //Mostrar o array
    for (int i = 0; i < linha; i++) {
        cout <<  "\n*";
        for (int j = 0; j < coluna; j++) {
            cout << arrayZonas[i][j].getAbreviaturas() << " *";
        }
        cout <<  "\n*";
        for (int j = 0; j < coluna; j++) {
            cout << "    " << "*";
        }
        cout <<  "\n*";
        for (int j = 0; j < coluna; j++) {
            cout << "    " << "*";
        }
        cout <<  "\n*";
        for (int j = 0; j < coluna; j++) {
            cout << "    " << "*";
        }
        cout << endl;
        for(int x=0;x<((coluna*5)+1);x++)
            cout << "*";
    }
    cout << "\n\n\n" << endl;
}