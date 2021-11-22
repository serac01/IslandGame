//
// Created by serco on 17/11/2021.
//

#ifndef PROJECTPOO_MUNDO_H
#define PROJECTPOO_MUNDO_H

#include "includes.h"
#include "zonas.h"
#include "trabalhadores.h"

class Mundo{
    int linha;
    int coluna;
    Zona **arrayZonas;

public:
    Mundo(int lin=3, int col=3): linha(lin), coluna(col) {}

    //Apaga a memoria dinamica que foi alocada para o array bidimencional
    ~Mundo() {
        for(int i=0;i<linha;i++)    //To delete the inner arrays
            delete [] arrayZonas[i];
        delete [] arrayZonas;              //To delete the outer array
    }

    void criaTabela();

    void prencheTabela();

    int prencheZonaTrabalhador(string nome);

    int prencheZonaEdificio(string nome, string abr, int linha, int coluna);

    void mostraTabela();

    int &getLinha(){
        return linha;
    }

    int &getColuna(){
        return coluna;
    }
};

#endif //PROJECTPOO_MUNDO_H
