#include "Giocatore.h"
#include "Pezzo.h"

Giocatore::Giocatore(Colore colore) : colore{colore} {

}

void Giocatore::aggiungiPezzo(Pezzo *pezzo){
    pezzi.push_back(pezzo);
}

Colore Giocatore::getColore(){
    return colore;
}