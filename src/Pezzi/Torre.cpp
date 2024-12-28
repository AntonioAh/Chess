#include "Torre.h"
#include "scacchiera.h"


Torre::Torre(Giocatore *giocatore, int riga, int colonna, Texture2D &texture) : Pezzo(giocatore, 5, riga, colonna, texture){

}

bool Torre::muoviPezzo(std::unique_ptr<Scacchiera> &scacchiera, int rigaArrivo, int colonnaArrivo) {
    Colore colore = this->giocatore->getColore();
    bool ris = true;
    bool trovatoIntermedio = false;
    
    //mpvimento orizzontale
    if (riga == rigaArrivo){
        if (colonna == colonnaArrivo)
            return false;

        int alto = colonna > colonnaArrivo ? colonna : colonnaArrivo;
        int basso = colonna > colonnaArrivo ? colonnaArrivo : colonna;

        for (int i = basso + 1; i < alto; i++){
            std::unique_ptr<Pezzo> &intermedio = scacchiera->getPezzo(riga, i);
            if (intermedio != nullptr)
                ris = false;
        }
    }
    else if (colonna ==  colonnaArrivo){
        int alto = riga > rigaArrivo ? riga : rigaArrivo;
        int basso = riga > rigaArrivo ? rigaArrivo : riga;

        for (int i = basso + 1; i < alto; i++){
            std::unique_ptr<Pezzo> &inter = scacchiera->getPezzo(i, colonna);
            if (inter != nullptr)
                ris = false;
        }
    }
    else{
        return false;
    }

    if (ris){
        std::unique_ptr<Pezzo> &nuovaCasella = scacchiera->getPezzo(rigaArrivo, colonnaArrivo);

        if (nuovaCasella == nullptr || nuovaCasella->giocatore->getColore() != this->giocatore->getColore()){
            scacchiera->muovi(scacchiera->getPezzo(riga, colonna), nuovaCasella, rigaArrivo, colonnaArrivo);
        }
        else{
            ris = false;
        }
    }
    return ris;
}