#include "interface.h"

using namespace std;

void Interface::pedirComandos(string cmd,string cmdCompleto) {
    string input, nome, line;
    int estado=1;

    if(cmd=="exec"){
        //Cortar o nome do ficheiro
        nome = cmdCompleto.substr(5);

        //Abrir o ficheiro
        ifstream nameFileout;
        nameFileout.open(nome);

        while(getline(nameFileout, line) && estado){
            cout << "\n\t> " << line;
            estado=executaComando(line);
        }
    }
    else
        while (estado) {
            cout << "\nLista de Comandos:";
            for (Comando c : comandos)
                cout << ' ' << c.getNome();

            cout << "\n> ";
            getline(cin, input);

            estado=executaComando(input);
        }
}

int Interface::executaComando(string input){
    int flag=0,i,countArg,countArgCmd=0;
    string cmdLido, argumentos;

    //Conta os argumentos
    for(i=0, countArg=0; input[i] != '\0';i++)
        if (input[i] == ' ')
            countArg++;

    //Receber o primeira palavra
    cmdLido = input.substr(0, input.find(" "));

    //Percorrer os nomes todos, se tiver um igual deixa a flag a 1
    for (Comando c : comandos)
        if(c.getNome() == cmdLido){
            flag = 1;
            argumentos = c.getArgs();
            for(i=0, countArgCmd=0; argumentos[i] != '\0';i++)
                if (argumentos[i] == ' ')
                    countArgCmd++;
        }

    countArgCmd++;

    if (flag == 1){
        if(cmdLido == "exec") {
            if (verificaArgumentos(countArg, countArgCmd)) {
                pedirComandos(cmdLido, input);
            }
        }

        else if(cmdLido == "cons") {
            if (verificaArgumentos(countArg, countArgCmd)) {
                constroiEdificio(input);
            }
        }

        else if(cmdLido == "liga"){ if(verificaArgumentos(countArg,countArgCmd)) cout << "\n\tEscreveu o comando liga!" << endl; }
        else if(cmdLido == "des"){ if(verificaArgumentos(countArg,countArgCmd)) cout << "\n\tEscreveu o comando des!" << endl; }
        else if(cmdLido == "move"){ if(verificaArgumentos(countArg,countArgCmd)) cout << "\n\tEscreveu o comando move!" << endl; }
        else if(cmdLido == "vende"){ if(verificaArgumentos(countArg,countArgCmd)) cout << "\n\tEscreveu o comando vende!" << endl; }

        else if(cmdLido == "cont") {
            if (verificaArgumentos(countArg, countArgCmd)) {
                contrataTrabalhador(input);
            }
        }

        else if(cmdLido == "list"){
            if(countArg==0)
                listaTudo(input);
            else if(verificaArgumentos(countArg,countArgCmd)){
                listaZona(input);
            }
        }

        else if(cmdLido == "next"){ if(verificaArgumentos(countArg,countArgCmd)) cout << "\n\tEscreveu o comando next!" << endl; }
        else if(cmdLido == "save"){ if(verificaArgumentos(countArg,countArgCmd)) cout << "\n\tEscreveu o comando save!" << endl; }
        else if(cmdLido == "load"){ if(verificaArgumentos(countArg,countArgCmd)) cout << "\n\tEscreveu o comando load!" << endl; }
        else if(cmdLido == "apaga"){ if(verificaArgumentos(countArg,countArgCmd)) cout << "\n\tEscreveu o comando apaga!" << endl; }
        else if(cmdLido == "config"){ if(verificaArgumentos(countArg,countArgCmd)) cout << "\n\tEscreveu o comando config!" << endl; }
        else if(cmdLido == "debcash"){ if(verificaArgumentos(countArg,countArgCmd)) cout << "\n\tEscreveu o comando debcash!" << endl; }
        else if(cmdLido == "debed"){ if(verificaArgumentos(countArg,countArgCmd)) cout << "\n\tEscreveu o comando debed!" << endl; }
        else if(cmdLido == "debkill"){ if(verificaArgumentos(countArg,countArgCmd)) cout << "\n\tEscreveu o comando debkill!" << endl; }
        return 1;
    }
    else{
        if(cmdLido.empty()){
            cout << "\n\tEscreva um comando!" << endl;
            return 1;
        }else{
            cout << "\n\tComando inexistente\n\tFIM!" << endl;
            return 0;
        }
    }
}

int Interface::verificaArgumentos(int argIntroduzidos, int argUsados){
    if(argIntroduzidos != argUsados) {
        cout << "\tIntroduziu um numero invalido de argumentos!" << endl;
        return 0;
    }
    return 1;
}

void Interface::constroiEdificio(string input){
    int c,l,i=0;
    string nome,linha,coluna;
    const char *abrEdificio[5] = { "mnF","mnC","ele", "bat", "fun"},
            *nomeEdificio[5] = { "Mina de Ferro", "Mina de Carvao","Central Eletrica", "Bateria", "Fundicao"};

    nome = input.substr(5);
    linha = input.substr(9);
    coluna = input.substr(11);
    nome = nome.substr(0, nome.find(" "));
    linha = linha.substr(0, linha.find(" "));

    l = stoi(linha);
    c = stoi(coluna);

    if((l < 0 || l >= mnd.getLinha()) || (c < 0 || c >= mnd.getColuna())){
        cout << "\tZona invalida" << endl;
        return;
    }

    while(nome != abrEdificio[i]){
        if (i>=4)
            break;
        i++;
    }

    if(nome == abrEdificio[i])
        mnd.prencheZonaEdificio(nomeEdificio[i],nome,l,c);
    else
        cout << "\tNao existe esse edificio" << endl;
}

void Interface::contrataTrabalhador(string input){
    int i=0,estado;
    string cmdLido;
    cmdLido = input.substr(5);
    const char *abrTrabalhadores[3] = { "O","M","L"},
            *nomeTrabalhadores[3] = { "operario", "mineiro","lenhador"};

    while(cmdLido != nomeTrabalhadores[i]){
        if (i>=4)
            break;
        i++;
    }

    if(cmdLido == nomeTrabalhadores[i]){
        estado = mnd.prencheZonaTrabalhador(cmdLido);
        if(estado==0)
            cout << "\tNao existe Pastagem" << endl;
    }
    else
        cout << "\tNao existe esse trabalhador" << endl;
}

void Interface::listaTudo(string input){
    mnd.mostraTabela();
    mnd.descTabelaCompleta();
}

void Interface::listaZona(string input){
    int l,c;
    string linha,coluna;
    cout << "\tZona" << endl;

    linha = input.substr(5);
    coluna = input.substr(7);
    linha = linha.substr(0, linha.find(" "));

    l = stoi(linha);
    c = stoi(coluna);

    if((l < 0 || l >= mnd.getLinha()) || (c < 0 || c >= mnd.getColuna())){
        cout << "\tZona invalida" << endl;
        return;
    }

    mnd.mostraTabela();
    mnd.descTabela(l,c);
}