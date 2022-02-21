// Created by Sérgio Costa on 18/11/2021.

#ifndef PROJECTPOO_EDIFICIOS_H
#define PROJECTPOO_EDIFICIOS_H

#include <iostream>

class Edificio {
    int preco;
    std::string nome;
    bool estado;

public:

    //Construtor e destrutor
    Edificio(int prec, std::string name=" ");
    virtual ~Edificio() { }

    //Funções virtuais
    virtual float getArmazem() { return 0; };
    virtual float setArmazem(float n) { return 0; };
    virtual float setArmazemReduz(float n) { return 0; };
    virtual float setArmazemDobra(float n) { return 0; };
    virtual float upgradeNivel(float dinheiroDisponivel){ return 0; };
    virtual float getProbDesabar() { return 0; }

    //Getters
    std::string &getNome();
    int &getPreco();
    bool &getEstado();

    //Setters
    void setPreco(int prec);
    void setEstado(bool est);
};

#endif
