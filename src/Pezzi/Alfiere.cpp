#include "Alfiere.h"
#include "scacchiera.h"

Alfiere::Alfiere(Giocatore *giocatore, int riga, int colonna, Texture2D &texture) : Pezzo(giocatore, 3, riga, colonna, texture){

}

bool Alfiere::muoviPezzo(std::unique_ptr<Scacchiera>& scacchiera, int rigaArrivo, int colonnaArrivo){
    int p = riga + colonna;
    int a = rigaArrivo + colonnaArrivo;

    int diff = (p - a) > 0 ? p-a : a-p;
    std::unique_ptr<Pezzo> &casellaArrivo = scacchiera->getPezzo(rigaArrivo, colonnaArrivo);

    if (diff == 0)
        return false;
    if (diff % 9 != 0 && diff % 7 != 0)
        return false;
    if (casellaArrivo && casellaArrivo->giocatore->getColore() == this->giocatore->getColore())
        return false;

    // bool alto = riga - rigaArrivo > 0;
    // bool destra = colonnaArrivo - colonna > 0;

    // int scarto;
    // if (destra && alto)
    //     scarto = -7;
    // else if (destra && !alto)
    //     scarto = -9;
    // else if (!destra && alto)
    //     scarto = 7;
    // else if (!destra && !alto)
    //     scarto = 9;

    // diff = (rigaArrivo * 8 + colonnaArrivo) - (riga * 8 + colonna);

    return false;
}

    