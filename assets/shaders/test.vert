#version 330 core

layout(location = 0) in vec3 inPosition;
layout(location = 1) in vec3 inColor;
layout(location = 2) in vec2 inTexcoord;

out vec3 vertexColor;
out vec2 texcoord;

uniform mat4 testMatrix;
uniform mat4 projection;
uniform mat4 view;

void main()
{
    vertexColor = inColor;
    texcoord = inTexcoord;

    gl_Position = projection * view * testMatrix * vec4(inPosition, 1.0);
}