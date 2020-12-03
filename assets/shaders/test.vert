#version 330 core

layout(location = 0) in vec3 VertexPosition;
layout(location = 1) in vec3 VertexColor;
layout(location = 2) in vec2 VertexUV;

out vec4 InterpColor;
out vec2 InterpUV;

uniform mat4 World;
uniform mat4 Projection;
uniform mat4 View;
uniform vec4 Tint;

void main()
{
    InterpColor = vec4(VertexColor, 1.0) * Tint;
    InterpUV = VertexUV;

    gl_Position = Projection * View * World * vec4(VertexPosition, 1.0);
}