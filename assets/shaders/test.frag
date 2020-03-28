#version 330 core

in vec4 v_color;
in vec2 v_coord;

out vec4 o_color;

uniform sampler2D u_albedo;

void main()
{
    vec4 color = v_color * texture(u_albedo, v_coord);

    o_color = color;
}