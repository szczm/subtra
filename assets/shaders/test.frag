#version 330 core

in vec4 InterpColor;
in vec2 InterpUV;

out vec4 FinalColor;

uniform sampler2D AlbedoTexture;

void main()
{
    vec4 TextureColor = texture(AlbedoTexture, InterpUV);

    FinalColor = TextureColor * InterpColor;
}