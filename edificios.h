// Created by Sérgio Costa on 18/11/2021.

#ifndef PROJECTPOO_EDIFICIOS_H
#define PROJECTPOO_EDIFICIOS_H

#include <iostream>

class Edificio {
    std::string nome,abreviatura;
    bool estado;
    int linha, coluna;

public:
    Edificio(std::string n="", std::string a="   ", int l=0, int c=0): nome(n), abreviatura(a), estado(false), linha(l), coluna(c) { }

    ~Edificio(){ }

    std::string &getNome(){ return nome; }

    std::string &getAbreviatura(){ return abreviatura; }

    bool &getEstado(){ return estado; }

    int &getLinha(){ return linha; }

    int &getColuna(){ return coluna; }

    //Setters
    std::string &setnome(std::string a){
        nome=a;
        return nome;
    }

    std::string &setAbreviatura(std::string a){
        abreviatura=a;
        return abreviatura;
    }

    bool &setEstado(bool e){
        estado=e;
        return estado;
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


#endif //PROJECTPOO_EDIFICIOS_H
