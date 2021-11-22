#include "comandos.h"

using namespace std;

string Comando::getAsString() const {
    ostringstream os;

    os << "Comando: " << getNome() << ' ' << args << endl;
    os << "Descricao: " << descr << endl;

    return os.str();
}