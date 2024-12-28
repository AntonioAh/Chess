#include "Pedone.h"
#include "scacchiera.h"

#include <iostream>

Pedone::Pedone(Giocatore *giocatore, int riga, int colonna, Texture2D &texture) : Pezzo(giocatore, 1, riga, colonna, texture){
    
}

bool Pedone::muoviPezzo(std::unique_ptr<Scacchiera> &scacchiera, int rigaArrivo, int colonnaArrivo) {
    Colore colore = this->giocatore->getColore();
    bool ris = false;

    if (colore == Colore::BIANCO){
        if (colonna == colonnaArrivo && scacchiera->getPezzo(rigaArrivo, colonnaArrivo) == nullptr){
            if (riga == 6){
                if (rigaArrivo == 5 || rigaArrivo == 4){
                    ris = true;
                }
            }
            else if (riga - rigaArrivo == 1){
                ris = true;
            }
        }
        else if (abs(colonna - colonnaArrivo) == 1 && riga - rigaArrivo == 1){
            if (scacchiera->getPezzo(rigaArrivo, colonnaArrivo) != nullptr && scacchiera->getPezzo(rigaArrivo, colonnaArrivo)->giocatore->getColore() == Colore::NERO)
                ris = true;
        }
    }
    else{
        if (colonna == colonnaArrivo && scacchiera->getPezzo(rigaArrivo, colonnaArrivo) == nullptr){
            if (riga == 1){
                if (rigaArrivo == 2 || rigaArrivo == 3){
                    ris = true;
                }
            }
            else if (riga - rigaArrivo == -1){
                ris = true;
            }
        }
        else if (abs(colonna - colonnaArrivo) == 1 && riga - rigaArrivo == -1){
            if (scacchiera->getPezzo(rigaArrivo, colonnaArrivo) != nullptr && scacchiera->getPezzo(rigaArrivo, colonnaArrivo)->giocatore->getColore() == Colore::BIANCO)
                ris = true;
        }
    }

    if (ris){
        scacchiera->muovi(scacchiera->getPezzo(riga, colonna), scacchiera->getPezzo(rigaArrivo, colonnaArrivo), rigaArrivo, colonnaArrivo);
        return true;  
    }

    return false;
}