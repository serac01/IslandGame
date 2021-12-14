#include "edificios.h"

using namespace std;

/************************** setters **************************/
string &Edificio::setnome(string a){
    nome=a;
    return nome;
}

string &Edificio::setAbreviatura(string a){
    abreviatura=a;
    return abreviatura;
}

bool &Edificio::setEstado(bool e){
    estado=e;
    return estado;
}

int &Edificio::setLinha(int l){
    linha=l;
    return linha;
}

int &Edificio::setColuna(int c){
    coluna=c;
    return coluna;
}

/************************** getters **************************/
string &Edificio::getNome(){ return nome; }

string &Edificio::getAbreviatura(){ return abreviatura; }

bool &Edificio::getEstado(){ return estado; }

int &Edificio::getLinha(){ return linha; }

int &Edificio::getColuna(){ return coluna; }