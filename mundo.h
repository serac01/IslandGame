//
// Created by serco on 17/11/2021.
//

#ifndef PROJECTPOO_MUNDO_H
#define PROJECTPOO_MUNDO_H

#include "includes.h"
#include "zonas.h"

class Mundo{
    int linha;
    int coluna;
    Zona **arrayZonas;
    vector<Zona> listaContas;

public:
    Mundo(int lin=3, int col=3): linha(lin), coluna(col) {
        std::cout << "Construindo o mundo: " << linha << " * " << coluna << "\n";
    }

    //Apaga a memoria dinamica que foi alocada para o array bidimencional
    ~Mundo() {
        for(int i=0;i<linha;i++)    //To delete the inner arrays
            delete [] arrayZonas[i];
        delete [] arrayZonas;              //To delete the outer array
        std::cout << "Destruindo o mundo: " << linha << " * " << coluna << "\n";
    }

    void criaTabela();

    void prencheTabela();

    void mostraTabela();
};

#endif //PROJECTPOO_MUNDO_H
