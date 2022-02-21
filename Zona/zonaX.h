#ifndef PROJECTPOO_ZONAX_H
#define PROJECTPOO_ZONAX_H

#include "zona.h"

class Praia : public Zona{

public:
    Praia(): Zona("Praia","pra") { }

    int desaba(int dia){
        if(dia>9)
            apagaEdificio();
        return 1;
    }
};

#endif
