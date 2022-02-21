// Created by Sérgio Costa on 18/11/2021.

#ifndef PROJECTPOO_COMANDOS_H
#define PROJECTPOO_COMANDOS_H

#include <sstream>

class Comando {
    std::string nome, args;

public:
    //CONSTRUTOR
    Comando(std::string n, std::string a = "");

    //GETTERS
    std::string getNome() const;
    std::string getArgs() const;
};

#endif
