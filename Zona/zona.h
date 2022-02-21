// Created by Sérgio Costa on 17/11/2021.

#ifndef PROJECTPOO_ZONA_H
#define PROJECTPOO_ZONA_H


#include <vector>
#include <string>
#include <iostream>

#include "../Edificio/edificios.h"
#include "../Edificio/minaFerr.h"
#include "../Edificio/minaCar.h"
#include "../Edificio/central.h"
#include "../Edificio/bateria.h"
#include "../Edificio/fundicao.h"
#include "../Edificio/serracao.h"

#include "../Trabalhadores/trabalhadores.h"

#include "../Recursos/recursos.h"

class Zona{
    std::string nome,abreviatura;
    int num, flagEdificio;
    static int contador;
    Edificio* edificio;

    std::vector <Edificio> configEdificio{{10,"minaf"},
                                          {10,"minac"},
                                          {15,"central"},
                                          {10,"bat"},
                                          {10,"fund"},
                                          {10,"serr"}};

public:
    Zona(std::string n, std::string a);

    virtual ~Zona();

    virtual void maisMadeira(int nDia, int temEdificio) { };
    virtual int desaba(int dia) { return 0; };
    virtual int produzZona(int n) { return 0; };
    virtual float getMadeiraArmazenada() { return 0; };
    virtual float getFerroArmazenada() { return 0; };
    virtual void setMadeiraArmazenada(float n){ };

    //Getters e Setters
    std::string &getNome();
    std::string getAbreviaturas();
    void setContador();

    std::string getNomeEdificio();
    int temEdificio();
    bool estadoEdificio();
    int constroiEdificio(std::string nome, float *dinheiro, float *nVigas);
    int constroiEdificioGratis(std::string nome);
    int upEdificio(float* din);
    int ligaEdificio();
    int desligaEdificio();
    int apagaEdificio();
    float getPrecoEdificio(std::string nome);
    void setPrecoEdificio(std::vector<std::string> words);
    float getArmazemEd();
    float setArmazemEd(float n);
    float setArmazemEdReduz(float n);
    float setArmazemEdDobra(float n);
    float getPD();
};


#endif
