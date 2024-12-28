#ifndef TORRE_H
#define TORRE_H

#include "Pezzo.h"

class Torre : public Pezzo{


    public:
        Torre(Giocatore *giocatore, int riga, int colonna, Texture2D &texture);
};

#endif