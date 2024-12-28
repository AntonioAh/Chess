#ifndef ALFIERE_H
#define ALFIERE_H

#include "Pezzo.h"

class Alfiere : public Pezzo{


    public:
        Alfiere(Giocatore *giocatore, int riga, int colonna, Texture2D &texture);

        bool muoviPezzo(std::unique_ptr<Scacchiera>& scacchiera, int rigaArrivo, int colonnaArrivo) override;
};


#endif