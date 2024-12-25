#ifndef CAVALLO_H
#define CAVALLO_H

#include "Pezzo.h"

class Cavallo : public Pezzo{


    public:
        Cavallo(Giocatore *giocatore, int riga, int colonna);
};

#endif