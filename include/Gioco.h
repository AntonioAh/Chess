#ifndef GIOCO_H
#define GIOCO_H

#include <memory>

#include "Giocatore.h"

class Gioco{
    private:
        std::unique_ptr<Giocatore> bianco;
        std::unique_ptr<Giocatore> nero;

        std::vector<std::unique_ptr<Pezzo>> scacchiera;


        void costruisciScacchiera();

    public:
        Gioco();
};

#endif