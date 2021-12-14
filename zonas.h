// Created by Sérgio Costa on 17/11/2021.

#ifndef PROJECTPOO_ZONAS_H
#define PROJECTPOO_ZONAS_H

#include "edificios.h"
#include "trabalhadores.h"
#include <vector>

class Zona{
    std::string nome,abreviatura;
    int num;
    static int contador;
    std::vector <Trabalhador> trabalhadores;
    Edificio h;

public:
    Zona(std::string n="", std::string a=""): nome(n), abreviatura(a), num(contador++) { }

    ~Zona(){ }

    //Gets
    std::string &getAbreviaturas();
    std::string &getNome();
    std::string &getEdificio();
    int &getNumZona();

    //Sets
    std::string &setAbreviaturas(std::string a);
    std::string &setNome(std::string n);

    //Outras:
    void setEdificio(std::string nome,std::string abr,int linha,int coluna);
    int setTrabalhador(Trabalhador &trb, int i, int j);
    int contaTrabalhadores(int lin, int col);
    void concatTrabalhadores(char* outStr, int lin, int col);
};

#endif //PROJECTPOO_ZONAS_H
