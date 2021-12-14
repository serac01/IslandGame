#include "comandos.h"

using namespace std;

string Comando::getNome() const { return nome; }

string Comando::getArgs() const { return args; }

string Comando::getAsString() const {
    ostringstream os;

    os << "Comando: " << getNome() << ' ' << args << endl;
    os << "Descricao: " << descr << endl;

    return os.str();
}