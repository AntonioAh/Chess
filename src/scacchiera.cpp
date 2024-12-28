#include "scacchiera.h"
#include "Pezzo.h"

#include <Pzz.h>

Scacchiera::Scacchiera(Shader &shader, unsigned int lato_schermo) : lato_schermo(lato_schermo){
    this->shader = shader;
    lato  = lato_schermo / 8.0f;
    unsigned int VBO;


    std::vector<float> ver;
    for (int riga = 0; riga < 8; riga++){
        if (riga % 2 == 0){
            for (int colonna = 0; colonna < 4; colonna++){
                ver.push_back(riga * lato);
                ver.push_back(2 * colonna * lato);
                ver.push_back((riga + 1) * lato);
                ver.push_back(2 * colonna * lato);
                ver.push_back(riga * lato);
                ver.push_back((2 * colonna + 1) * lato);

                ver.push_back(riga * lato);
                ver.push_back((2 * colonna + 1) * lato);
                ver.push_back((riga + 1) * lato);
                ver.push_back(2 * colonna * lato);
                ver.push_back((riga + 1) * lato);
                ver.push_back((2 * colonna + 1) * lato);
            }
        }
        else{
           for (int colonna = 0; colonna < 4; colonna++){
                ver.push_back(riga * lato);                 //alto-sinistra
                ver.push_back((2 * colonna + 1) * lato);
                ver.push_back((riga + 1) * lato);           //alto-destra    
                ver.push_back((2 * colonna + 1)* lato);
                ver.push_back(riga * lato);                 //basso-sinistra
                ver.push_back((2 * lato) * (colonna + 1));

                ver.push_back((riga + 1) * lato);           //alto-destra    
                ver.push_back((2 * colonna + 1)* lato);

                ver.push_back(riga * lato);                 //basso-sinistra
                ver.push_back((2 * lato) * (colonna + 1));

                ver.push_back((riga+1) * lato);             //basso-destra
                ver.push_back((2 * lato) * (colonna + 1));
            } 
        }
    }

    vertices = ver.data();

    glGenVertexArrays(1, &this->VAO);
    glGenBuffers(1, &VBO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(float) * ver.size(), vertices, GL_STATIC_DRAW);

    glBindVertexArray(this->VAO);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), (void*)0);
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);

    aggiungiPezzi();

}

Scacchiera::~Scacchiera(){
    glDeleteVertexArrays(1, &this->VAO);
}

void Scacchiera::Render(){
    this->shader.Use();

    glBindVertexArray(VAO);
    glDrawArrays(GL_TRIANGLES, 0, 32 * 6);
}

void Scacchiera::aggiungiPezzi(){
    bianco = std::make_unique<Giocatore>(Colore::BIANCO);
    nero = std::make_unique<Giocatore>(Colore::NERO);

    pezzi.resize(64);

    for (int i = 0; i < 8; i++){
        pezzi[48 + i] = std::make_unique<Pedone>(bianco.get(), 6, i, ResourceManager::GetTexture("pedone"));
        pezzi[8 + i] = std::make_unique<Pedone>(nero.get(), 1, i, ResourceManager::GetTexture("pedone"));
    }

    pezzi[56] = std::make_unique<Torre>(bianco.get(), 7, 0, ResourceManager::GetTexture("torre_bianca"));
    pezzi[57] = std::make_unique<Cavallo>(bianco.get(), 7, 1, ResourceManager::GetTexture("pedone"));
    pezzi[58] = std::make_unique<Alfiere>(bianco.get(), 7, 2, ResourceManager::GetTexture("pedone"));
    pezzi[59] = std::make_unique<Regina>(bianco.get(), 7, 3, ResourceManager::GetTexture("pedone"));
    pezzi[60] = std::make_unique<Re>(bianco.get(), 7, 4, ResourceManager::GetTexture("pedone"));
    pezzi[61] = std::make_unique<Alfiere>(bianco.get(), 7, 5, ResourceManager::GetTexture("pedone"));
    pezzi[62] = std::make_unique<Cavallo>(bianco.get(), 7, 6, ResourceManager::GetTexture("pedone"));
    pezzi[63] = std::make_unique<Torre>(bianco.get(), 7, 7, ResourceManager::GetTexture("pedone"));

    pezzi[0] = std::make_unique<Torre>(nero.get(), 0, 0, ResourceManager::GetTexture("pedone"));
    pezzi[1] = std::make_unique<Cavallo>(nero.get(), 0, 1, ResourceManager::GetTexture("pedone"));
    pezzi[2] = std::make_unique<Alfiere>(nero.get(), 0, 2, ResourceManager::GetTexture("pedone"));
    pezzi[3] = std::make_unique<Regina>(nero.get(), 0, 3, ResourceManager::GetTexture("pedone"));
    pezzi[4] = std::make_unique<Re>(nero.get(), 0, 4, ResourceManager::GetTexture("pedone"));
    pezzi[5] = std::make_unique<Alfiere>(nero.get(), 0, 5, ResourceManager::GetTexture("pedone"));
    pezzi[6] = std::make_unique<Cavallo>(nero.get(), 0, 6, ResourceManager::GetTexture("pedone"));
    pezzi[7] = std::make_unique<Torre>(nero.get(), 0, 7, ResourceManager::GetTexture("pedone"));
}

std::unique_ptr<Pezzo>& Scacchiera::getPezzo(int riga, int colonna){
    return pezzi[riga * 8 + colonna];
}

std::vector<std::unique_ptr<Pezzo>>& Scacchiera::getAllPieces(){
    return pezzi;
}

void Scacchiera::mangia(std::unique_ptr<Pezzo> &primo, std::unique_ptr<Pezzo> &secondo){
    int r = primo->riga, c = primo->colonna;

    std ::cout << "uno\n";

    primo->riga = secondo->riga;
    primo->colonna = secondo->colonna;

    secondo->riga = r;
    secondo->colonna = c;

    
    std::swap(primo, secondo);
}

void Scacchiera::avanza(std::unique_ptr<Pezzo> &pezzo, std::unique_ptr<Pezzo> &vuoto, int nuovaRiga, int nuovaColonna){
    pezzo->riga = nuovaRiga;
    pezzo->colonna = nuovaColonna;

    std::swap(pezzo, vuoto);
}