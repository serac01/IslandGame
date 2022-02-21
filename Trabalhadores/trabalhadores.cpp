#include "trabalhadores.h"

using namespace std;

Trabalhador::Trabalhador(string n, string idTrab, int l, int c, int p, float pd) : nome(n), id(idTrab), linha(l), coluna(c), preco(p), probDespedir(pd) { }

string &Trabalhador::getNome(){ return nome; }

string &Trabalhador::getID(){ return id; }

int &Trabalhador::getPreco(){ return preco; }

int &Trabalhador::getLinha(){ return linha; }

int &Trabalhador::getColuna(){ return coluna; }

float &Trabalhador::getProbabilidadeDespedir(){ return probDespedir; }

int &Trabalhador::setLinha(int l){
    linha=l;
    return linha;
}

int &Trabalhador::setColuna(int c){
    coluna=c;
    return coluna;
}