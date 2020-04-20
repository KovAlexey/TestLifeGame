#include "lifeworld.h"

LifeWorld::LifeWorld(int _worldX, int _worldY):m_WorldX(_worldX), m_WorldY(_worldY)
{
    m_World = new int*[_worldX];
    for (int x = 0; x < _worldX; x++)
    {
        m_World[x] = new int[_worldY];
        for (int y = 0; y < _worldY; y++)
            m_World[x][y] = CellStatus::Death;
    }
}

LifeWorld::~LifeWorld()
{

}

void LifeWorld::set(int _posX, int _posY, LifeWorld::CellStatus status)
{
    m_World[_posX][_posY] = status;
}

void LifeWorld::step()
{
    int size = sizeof (int) * m_WorldX * m_WorldY;
    int** tempWorld = (int**)malloc(size);
    memcpy(tempWorld, m_World, size);

    for (int x = 0; x < m_WorldX; x++)
    {
        for (int y = 0; y < m_WorldY; y++)
        {
            updateState(x, y, tempWorld);
        }
    }
    memcpy(m_World, tempWorld, size);
    free(tempWorld);
    emit worldReady();
}

int LifeWorld::WorldX() const
{
    return m_WorldX;
}

int LifeWorld::WorldY() const
{
    return m_WorldY;
}

void LifeWorld::updateState(int _posX, int _posY, int** p_world)
{
    int aliveCellsAround = 0;
    for (int x = -1; x <= 1; x++)
    {
        int currentX = _posX + x;

        if (currentX == m_WorldX)
            currentX = 0;
        else if (currentX < 0)
            currentX = m_WorldX - 1;

        for (int y = -1; y <= 1; y++)
        {
            if (y == 0 && x == 0)
                continue;
            int currentY = _posY + y;

            if (currentY == m_WorldY)
                currentY = 0;
            else if (currentY < 0)
                currentY = m_WorldY - 1;

            int currentState = m_World[currentX][currentY];
            if (currentState == CellStatus::Live)
                    aliveCellsAround++;
        }
    }
    if (aliveCellsAround <= 1 || aliveCellsAround > 3)
    {
        p_world[_posX][_posY] = CellStatus::Death;
    }
    else if (aliveCellsAround == 3)
    {
        p_world[_posX][_posY] = CellStatus::Live;
        qDebug() << "live!";
    }
}
