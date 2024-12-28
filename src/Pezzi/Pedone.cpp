#include "Pedone.h"
#include "scacchiera.h"

#include <iostream>

Pedone::Pedone(Giocatore *giocatore, int riga, int colonna, Texture2D &texture) : Pezzo(giocatore, 1, riga, colonna, texture){
    
}

bool Pedone::muoviPezzo(std::unique_ptr<Scacchiera> &scacchiera, int rigaArrivo, int colonnaArrivo) {
    Colore colore = this->giocatore->getColore();

    if (colore == Colore::BIANCO){
        if (colonna == colonnaArrivo && scacchiera->getPezzo(rigaArrivo, colonnaArrivo) == nullptr){
            if (riga == 6){
                if (rigaArrivo == 5 || rigaArrivo == 4){
                    std ::cout << "prova\n";
                    Scacchiera::avanza(scacchiera->getPezzo(riga, colonna), scacchiera->getPezzo(rigaArrivo, colonnaArrivo), rigaArrivo, colonnaArrivo);
                    return true;
                }
            }
            else if (riga - rigaArrivo == 1){
            //    Scacchiera::scambia(scacchiera->getPezzo(riga, colonna), scacchiera->getPezzo(rigaArrivo, colonnaArrivo));
                return true;
            }
        }
    }

    return false;
}