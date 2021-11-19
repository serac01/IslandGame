#include "interface.h"

void Interface::pedirComandos() {
    string cmdLido, novoS, input;
    int flag,i,countArg;

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
        cout << "\n\tNumero de argumentos: " << countArg << endl;

        //Receber o primeira palavra
        cmdLido = input.substr(0, input.find(" "));

        //Percorrer os nomes todos, se tiver um igual deixa a flag a 1
        for (Comando c : comandos)
            if(c.getNome() == cmdLido)
                flag = 1;

        if (flag == 1){
            if(cmdLido == "exec"){ cout << "\n\tEscreveu o comando exec!" << endl; }
            else if(cmdLido == "cons"){ cout << "\n\tEscreveu o comando cons!" << endl; }
            else if(cmdLido == "liga"){ cout << "\n\tEscreveu o comando liga!" << endl; }
            else if(cmdLido == "des"){ cout << "\n\tEscreveu o comando des!" << endl; }
            else if(cmdLido == "move"){ cout << "\n\tEscreveu o comando move!" << endl; }
            else if(cmdLido == "vende"){ cout << "\n\tEscreveu o comando vende!" << endl; }
            else if(cmdLido == "cont"){ cout << "\n\tEscreveu o comando cont!" << endl; }
            else if(cmdLido == "list"){ cout << "\n\tEscreveu o comando list!" << endl; }
            else if(cmdLido == "next"){ cout << "\n\tEscreveu o comando next!" << endl; }
            else if(cmdLido == "save"){ cout << "\n\tEscreveu o comando save!" << endl; }
            else if(cmdLido == "load"){ cout << "\n\tEscreveu o comando load!" << endl; }
            else if(cmdLido == "apaga"){ cout << "\n\tEscreveu o comando apaga!" << endl; }
            else if(cmdLido == "config"){ cout << "\n\tEscreveu o comando config!" << endl; }
            else if(cmdLido == "debcash"){ cout << "\n\tEscreveu o comando debcash!" << endl; }
            else if(cmdLido == "debed"){ cout << "\n\tEscreveu o comando debed!" << endl; }
            else if(cmdLido == "debkill"){ cout << "\n\tEscreveu o comando debkill!" << endl; }
        }
        else
            if(cmdLido.empty()) cout << "\n\tEscreva um comando!" << endl;
            else{
                cout << "\n\tComando inexistente\n\tFIM!" << endl;
                return;
            }
    }
}