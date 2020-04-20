#ifndef LIFEWORLD_H
#define LIFEWORLD_H
#include <QGuiApplication>
#include <QObject>
#include <QDebug>

class LifeWorld : public QObject
{
    Q_OBJECT
public:
    enum CellStatus{Death, Live};

    LifeWorld(int _worldX, int _worldY);
    ~LifeWorld();

    void set(int _posX, int _posY, CellStatus status);
    void step();

    int WorldX() const;
    int WorldY() const;

signals:
    void worldReady();

private:
    int m_WorldX, m_WorldY;
    int** m_World;
    void updateState(int _posX, int posY, int **p_world);
};

#endif // LIFEWORLD_H
