// SUBTRA Mesh class source
// 2019 Matthias Scherba @szczm_

#include "Mesh.hpp"

#include <iostream>

SUBTRA::Mesh::Mesh(const std::string& a_path)
{
    glGenVertexArrays(1, &m_vao);
    glBindVertexArray(m_vao);

    glGenBuffers(1, &m_vbo);
    glBindBuffer(GL_ARRAY_BUFFER, m_vbo);

    const GLfloat g_vertex_buffer_data[] =
    {
        -1.0f, -1.0f, 0.0f,
        1.0f, -1.0f, 0.0f,
        0.0f, 1.0f, 0.0f,
    };

    // Bind vertex array
    glBindBuffer(GL_ARRAY_BUFFER, m_vao);
    glBufferData(GL_ARRAY_BUFFER, sizeof(g_vertex_buffer_data), g_vertex_buffer_data, GL_STATIC_DRAW);

    // Bind position vertex attrib
    glEnableVertexAttribArray(VertexAttrib::Position);
    glVertexAttribPointer(VertexAttrib::Position, 3, GL_FLOAT, GL_FALSE, 0, static_cast<void*>(0));

    glBindVertexArray(0);
}

void SUBTRA::Mesh::Bind()
{
    glBindVertexArray(m_vao);
}