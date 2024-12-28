#include "Gioco.h"
#include "Pedone.h"
#include "Torre.h"
#include "Cavallo.h"
#include "Alfiere.h"
#include "Re.h"
#include "Regina.h"

#include "stb_image.h"

#include "sprite_renderer.h"

#include <algorithm>

SpriteRenderer *Renderer;

Gioco::Gioco(unsigned int width, unsigned int height) : Width(width), Height(height) {

}


// void Gioco::costruisciScacchiera(){
//     scacchiera.resize(64);

//     bianco = std::make_unique<Giocatore>(Colore::BIANCO);
//     nero = std::make_unique<Giocatore>(Colore::NERO);

//     for (int i = 0; i < 8; i++){
//         scacchiera[8 + i] = std::make_unique<Pedone>(bianco.get(), 1, i);
//         scacchiera[48 + i] = std::make_unique<Pedone>(nero.get(), 6, i);
//     }

//     scacchiera[0] = std::make_unique<Torre>(bianco.get(), 0, 0);
//     scacchiera[1] = std::make_unique<Cavallo>(bianco.get(), 0, 1);
//     scacchiera[2] = std::make_unique<Alfiere>(bianco.get(), 0, 2);
//     scacchiera[3] = std::make_unique<Regina>(bianco.get(), 0, 3);
//     scacchiera[4] = std::make_unique<Re>(bianco.get(), 0, 4);
//     scacchiera[5] = std::make_unique<Alfiere>(bianco.get(), 0, 5);
//     scacchiera[6] = std::make_unique<Cavallo>(bianco.get(), 0, 6);
//     scacchiera[7] = std::make_unique<Torre>(bianco.get(), 0, 7);

//     scacchiera[56] = std::make_unique<Torre>(nero.get(), 7, 0);
//     scacchiera[57] = std::make_unique<Cavallo>(nero.get(), 7, 1);
//     scacchiera[58] = std::make_unique<Alfiere>(nero.get(), 7, 2);
//     scacchiera[59] = std::make_unique<Regina>(nero.get(), 7, 3);
//     scacchiera[60] = std::make_unique<Re>(nero.get(), 7, 4);
//     scacchiera[61] = std::make_unique<Alfiere>(nero.get(), 7, 5);
//     scacchiera[62] = std::make_unique<Cavallo>(nero.get(), 7, 6);
//     scacchiera[63] = std::make_unique<Torre>(nero.get(), 7, 7);

//     for (int i = 0; i < 16; i++)
//         bianco->aggiungiPezzo(scacchiera[i].get());

//     for (int i = 48; i < 64; i++)
//         nero->aggiungiPezzo(scacchiera[i].get());
// }


void Gioco::Init(){
    selezionato = false;
    lato = Width / 8.0f;

    ResourceManager::LoadShader("../src/sprite.vs", "../src/sprite.fs", nullptr, "sprite");
    ResourceManager::LoadShader("../src/scacchiera.vs", "../src/scacchiera.fs", nullptr, "scacchiera");

    glm::mat4 projection = glm::ortho(0.0f, static_cast<float>(this->Width), static_cast<float>(this->Height), 0.0f, -1.0f, 1.0f);
    ResourceManager::GetShader("scacchiera").Use().SetMatrix4("projection", projection);
    ResourceManager::GetShader("sprite").Use().SetInteger("sprite", 0);
    ResourceManager::GetShader("sprite").SetMatrix4("projection", projection);

    ResourceManager::LoadTexture("../resources/board.jpg", false, "pedone");
    ResourceManager::LoadTexture("../resources/torre_bianca senza sfondo.png", true, "torre_bianca");
   // ResourceManager::LoadTexture("../resources/torre_nera.jpg", false, "torre_nera");

    Renderer = new SpriteRenderer(ResourceManager::GetShader("sprite"));
    scacchiera = std::make_unique<Scacchiera>(ResourceManager::GetShader("scacchiera"), Width);
    turno = Colore::BIANCO;
}

void Gioco::Render(){    
    scacchiera->Render();

    for (auto &p : scacchiera->getAllPieces()){
        if (p.get()){
            Renderer->DrawSprite(p.get()->texture, glm::vec2(p.get()->colonna * 100, p.get()->riga * 100), glm::vec2(100, 100));
        }
    }
}

void Gioco::Muovi(){
    Pezzo *partenza = scacchiera->getPezzo(rigaPartenza, colonnaPartenza).get();
   // Pezzo *arrivo = scacchiera->pezzi[rigaArrivo * 8 + colonnaArrivo].get();

    if (partenza == nullptr || partenza->giocatore->getColore() != turno){
        return ;
    }

    bool valido = partenza->muoviPezzo(scacchiera, rigaArrivo, colonnaArrivo);
    if (valido){
        turno = turno == Colore::BIANCO ? Colore::NERO : Colore::BIANCO;
    }

    int a = 0;

}