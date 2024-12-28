#ifndef PEDONE_H
#define PEDONE_H

#include "Pezzo.h"

class Pedone : public Pezzo{
    
    public:
        Pedone(Giocatore *giocatore, int riga, int colonna, Texture2D &texture);

        bool muoviPezzo(std::unique_ptr<Scacchiera>& scacchiera, int rigaArrivo, int colonnaArrivo) override;
};

#endif