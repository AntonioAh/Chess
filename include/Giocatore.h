#ifndef GIOCATORE_H
#define GIOCATORE_H

#include "Pezzo.h"

#include <vector>
#include <memory>



enum Colore{
    BIANCO,
    NERO
};

class Giocatore{
    private:
        const Colore colore;
        std::vector<Pezzo *> pezzi;

    public:
        Giocatore(Colore colore);

        void aggiungiPezzo(Pezzo *);


};

#endif