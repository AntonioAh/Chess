#include "Pezzo.h"

Pezzo::Pezzo(Giocatore *giocatore, int valore, int riga, int colonna, Texture2D &texture) : giocatore{giocatore},
                                                                        valore{valore}, riga{riga}, colonna{colonna}, 
                                                                        texture{texture} {


}