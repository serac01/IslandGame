// Created by Sérgio Costa on 18/11/2021.

#ifndef PROJECTPOO_INTERFACE_H
#define PROJECTPOO_INTERFACE_H

#include <vector>
#include <fstream>
#include "mundo.h"
#include "comandos.h"

class Interface {
    Mundo& mnd;
    std::vector<Comando> comandos = { {"exec", "Executa um conjunto de comandos existentes em nomeFicheiro.", "<nomeFicheiro>"},
                                 {"cons", "Constrói um edifício de um dado tipo na zona posicionada na linha e coluna.", "<tipo> <linha> <coluna>"},
                                 {"liga", "Liga o edifício que está construído na zona posicionada na linha e coluna.", "<linha> <coluna>"},
                                 {"des", "Desliga o edifício que está construído na zona posicionada na linha e coluna.", "<linha> <coluna>"},
                                 {"move", "Move o trabalhador com o identificador id para a zona posicionada na linha e coluna.", "<id> <linha> <coluna>"},
                                 {"vende", "Vende recursos de um dado tipo e de acordo com quanto se pretende vender.", "<tipo> <quanto>"},
                                 {"cont", "Contrata um trabalhador de um dado tipo e este, e vai para a zona de pasto à espera.", "<tipo>"},
                                 {"list", "Obtém a informação do jogo, globalmente se não for indicada nenhuma linha e coluna", "<linha> <coluna>"},
                                 {"vende", "Vende o edifício existente na zona indicada na linha e coluna especificadas.", "<linha> <coluna>"},
                                 {"next", "Termina a fase de recolha de comandos e desencadeia as ações necessárias ao seu processamento", "<next>"},
                                 {"save", "Grava o estado do jogo em memória, associando-lhe um nome.", "<nome>"},
                                 {"load", "Recupera um dado estado do jogo em memória, identificado ao nome indicado, e carrega-o. O jogo recuperado passa a ser o que está em efeito: os comandos passam a agir sobre este.", "<nome>"},
                                 {"apaga", "Apaga um determinado savegame de memória.", "<nome>"},
                                 {"config", "Lê o ficheiro de texto e extrai dele os preços de contratação dos trabalhadores e de compra dos edifícios.", "<ficheiro>"},
                                 {"debcash", "Adicina a quantidade de € especificada em valor.", "<valor>"},
                                 {"debed", "Adiciona um edifício a custo zero na zona linha, coluna, respeitando as restrições de não poder haver mais do que um edifício na zona.", "<tipo> <linha> <coluna>"},
                                 {"debkill", "Remove o trabalhador com a identificação id.", "<id>"},
                            };

public:
    Interface(Mundo& m) : mnd(m) {}

    ~Interface() {}

    void pedirComandos(std::string cmd="", std::string cmdCompleto="");

    int verificaArgumentos(int argIntroduzidos, int argUsados);

    void contrataTrabalhador(std::string input);

    void constroiEdificio(std::string input);

    int executaComando(std::string input);

    void listaTudo(std::string input);

    void listaZona(std::string input);
};

#endif
