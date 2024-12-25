#ifndef ALFIERE_H
#define ALFIERE_H

#include "Pezzo.h"

class Alfiere : public Pezzo{


    public:
        Alfiere(Giocatore *giocatore, int riga, int colonna);
};


#endif