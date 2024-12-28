#ifndef PEZZO_H
#define PEZZO_H

#include "texture.h"
#include "resource_manager.h"
#include "shader.h"

#include <glad/glad.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

class Giocatore;

enum class TipologiaPezzo{
    PEDONE,
    TORRE,
    CAVALLO,
    ALFIERE,
    REGINA,
    RE
};

class Pezzo{

    private:
        const int valore;
        Giocatore *giocatore;
        unsigned int quadVAO;

    public:
        Texture2D texture;
        Pezzo(Giocatore *giocatore, int valore, int riga, int colonna, Texture2D &texture);

        int riga;
        int colonna;

    protected:
        Shader shader;
        void inizializzaTexture();
        
        
};

#endif