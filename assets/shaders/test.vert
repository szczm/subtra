#version 330 core

layout(location = 0) in vec3 inPosition;
layout(location = 1) in vec3 inColor;
layout(location = 2) in vec2 inTexcoord;

out vec4 vertexColor;
out vec2 texcoord;

uniform mat4 world;
uniform mat4 projection;
uniform mat4 view;

uniform vec4 color;

void main()
{
    vertexColor = vec4(inColor, 1.0) * color;
    texcoord = inTexcoord;

    gl_Position = projection * view * world * vec4(inPosition, 1.0);
}