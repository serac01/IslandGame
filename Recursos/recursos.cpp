#include "recursos.h"

using namespace std;

Recurso::Recurso(float prec, string mat, float quant): quantidade(quant), preco(prec), material(mat) { };

float &Recurso::getPreco(){ return preco; }

float &Recurso::getQuantidade(){ return quantidade; }

string &Recurso::getNomeMaterial(){ return material; }

void Recurso::setQuantidade(float quant){ quantidade=quant; }