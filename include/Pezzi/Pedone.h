#ifndef PEDONE_H
#define PEDONE_H

#include "Pezzo.h"

class Pedone : public Pezzo{
    
    public:
        Pedone(Giocatore *giocatore, int riga, int colonna);
};

#endif