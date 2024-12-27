#include "scacchiera.h"

Scacchiera::Scacchiera(Shader &shader, unsigned int lato_schermo) : lato_schermo(lato_schermo){
    this->shader = shader;
    const float lato = lato_schermo / 8.0f;
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

}

Scacchiera::~Scacchiera(){
    glDeleteVertexArrays(1, &this->VAO);
}

void Scacchiera::Render(){
    this->shader.Use();

    glBindVertexArray(VAO);
    glDrawArrays(GL_TRIANGLES, 0, 32 * 6);

}