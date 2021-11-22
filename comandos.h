// Created by Sérgio Costa on 18/11/2021.

#ifndef PROJECTPOO_COMANDOS_H
#define PROJECTPOO_COMANDOS_H

#include <sstream>

class Comando {
    std::string nome, descr, args;

public:
    Comando(std::string n, std::string d, std::string a = "") : nome(n), descr(d), args(a) {}

    // Devolve o nome do comando
    std::string getNome() const { return nome; }

    // Devolve os argumentos que o comando necessita
    std::string getArgs() const { return args; }

    //Não é usado, mas mostra a descrição dos comandos
    std::string getAsString() const;
};

#endif //PROJECTPOO_COMANDOS_H
