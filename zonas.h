//
// Created by serco on 17/11/2021.
//

#ifndef PROJECTPOO_ZONAS_H
#define PROJECTPOO_ZONAS_H

#include "includes.h"
#include "edificios.h"


class Zona{
    string nome,abreviatura;
    int id;

public:
    Zona(string n="", string a="", int i=0): nome(n), abreviatura(a), id(i) {
        std::cout << "Construindo a Zona: " << nome << " " << abreviatura << " " << id << "\n";
    }

    ~Zona(){
        std::cout << "Destruindo a zona: " << nome << " " << abreviatura << " " << id <<"\n";
    }

    string &getAbreviaturas(){
        return abreviatura;
    }

    string &getNome(){
        return nome;
    }

    int &getId(){
        return id;
    }

    string &setAbreviaturas(string a){
        abreviatura=a;
        return abreviatura;
    }

    string &setNome(string n){
        nome=n;
        return nome;
    }

    int &setId(int n){
        id=n;
        return id;
    }
};


#endif //PROJECTPOO_ZONAS_H
