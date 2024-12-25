#ifndef PEZZO_H
#define PEZZO_H

//#include "Giocatore.h"

// class Posizione{
//     private:
//         int riga, colonna;

//     public:
//         int getRiga();
//         int getColonna();

//         void setRiga();
//         void setColonna();
// };

class Giocatore;

class Pezzo{

    private:
        const int valore;
        int riga;
        int colonna;
        Giocatore *giocatore;

    public:
        Pezzo(Giocatore *giocatore, int valore, int riga, int colonna);

        
        
};

#endif