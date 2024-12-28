#ifndef PEZZO_H
#define PEZZO_H

#include "texture.h"
#include "resource_manager.h"
#include "shader.h"

#include <glad/glad.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <memory>

class Giocatore;
class Scacchiera;

class Pezzo{

    private:
        const int valore;
        unsigned int quadVAO;

    public:
        Texture2D texture;
        Pezzo(Giocatore *giocatore, int valore, int riga, int colonna, Texture2D &texture);

        int riga;
        int colonna;
        Giocatore *giocatore;

        virtual bool muoviPezzo(std::unique_ptr<Scacchiera>& scacchiera, int riga, int colonna);

    protected:
        Shader shader;
        void inizializzaTexture();
        
        
};

#endif