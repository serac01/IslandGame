// Created by serco on 06/01/2022.

#ifndef PROJECTPOO_BATERIA_H
#define PROJECTPOO_BATERIA_H

#include "edificios.h"

class Bateria : public Edificio{
    int nivel;
    float armazena, custoNivel,capMax;

public:
    Bateria(): Edificio(10,"bat"), nivel(1), custoNivel(5), armazena(0), capMax(100) {}

    float getArmazem() override { return armazena; }

    float setArmazem(float eletrecidade) override {
        if(armazena<capMax){
            armazena= armazena+eletrecidade;
            return 1;
        }
        return 0;
    }

    float upgradeNivel(float dinheiroDisponivel) override{
        if(nivel<5 && dinheiroDisponivel >= custoNivel){
            nivel++;
            capMax=capMax+10;
            dinheiroDisponivel=dinheiroDisponivel-custoNivel;
            return dinheiroDisponivel;
        }
        return dinheiroDisponivel;
    }
};

#endif