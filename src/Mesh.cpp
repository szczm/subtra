// SUBTRA Mesh class source
// 2019 Matthias Scherba @szczm_

#include "Mesh.hpp"

#include <iostream>

void sub::Mesh::init()
{
    glGenVertexArrays(1, &m_VAO);
    glBindVertexArray(m_VAO);

    glGenBuffers(1, &m_VBO);
    glBindBuffer(GL_ARRAY_BUFFER, m_VBO);

    const GLfloat g_vertex_buffer_data[] =
    {
        -1.0f, -1.0f, 0.0f,
        1.0f, -1.0f, 0.0f,
        0.0f,  1.0f, 0.0f,
    };

    glBindBuffer(GL_ARRAY_BUFFER, m_VAO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(g_vertex_buffer_data), g_vertex_buffer_data, GL_STATIC_DRAW);
}

void sub::Mesh::bind()
{
    glBindVertexArray(m_VAO);
}