// SUBTRA Mesh class source
// 2020 Matthias Scherba @szczm_

#include "Mesh.hpp"

#include <iostream>


SUBTRA::Mesh::Mesh (std::string a_path)
{
    const GLfloat vertices[] =
    {
        // position --------   colours -----------   texcoords -
        -1.0f, -1.0f,  0.0f,   1.0f,  1.0f,  0.0f,   0.0f, 0.0f,
         1.0f, -1.0f,  0.0f,   1.0f,  0.0f,  1.0f,   1.0f, 0.0f,
         0.0f,  1.0f,  0.0f,   0.0f,  1.0f,  1.0f,   0.5f, 1.0f
    };


    glGenVertexArrays(1, &m_vao);
    glBindVertexArray(m_vao);

    glGenBuffers(1, &m_vbo);
    glBindBuffer(GL_ARRAY_BUFFER, m_vbo);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    glEnableVertexAttribArray(VertexAttrib::Position);
    glEnableVertexAttribArray(VertexAttrib::Color);
    glEnableVertexAttribArray(VertexAttrib::TexCoord);

    glVertexAttribPointer(VertexAttrib::Position, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), reinterpret_cast<void*>(0));
    glVertexAttribPointer(VertexAttrib::Color, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), reinterpret_cast<void*>(3*sizeof(float)));
    glVertexAttribPointer(VertexAttrib::TexCoord, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), reinterpret_cast<void*>(6*sizeof(float)));

    glBindVertexArray(0);
}

void SUBTRA::Mesh::Bind ()
{
    glBindVertexArray(m_vao);
}