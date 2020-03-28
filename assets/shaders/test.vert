#version 330 core

layout(location = 0) in vec3 i_pos;
layout(location = 1) in vec3 i_color;
layout(location = 2) in vec2 i_coord;

out vec4 v_color;
out vec2 v_coord;

uniform mat4 u_world;
uniform mat4 u_proj;
uniform mat4 u_view;
uniform vec4 u_color;

void main()
{
    v_color = vec4(i_color, 1.0) * u_color;
    v_coord = i_coord;

    gl_Position = u_proj * u_view * u_world * vec4(i_pos, 1.0);
}