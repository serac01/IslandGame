#include "zona.h"

using namespace std;

int Zona::contador=0;

Zona::Zona(string n, string a=" "): nome(n), abreviatura(a), num(contador++), flagEdificio(0) { }

Zona::~Zona(){ }

string &Zona::getNome(){ return nome; }

string Zona::getAbreviaturas() { return abreviatura; }

void Zona::setContador(){ contador=0; }

string Zona::getNomeEdificio() {
    if(flagEdificio == 1)
        return edificio->getNome();
    else
        return " ";
}

int Zona::constroiEdificio(std::string nome, float *dinheiro, float *nVigas) {
    float x = 10 - *nVigas;
    int dobraPreco=1;

    if(getNome()=="Montanha")
        dobraPreco=2;

    if(flagEdificio==0){
        if(nome=="minaf" && *dinheiro >= (x * configEdificio[0].getPreco())*dobraPreco){
            *nVigas=0;
            edificio = new MinaF;
            *dinheiro = *dinheiro - (x * configEdificio[0].getPreco())*dobraPreco;
        }
        else if(nome=="minac" && *dinheiro >= (x * configEdificio[1].getPreco())*dobraPreco){
            *nVigas=0;
            edificio = new MinaC;
            *dinheiro = *dinheiro - (x * configEdificio[1].getPreco()*dobraPreco);
        }
        else if(nome=="central" && *dinheiro >= configEdificio[2].getPreco()*dobraPreco){
            edificio = new Central;
            *dinheiro = *dinheiro - configEdificio[2].getPreco()*dobraPreco;
        }
        else if(nome=="bat" && *dinheiro >= configEdificio[3].getPreco()*dobraPreco && *nVigas==10){
            *nVigas=0;
            edificio = new Bateria;
            *dinheiro = *dinheiro - configEdificio[3].getPreco()*dobraPreco;
        }
        else if(nome=="fund" && *dinheiro >= configEdificio[4].getPreco()*dobraPreco){
            edificio = new Fundicao;
            *dinheiro = *dinheiro - configEdificio[4].getPreco()*dobraPreco;
        }
        else if(nome=="serr" && *dinheiro >= configEdificio[5].getPreco()*dobraPreco){
            edificio = new Serracao;
            *dinheiro = *dinheiro - configEdificio[5].getPreco()*dobraPreco;
        }
        else{ return 0; }
        flagEdificio=1;
        return 1;
    }
    return 0;
}

int Zona::constroiEdificioGratis(std::string nome) {
    if(flagEdificio==0){
        if(nome=="minaf" ) edificio = new MinaF;
        else if(nome=="minac") edificio = new MinaC;
        else if(nome=="central") edificio = new Central;
        else if(nome=="bat") edificio = new Bateria;
        else if(nome=="fund") edificio = new Fundicao;
        else if(nome=="serr") edificio = new Serracao;
        else{ return 0; }
        flagEdificio=1;
        return 1;
    }
    return 0;
}

int Zona::temEdificio() { return flagEdificio; }

bool Zona::estadoEdificio() { return edificio->getEstado(); }

int Zona::ligaEdificio() {
    if(flagEdificio){
        edificio->setEstado(true);
        return 1;
    }
    return 0;
}

int Zona::upEdificio(float *din) {
    if(flagEdificio){
        float x=*din;
        *din = edificio->upgradeNivel(x);
        return 1;
    }
    return 0;
}

int Zona::desligaEdificio() {
    if(flagEdificio){
        edificio->setEstado(false);
        return 1;
    }
    return 0;
}

int Zona::apagaEdificio() {
    if(flagEdificio){
        delete edificio;
        flagEdificio=0;
        return 1;
    }
    return 0;
}

float Zona::getPrecoEdificio(std::string nome) {
    int i=0;
    for(auto pos=configEdificio.begin(); pos!=configEdificio.end(); pos++, i++)
        if(nome == "minac" || nome == "minaf" || nome == "bat"){
            delete edificio;
            flagEdificio=0;
            return pos->getPreco()*10;
        }else if(nome == pos->getNome()){
            delete edificio;
            flagEdificio=0;
            return pos->getPreco();
        }
    return 0;
};

void Zona::setPrecoEdificio(std::vector<std::string> words) {
    for(auto pos=words.begin(); pos!=words.end(); pos++){
        if(*pos == "minaf"){
            pos++;
            configEdificio[0].setPreco(stoi(*pos));
        }
        else if(*pos == "minac"){
            pos++;
            configEdificio[1].setPreco(stoi(*pos));
        }
        else if(*pos == "central"){
            pos++;
            configEdificio[2].setPreco(stoi(*pos));
        }
        else if(*pos == "bat"){
            pos++;
            configEdificio[3].setPreco(stoi(*pos));
        }
        else if(*pos == "fund"){
            pos++;
            configEdificio[4].setPreco(stoi(*pos));
        }
        else if(*pos == "serr"){
            pos++;
            configEdificio[5].setPreco(stoi(*pos));
        }
        else
            pos++;
    }
};

float Zona::getArmazemEd() { return edificio->getArmazem(); };

float Zona::setArmazemEd(float n) { edificio->setArmazem(n); };

float Zona::setArmazemEdReduz(float n) { edificio->setArmazemReduz(n); };

float Zona::setArmazemEdDobra(float n) { edificio->setArmazemDobra(n); };

float Zona::getPD() { return edificio->getProbDesabar(); };