// Created by serco on 06/01/2022.

#ifndef PROJECTPOO_CENTRAL_H
#define PROJECTPOO_CENTRAL_H

#include "edificios.h"

class Central : public Edificio{
    float armazena, capMax;

public:
    Central(): Edificio(15,"central"), armazena(0), capMax(100) {}

    float getArmazem() override { return armazena; }

    float setArmazem(float madeira) override {
        if(armazena<capMax){
            armazena=armazena+madeira;//recebe madeira e guarda carvao
            return 1;
        }
        return 0;
    }
};

#endif