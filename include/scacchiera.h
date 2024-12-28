#ifndef SCACCHIERA_H
#define SCACCHIERA_H

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

        float lato;

        std::unique_ptr<Giocatore> bianco;
        std::unique_ptr<Giocatore> nero;

        std::unique_ptr<Pezzo>& getPezzo(int riga, int colonna);
        std::vector<std::unique_ptr<Pezzo>>& getAllPieces();

        void muovi(std::unique_ptr<Pezzo> &pezzo, std::unique_ptr<Pezzo> &other, int, int);

    private:
        unsigned int lato_schermo;
        unsigned int VAO;
        Shader shader;
        float *vertices;

        std::vector<std::unique_ptr<Pezzo>> pezzi;
        static int getIndice(int riga, int colonna);


        void aggiungiPezzi();
};

#endif