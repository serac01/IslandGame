#ifndef PROJECTPOO_EDIFICIOS_H
#define PROJECTPOO_EDIFICIOS_H
#include "includes.h"

class Edificio {
    string nome,abreviatura;
    bool estado;
    int linha, coluna;
public:
    Edificio(string n="", string a="   ", int l=0, int c=0): nome(n), abreviatura(a), estado(false), linha(l), coluna(c) {
        std::cout << "Construindo o Edificio: " << nome << " " << abreviatura << " " << estado << " " << linha << " " << coluna << "\n";
    }

    ~Edificio(){
        std::cout << "Destruindo o Edificio: " << nome << " " << abreviatura << " " << estado << " " << linha << " " << coluna << "\n";
    }

    string &getNome(){
        return nome;
    }

    string &getAbreviatura(){
        return abreviatura;
    }

    bool &getEstado(){
        return estado;
    }

    int &getLinha(){
        return linha;
    }

    int &getColuna(){
        return coluna;
    }

    //Setters
    string &setnome(string a){
        nome=a;
        return nome;
    }

    string &setAbreviatura(string a){
        abreviatura=a;
        return abreviatura;
    }

    bool &setEstado(bool e){
        estado=e;
        return estado;
    }

    int &setLinha(int l){
        linha=l;
        return linha;
    }

    int &setColuna(int c){
        coluna=c;
        return coluna;
    }
};


#endif //PROJECTPOO_EDIFICIOS_H
