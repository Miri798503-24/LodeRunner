#include "Monsters.h"

Monsters::Monsters()
{
}

int Monsters::getDirection()
{
    return m_direction;
}

int Monsters::getFall()
{
    return m_isFall;
}

void Monsters::setFall(const bool& flag)
{
    m_isFall = flag;
}
