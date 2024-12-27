#ifndef GIOCO_H
#define GIOCO_H

#include <iostream>
#include <memory>


#include "Giocatore.h"

#include "resource_manager.h"


class Gioco{
    private:
        std::unique_ptr<Giocatore> bianco;
        std::unique_ptr<Giocatore> nero;

        std::vector<std::unique_ptr<Pezzo>> scacchiera;
        void costruisciScacchiera();


    public:
        unsigned int Width, Height;

        Gioco(unsigned int width, unsigned int height);
        void Init();
        void Render();
};

#endif