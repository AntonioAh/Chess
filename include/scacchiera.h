#include "shader.h"

#include "Giocatore.h"
#include "Pezzo.h"

#include <iostream>
#include <vector>
#include <memory>
#include <glad/glad.h>
#include <glm/glm.hpp>

class Scacchiera{
    public:
        Scacchiera(Shader &shader, unsigned int lato_schermo);
        ~Scacchiera();

        void Render();

        std::vector<std::shared_ptr<Pezzo>> pezzi;

    private:
        unsigned int lato_schermo;
        unsigned int VAO;
        Shader shader;
        float *vertices;

        std::unique_ptr<Giocatore> bianco;
        std::unique_ptr<Giocatore> nero;

        void aggiungiPezzi();
};