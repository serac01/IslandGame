// Created by Sérgio Costa on 22/11/2021.

#ifndef PROJECTPOO_TRABALHADORES_H
#define PROJECTPOO_TRABALHADORES_H

#include <iostream>

class Trabalhador {
    std::string nome;
    int linha, coluna;

public:
    Trabalhador(std::string n="", int l=0, int c=0) : nome(n), linha(l), coluna(c)  { }

    ~Trabalhador(){ }

    //Gets
    std::string &getNome();
    int &getLinha();
    int &getColuna();

    //Sets
    std::string &setnome(std::string a);
    int &setLinha(int l);
    int &setColuna(int c);
};

#endif
