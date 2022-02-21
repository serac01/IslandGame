#include "comandos.h"

using namespace std;

Comando::Comando(std::string n, std::string a) : nome(n), args(a) { }

string Comando::getNome() const { return nome; }

string Comando::getArgs() const { return args; }