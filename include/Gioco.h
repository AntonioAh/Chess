#ifndef GIOCO_H
#define GIOCO_H

#include <iostream>
#include <memory>


#include "Giocatore.h"
#include "scacchiera.h"
#include "resource_manager.h"


class Gioco{
    // private:
    //     std::unique_ptr<Giocatore> bianco;
    //     std::unique_ptr<Giocatore> nero;

    //     std::vector<std::shared_ptr<Pezzo>> scacchiera;
    //     void costruisciScacchiera();



    public:
        unsigned int Width, Height;

        bool selezionato;
        int rigaPartenza, colonnaPartenza;
        int rigaArrivo, colonnaArrivo;

        float lato;

        Gioco(unsigned int width, unsigned int height);
        void Init();
        void Render();

        std::unique_ptr<Scacchiera> scacchiera;
        Giocatore *turno;
        void Muovi();

};

#endif