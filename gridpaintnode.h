#ifndef GRIDPAINTNODE_H
#define GRIDPAINTNODE_H
#include <QSGGeometryNode>
#include <QSGFlatColorMaterial>

class GridPaintNode: public QSGGeometryNode
{
public:
    GridPaintNode(int _worldX, int _worldY);
    void setGridGeometry(float sizeX, float sizeY);
private:
    QSGFlatColorMaterial* m_material;
    QSGGeometry* m_geometry;
    int m_SizeX, m_SizeY;
};

#endif // GRIDPAINTNODE_H
