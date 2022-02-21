#ifndef PROJECTPOO_MONTANHA_H
#define PROJECTPOO_MONTANHA_H

#include "zona.h"

class Montanha : public Zona{
    float ferroArmazenado;

public:
    Montanha(): Zona("Montanha","mnt"), ferroArmazenado(0) { }

    float getFerroArmazenada() { return ferroArmazenado; }
    void setFerroArmazenado(float n){ ferroArmazenado=ferroArmazenado+n; }

    int produzZona(int nTrabalhadores){
        setFerroArmazenado(nTrabalhadores * 0.1);
        return 1;
    }
};

#endif
