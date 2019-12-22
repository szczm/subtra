#version 330 core

in vec3 vertexColor;
in vec2 texcoord;

out vec4 outColor;

uniform sampler2D testTexture;

void main()
{
    vec4 color = vec4(vertexColor, 1.0) * texture(testTexture, texcoord);

    outColor = color;
}