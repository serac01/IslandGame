// Created by Sérgio Costa on 17/11/2021.

#ifndef PROJECTPOO_ILHA_H
#define PROJECTPOO_ILHA_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <iterator>
#include "../Zona/zona.h"
#include "../Zona/deserto.h"
#include "../Zona/pastagem.h"
#include "../Zona/floresta.h"
#include "../Zona/montanha.h"
#include "../Zona/pantano.h"
#include "../Zona/zonaX.h"

#include "../Trabalhadores/trabalhadores.h"

class Ilha{
    int linha, coluna;
    float dinheiroDisponivel;
    static int diaSimulacao;
    Zona ***arrayZonas;
    std::vector <Trabalhador *> trabalhadores;
    std::vector <float> configPrecoTrab {{15},{20},{10}}; //oper-len-miner

public:
    Ilha(int lin=3, int col=3);

    ~Ilha();

    //funções para auxiliar na criação e destruição da ilha
    void criaIlha();
    void resizeIlha(int nLinha, int nColuna);
    void destroiIlha();

    //Getters e setters
    int &getLinha();
    int &getColuna();

    //Outras
    int preparaEdificio(std::string nome, int lin, int col);
    int ligaEdificio(int linha, int coluna);
    int desligaEdificio(int linha, int coluna);
    int upgradeEdificio(int linha, int coluna);
    int vendeEdificio(int lin, int col);
    int vendeRecurso(std::string nome, float quantidade);
    int contrataTrabalhador(std::string nome);
    int moveTrabalhador(std::string id, int linha, int coluna);
    int getNumTrabalhadoresZona(int linha, int coluna, std::string nome="undefined");
    std::string getNomeTrabalhadoresZona(int linha, int coluna);
    int leConfig(std::string nomeF);
    void amanhecer();
    void anoitecer();
    std::string informacaoIlha();
    std::string list();
    std::string listZona(int lin, int col);

    //Funções para debug
    void debcash(float cash);
    void debed(std::string tipo, int linha, int coluna);
    void debkill(std::string id);

    //Funções auxiliares
    std::string getAbrZona(int lin, int col);
    std::string getEdificioZona(int lin, int col);
    std::vector<std::string> dividePalavras(std::string frase);
    std::vector<std::string> getZonasAdj(int linha, int coluna);
    std::vector<std::string> getEdificioAdj(int linha, int coluna);

};

#endif