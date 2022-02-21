#include "edificios.h"

using namespace std;

Edificio::Edificio(int prec, string name): preco(prec), nome(name), estado(false) { }

string &Edificio::getNome(){ return nome; }

bool &Edificio::getEstado(){ return estado; }

int &Edificio::getPreco(){ return preco; }

void Edificio::setEstado(bool est){ estado=est; }

void Edificio::setPreco(int prec) { preco=prec; }