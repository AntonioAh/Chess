#include "Pedone.h"
#include "scacchiera.h"

Pedone::Pedone(Giocatore *giocatore, int riga, int colonna, Texture2D &texture) : Pezzo(giocatore, 1, riga, colonna, texture){
    
}

bool Pedone::muoviPezzo(std::unique_ptr<Scacchiera> &scacchiera, int rigaArrivo, int rigaColonna) {
    Colore colore = this->giocatore->getColore();

    if (colore == Colore::BIANCO){
        if (riga == 6){
            int   a = 0;
        }
    }
}