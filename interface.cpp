#include "interface.h"

void Interface::pedirComandos() {
    string cmdLido;
    int flag;
    while (1) {
        flag=0;
        cout << "\nComandos disponiveis:";
        for (Comando c : comandos)
                cout << ' ' << c.getNome();

        cout << "\nCMD: ";
        string input;
        getline(cin, input);

        cmdLido = input.substr(0, input.find(" "));

        for (Comando c : comandos)
            if(c.getNome() == cmdLido)
                flag = 1;

        if (flag == 1)
            cout << "\nComando executado com sucesso!" << endl;
        else
            return;
    }
}