#include "comandos.h"

string Comando::getAsString() const {
    ostringstream os;

    os << "Comando: " << getNome() << ' ' << args << endl <<  endl;
    os << "Descricao: " << descr;

    return os.str();
}