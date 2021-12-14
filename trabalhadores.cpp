#include "trabalhadores.h"

using namespace std;

string &Trabalhador::getNome(){ return nome; }

int &Trabalhador::getLinha(){ return linha; }

int &Trabalhador::getColuna(){ return coluna; }

string &Trabalhador::setnome(string a){
    nome=a;
    return nome;
}

int &Trabalhador::setLinha(int l){
    linha=l;
    return linha;
}

int &Trabalhador::setColuna(int c){
    coluna=c;
    return coluna;
}