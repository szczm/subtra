#version 330 core

in vec4 vertexColor;
in vec2 texcoord;

out vec4 outColor;

uniform sampler2D albedo;

void main()
{
    vec4 color = vertexColor * texture(albedo, texcoord);

    outColor = color;
}