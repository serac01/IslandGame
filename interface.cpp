#include "interface.h"

int verificaArgumentos(int argIntroduzidos, int argUsados){
    if(argIntroduzidos != argUsados) {
        cout << "Introduziu um numero invalido de argumentos!" << endl;
        return 0;
    }
    return 1;
}

void Interface::pedirComandos() {
    string cmdLido, novoS, input,argumentos;
    int flag,i,countArg,countArgCmd;

    while (1) {
        flag=0;
        cout << "\nComandos disponiveis:";
        for (Comando c : comandos)
                cout << ' ' << c.getNome();

        //Pedir comandos
        cout << "\nCMD: ";
        getline(cin, input);

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

        cout << "\n\n\tA funcao escolhida tem de agrumentos " << ++countArgCmd << " inseriu " << countArg << " argumentos que sao: " << argumentos << endl;

        if (flag == 1){
            if(cmdLido == "exec"){ if(verificaArgumentos(countArg,countArgCmd)) cout << "\n\tEscreveu o comando exec!" << endl; }
            else if(cmdLido == "cons"){ if(verificaArgumentos(countArg,countArgCmd)) cout << "\n\tEscreveu o comando cons!" << endl; }
            else if(cmdLido == "liga"){ if(verificaArgumentos(countArg,countArgCmd)) cout << "\n\tEscreveu o comando liga!" << endl; }
            else if(cmdLido == "des"){ if(verificaArgumentos(countArg,countArgCmd)) cout << "\n\tEscreveu o comando des!" << endl; }
            else if(cmdLido == "move"){ if(verificaArgumentos(countArg,countArgCmd)) cout << "\n\tEscreveu o comando move!" << endl; }
            else if(cmdLido == "vende"){ if(verificaArgumentos(countArg,countArgCmd)) cout << "\n\tEscreveu o comando vende!" << endl; }
            else if(cmdLido == "cont"){ if(verificaArgumentos(countArg,countArgCmd)) cout << "\n\tEscreveu o comando cont!" << endl; }
            else if(cmdLido == "list"){ if(verificaArgumentos(countArg,countArgCmd)) cout << "\n\tEscreveu o comando list!" << endl; }
            else if(cmdLido == "next"){ if(verificaArgumentos(countArg,countArgCmd)) cout << "\n\tEscreveu o comando next!" << endl; }
            else if(cmdLido == "save"){ if(verificaArgumentos(countArg,countArgCmd)) cout << "\n\tEscreveu o comando save!" << endl; }
            else if(cmdLido == "load"){ if(verificaArgumentos(countArg,countArgCmd)) cout << "\n\tEscreveu o comando load!" << endl; }
            else if(cmdLido == "apaga"){ if(verificaArgumentos(countArg,countArgCmd)) cout << "\n\tEscreveu o comando apaga!" << endl; }
            else if(cmdLido == "config"){ if(verificaArgumentos(countArg,countArgCmd)) cout << "\n\tEscreveu o comando config!" << endl; }
            else if(cmdLido == "debcash"){ if(verificaArgumentos(countArg,countArgCmd)) cout << "\n\tEscreveu o comando debcash!" << endl; }
            else if(cmdLido == "debed"){ if(verificaArgumentos(countArg,countArgCmd)) cout << "\n\tEscreveu o comando debed!" << endl; }
            else if(cmdLido == "debkill"){ if(verificaArgumentos(countArg,countArgCmd)) cout << "\n\tEscreveu o comando debkill!" << endl; }
        }
        else
            if(cmdLido.empty()) cout << "\n\tEscreva um comando!" << endl;
            else{
                cout << "\n\tComando inexistente\n\tFIM!" << endl;
                return;
            }
    }
}