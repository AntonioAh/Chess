#include "shader.h"

#include <iostream>
#include <vector>
#include <glad/glad.h>
#include <glm/glm.hpp>

class Scacchiera{
    public:
        Scacchiera(Shader &shader, unsigned int lato_schermo);
        ~Scacchiera();

        void Render();

    private:
        unsigned int lato_schermo;
        unsigned int VAO;
        Shader shader;
        float *vertices;
};