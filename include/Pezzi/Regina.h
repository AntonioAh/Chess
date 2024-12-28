#ifndef REGINA_H
#define REGINA_H

#include "Pezzo.h"

class Regina : public Pezzo{


    public:
        Regina(Giocatore *giocatore, int riga, int colonna, Texture2D &texture);

        // bool muoviPezzo(Scacchiera *scacchiera, int rigaArrivo, int colonnaArrivo) override;
};


#endif