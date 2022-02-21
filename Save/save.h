#ifndef SAVE_H
#define SAVE_H

#include "../Ilha/ilha.h"

class Save {
    std::string nome;
    Ilha ilh;

public:

    Save(Ilha& m, std::string n="save") : nome(n), ilh(m){}

    ~Save(){}

    std::string getNome() const { return nome; }

    Ilha getIlha() const { return ilh; }
};

#endif