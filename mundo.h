// Created by Sérgio Costa on 17/11/2021.

#ifndef PROJECTPOO_MUNDO_H
#define PROJECTPOO_MUNDO_H

#include "zonas.h"
#include <fstream>

class Mundo{
    int linha;
    int coluna;
    Zona **arrayZonas;

public:
    Mundo(int lin=3, int col=3): linha(lin), coluna(col) {}

    ~Mundo() {
        for(int i=0;i<linha;i++)
            delete [] arrayZonas[i];
        delete [] arrayZonas;
    }

    int &getLinha();

    int &getColuna();

    void criaTabela();

    void prencheTabela();

    void mostraTabela();

    int prencheZonaTrabalhador(std::string nome);

    int prencheZonaEdificio(std::string nome, std::string abr, int linha, int coluna);

    void descTabela(int l, int c);

    void descTabelaCompleta();
};

#endif
