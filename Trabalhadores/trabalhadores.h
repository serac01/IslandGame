// Created by Sérgio Costa on 22/11/2021.

#ifndef PROJECTPOO_TRABALHADORES_H
#define PROJECTPOO_TRABALHADORES_H

#include <iostream>

class Trabalhador {
    std::string nome,id;
    int linha, coluna,preco;
    float probDespedir;

public:
    Trabalhador(std::string n, std::string idTrab, int l, int c, int p, float pd);

    ~Trabalhador(){ }

    //Gets
    std::string &getNome();
    std::string &getID();
    int &getPreco();
    int &getLinha();
    int &getColuna();
    float &getProbabilidadeDespedir();

    //Sets
    int &setLinha(int l);
    int &setColuna(int c);
};

#endif
