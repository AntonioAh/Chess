#ifndef GIOCO_H
#define GIOCO_H

#include <iostream>
#include <memory>

#include "glad/glad.h"
#include <GLFW/glfw3.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "Giocatore.h"

class Gioco{
    private:
        std::unique_ptr<Giocatore> bianco;
        std::unique_ptr<Giocatore> nero;

        std::vector<std::unique_ptr<Pezzo>> scacchiera;


        void costruisciScacchiera();

        void aggiungiGrafica();
        void disegnaScacchiera(unsigned int shaderProgram, unsigned int VAO);
        unsigned int CreateShaderProgram();
        unsigned int createRectangle();

    public:
        Gioco();
};

#endif