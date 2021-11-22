// Created by Sérgio Costa on 22/11/2021.

#ifndef PROJECTPOO_TRABALHADORES_H
#define PROJECTPOO_TRABALHADORES_H

#include <iostream>

class Trabalhador {
    std::string nome;
    int linha, coluna;

public:
    Trabalhador(std::string n="", int l=0, int c=0) : nome(n), linha(l), coluna(c)  {
        //std::cout << "Construindo a Trabalhador: " << nome << " " << linha << " " << coluna << "\n";
    }

    ~Trabalhador(){
        //std::cout << "Destruindo a Trabalhador: " << nome << " " << linha << " " << coluna <<"\n";
    }

    std::string &getNome(){
        return nome;
    }

    int &getLinha(){
        return linha;
    }

    int &getColuna(){
        return coluna;
    }

    std::string &setnome(std::string a){
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

#endif
