// Created by serco on 06/01/2022.

#ifndef PROJECTPOO_SERRACAO_H
#define PROJECTPOO_SERRACAO_H

#include "edificios.h"

class Serracao : public Edificio{
    float armazena;

public:
    Serracao(): Edificio(10,"serr"), armazena(0) {}

    float getArmazem() override { return armazena; }

    float setArmazem(float n) override {
        armazena=armazena+n;
        return 1;
    }
};

#endif