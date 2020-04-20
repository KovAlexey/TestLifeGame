#ifndef LIFEWORLD_H
#define LIFEWORLD_H
#include <QGuiApplication>
#include <QDebug>

class LifeWorld
{
public:
    enum CellStatus{Death, Live};

    LifeWorld(int _worldX, int _worldY);
    ~LifeWorld();

    void set(int _posX, int _posY, CellStatus status);
    void step();

private:
    int m_WorldX, m_WorldY;
    int** m_World;
    void updateState(int _posX, int posY, int **p_world);
};

#endif // LIFEWORLD_H
