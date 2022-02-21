// Created by serco on 06/01/2022.

#ifndef PROJECTPOO_MINAF_H
#define PROJECTPOO_MINAF_H

#include "edificios.h"

class MinaF : public Edificio{
    float armazena, pbDesaba, nivel, custoNivel, capMax;

public:
    MinaF(): Edificio(10,"minaf"), nivel(1), custoNivel(15), pbDesaba(0.15), armazena(0), capMax(100) { }

    float getProbDesabar() override { return pbDesaba; }

    float getArmazem() override { return armazena; };

    float setArmazem(float n) override {
        if(armazena<capMax){
            armazena=armazena+n+(nivel-1);
            return 1;
        }
        return 0;
    }

    float setArmazemReduz(float n) override {
        if(armazena<capMax){
            armazena=armazena+( n + (nivel-1) ) / 2;
            return 1;
        }
        return 0;
    }

    float setArmazemDobra(float n) override {
        if(armazena<capMax){
            armazena=armazena+( n + (nivel-1) ) * 2;
            return 1;
        }
        return 0;
    }

    float upgradeNivel(float dinheiroDisponivel) override {
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