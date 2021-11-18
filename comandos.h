//
// Created by serco on 18/11/2021.
//

#ifndef PROJECTPOO_COMANDOS_H
#define PROJECTPOO_COMANDOS_H

#include "includes.h"
#include "mundo.h"

class Comando {
    string nome, descr, args;
    bool disponivel = false;

public:
    Comando(string n, string d, string a = "") : nome(n), descr(d), args(a) {}

    // Devolve o nome do comando
    string getNome() const { return nome; }

    // Devolve a descricao do comando
    string getDescr() const { return descr; }

    // Devolve os argumentos que o comando necessita
    string getArgs() const { return args; }

    string getAsString() const;
};

#endif //PROJECTPOO_COMANDOS_H
