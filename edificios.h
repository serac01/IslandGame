// Created by Sérgio Costa on 18/11/2021.

#ifndef PROJECTPOO_EDIFICIOS_H
#define PROJECTPOO_EDIFICIOS_H

#include <iostream>

class Edificio {
    std::string nome,abreviatura;
    int linha, coluna;
    bool estado;

public:
    //CONSTRUTOR
    Edificio(std::string n="", std::string a="   ", int l=0, int c=0): nome(n), abreviatura(a), estado(false), linha(l), coluna(c) { }

    //DESTRUTOR
    ~Edificio(){ }

    //SETTERS
    std::string &setnome(std::string a);
    std::string &setAbreviatura(std::string a);
    bool &setEstado(bool e);
    int &setLinha(int l);
    int &setColuna(int c);

    //GETTERS
    std::string &getNome();
    std::string &getAbreviatura();
    bool &getEstado();
    int &getLinha();
    int &getColuna();
};

#endif
