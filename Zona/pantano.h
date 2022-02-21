#ifndef PROJECTPOO_PANTANO_H
#define PROJECTPOO_PANTANO_H

#include "zona.h"

class Pantano : public Zona{

public:
    Pantano(): Zona("Pantano","pnt") { }

    //passa 10 dias desaba edificios
    int desaba(int dia){
        if(dia>9)
            apagaEdificio();
        return 1;
    }
};

#endif
