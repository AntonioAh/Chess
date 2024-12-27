#version 330 core
layout(location = 0) in vec2 aPos;  // Input vertex position

uniform mat4 projection;
void main()
{
    gl_Position = projection * vec4(aPos.x, aPos.y, 0.0, 1.0);  // Set the position of the vertex
}
