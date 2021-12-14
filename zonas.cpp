#include "zonas.h"

using namespace std;

int Zona::contador=1;

string &Zona::getAbreviaturas(){ return abreviatura; }

string &Zona::getNome(){ return nome; }

string &Zona::getEdificio(){ return h.getAbreviatura(); }

int &Zona::getNumZona(){ return num; }

string &Zona::setAbreviaturas(string a){
    abreviatura=a;
    return abreviatura;
}

string &Zona::setNome(string n){
    nome=n;
    return nome;
}

void Zona::setEdificio(string nome,string abr,int linha,int coluna){
    h.setAbreviatura(abr);
    h.setnome(nome);
    h.setLinha(linha);
    h.setColuna(coluna);
}

int Zona::setTrabalhador(Trabalhador &trb, int i, int j){
    if(nome == "Pastagem"){
        trb.setLinha(i);
        trb.setColuna(j);
        trabalhadores.push_back(trb);
        return 1;
    }
    return 0;
}

int Zona::contaTrabalhadores(int lin, int col){
    int count = 0;
    for (Trabalhador c : trabalhadores)
        if((c.getLinha()==lin) && (c.getColuna()==col))
            count++;
    return count;
}

void Zona::concatTrabalhadores(char* outStr, int lin, int col){
    char str[]="    ";
    int i=0,j;
    string n;

    for (Trabalhador c : trabalhadores)
        if((c.getLinha()==lin) && (c.getColuna()==col) && i<4) {
            n=c.getNome();
            str[i] = n[0];
            i++;
        }

    for(j=0;j<4;j++)
        outStr[j]= toupper(str[j]);
}