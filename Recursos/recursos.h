// Created by Sérgio Costa on 17/11/2021.

#ifndef PROJECTPOO_RECURSOS_H
#define PROJECTPOO_RECURSOS_H

#include <string>

class Recurso{
    float preco, quantidade;
    std::string material;

public:
    Recurso(float prec, std::string mat, float quant=0);

    ~Recurso(){ };

    float &getPreco();
    float &getQuantidade();
    std::string &getNomeMaterial();

    void setQuantidade(float quant);
};


#endif
