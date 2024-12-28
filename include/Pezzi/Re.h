#ifndef RE_H
#define RE_H

#include "Pezzo.h"

class Re : public Pezzo{


    public:
        Re(Giocatore *giocatore, int riga, int colonna, Texture2D &texture);

        // bool muoviPezzo(Scacchiera *scacchiera, int rigaArrivo, int colonnaArrivo) override;
};

#endif