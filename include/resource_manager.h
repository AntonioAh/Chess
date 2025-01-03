#ifndef RESOURCE_MANAGER_H
#define RESOURCE_MANAGER_H

#include <map>
#include <string>

#include "glad/glad.h"
#include "texture.h"
#include "shader.h"

class ResourceManager{
    public:
        static std::map<std::string, Shader> Shaders;
        static std::map<std::string, Texture2D> Textures;

        // loads (and generates) a shader program from file loading vertex, fragment (and geometry) shader's source code. If gShaderFile is not nullptr, it also loads a geometry shader
        static Shader LoadShader(const char *vShaderFile, const char *fShaderFile, const char *gShaderFile, std::string name);
        static Shader &GetShader(std::string name);

        static Texture2D LoadTexture(const char *file, bool alpha, std::string name);
        static Texture2D &GetTexture(std::string name);

        static void clear();

    private:
        ResourceManager() {}

        static Shader loadShaderFromFile(const char *vShaderFile, const char *fShaderFile, const char *gShaderFile = nullptr);
        static Texture2D loadTextureFromFile(const char *file, bool alpha);
};

#endif