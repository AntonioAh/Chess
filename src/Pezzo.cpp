#include "Pezzo.h"

Pezzo::Pezzo(Giocatore *giocatore, int valore, int riga, int colonna, Texture2D &texture) : giocatore{giocatore},
                                                                        valore{valore}, riga{riga}, colonna{colonna}, 
                                                                        texture{texture} {


}

bool Pezzo::muoviPezzo(std::unique_ptr<Scacchiera> &scacchiera, int riga, int colonna){
    return false;
}
