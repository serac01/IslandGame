#ifndef PROJECTPOO_FLORESTA_H
#define PROJECTPOO_FLORESTA_H

#include "zona.h"

class Floresta : public Zona{
    int nArvores,armazenaArvores;
    float maderiraArmazenada;

public:
    Floresta(): Zona("Floresta","flr"), nArvores((rand() % 21) + 20), armazenaArvores(100), maderiraArmazenada(0) { }

    void maisMadeira(int nDia, int temEdificio){
        if(temEdificio==1 && nArvores!=0)
                nArvores--;
        if(temEdificio==0 && (nDia % 2 == 0) && nArvores < armazenaArvores)
                nArvores++;
    }

    float getMadeiraArmazenada() { return maderiraArmazenada; }

    void setMadeiraArmazenada(float n){ maderiraArmazenada=maderiraArmazenada+n; }

    int produzZona(int nTrabalhadores){
        setMadeiraArmazenada( nTrabalhadores);
        return 1;
    }
};

#endif
