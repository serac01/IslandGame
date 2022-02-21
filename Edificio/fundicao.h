// Created by serco on 06/01/2022.

#ifndef PROJECTPOO_FUNDICAO_H
#define PROJECTPOO_FUNDICAO_H

#include "edificios.h"

class Fundicao : public Edificio{
    float armazena, capMax;

public:
    Fundicao(): Edificio(10,"fund"), armazena(0), capMax(100) {}

    float getArmazem() override { return armazena; }

    float setArmazem(float n) override {
        if(armazena<capMax){
            armazena=armazena+n;//armazena 1 barra de aço
            return 1;
        }
        return 0;
    }
};

#endif