//
// Created by serco on 17/11/2021.
//

#ifndef PROJECTPOO_ZONAS_H
#define PROJECTPOO_ZONAS_H

#include "includes.h"
#include "edificios.h"
#include "trabalhadores.h"


class Zona{
    string nome,abreviatura;
    int num;
    static int contador;
    vector <Trabalhador> trabalhadores;
    Edificio h;

public:
    Zona(string n="", string a=""): nome(n), abreviatura(a), num(contador++) {
        //std::cout << "Construindo a Zona: " << nome << " " << abreviatura << " " << num << "\n";
    }

    ~Zona(){
        //std::cout << "Destruindo a zona: " << nome << " " << abreviatura << " " << num <<"\n";
    }

    string &getAbreviaturas(){
        return abreviatura;
    }

    string &getNome(){
        return nome;
    }

    int &getNumZona(){
        return num;
    }

    string &getEdificio(){
        return h.getAbreviatura();
    }

    string &setAbreviaturas(string a){
        abreviatura=a;
        return abreviatura;
    }

    string &setNome(string n){
        nome=n;
        return nome;
    }

    void setEdificio(string nome,string abr,int linha,int coluna){
        h.setAbreviatura(abr);
        h.setnome(nome);
        h.setLinha(linha);
        h.setColuna(coluna);
    }

    int setTrabalhador(Trabalhador &trb, int i, int j){
        if(nome == "Pastagem"){
            trb.setLinha(i);
            trb.setColuna(j);
            trabalhadores.push_back(trb);
            return 1;
        }
        return 0;
    }

    int contraTrabalhadores(int lin, int col){
        int count = 0;
        for (Trabalhador c : trabalhadores)
            if((c.getLinha()==lin) && (c.getColuna()==col))
                count++;
        return count;
    }

    void testfunc(char* outStr, int lin, int col){
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
};

#endif //PROJECTPOO_ZONAS_H
