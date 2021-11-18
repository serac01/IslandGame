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
    Zona(string n="", string a=""): nome(n), abreviatura(a) {
        std::cout << "Construindo a Zona: " << nome << " " << abreviatura << "\n";
    }

    ~Zona(){
        std::cout << "Destruindo a zona: " << nome << " " << abreviatura << "\n";
    }

    string &getAbreviaturas(){
        return abreviatura;
    }

    string &getNome(){
        return nome;
    }

    string &setAbreviaturas(string a){
        abreviatura=a;
        return abreviatura;
    }

    string &setNome(string n){
        nome=n;
        return nome;
    }
};


#endif //PROJECTPOO_ZONAS_H
