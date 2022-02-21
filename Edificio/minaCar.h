// Created by serco on 06/01/2022.

#ifndef PROJECTPOO_MINAC_H
#define PROJECTPOO_MINAC_H

#include "edificios.h"

class MinaC : public Edificio {
    float nivel, armazena, pbDesaba, capMax, custoNivel;
public:
    MinaC(): Edificio( 10,"minac"), nivel(1), pbDesaba(0.1), custoNivel(10), armazena(0), capMax(100) {}

    float getProbDesabar() override { return pbDesaba; }

    float getArmazem()  override { return armazena; }

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