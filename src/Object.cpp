// SUBTRA Object class source
// 2020 Matthias Scherba @szczm_

#include "Object.hpp"


SUBTRA::Object& SUBTRA::Object::operator= (const SUBTRA::Object& a_other)
{
    m_components = a_other.m_components;
    m_transform = a_other.m_transform;
}