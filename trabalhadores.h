//
// Created by serco on 22/11/2021.
//

#ifndef PROJECTPOO_TRABALHADORES_H
#define PROJECTPOO_TRABALHADORES_H

#include "includes.h"

class Trabalhador {
    string nome;
    int linha, coluna;

public:
    Trabalhador(string n="", int l=0, int c=0) : nome(n), linha(l), coluna(c)  {
        //std::cout << "Construindo a Trabalhador: " << nome << " " << linha << " " << coluna << "\n";
    }

    ~Trabalhador(){
        //std::cout << "Destruindo a Trabalhador: " << nome << " " << linha << " " << coluna <<"\n";
    }

    string &getNome(){
        return nome;
    }

    int &getLinha(){
        return linha;
    }

    int &getColuna(){
        return coluna;
    }

    string &setnome(string a){
        nome=a;
        return nome;
    }

    int &setLinha(int l){
        linha=l;
        return linha;
    }

    int &setColuna(int c){
        coluna=c;
        return coluna;
    }
};

#endif //PROJECTPOO_TRABALHADORES_H
