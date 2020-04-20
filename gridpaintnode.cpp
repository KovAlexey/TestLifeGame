#include "gridpaintnode.h"

GridPaintNode::GridPaintNode(int _worldX, int _worldY):m_SizeX(_worldX), m_SizeY(_worldY)
{
    int vertexCount = (_worldX + _worldY) * 2;
    m_geometry = new QSGGeometry(QSGGeometry::defaultAttributes_Point2D(), vertexCount);
    m_geometry->setDrawingMode(QSGGeometry::DrawLines);
    m_geometry->setLineWidth(1);
    setGeometry(m_geometry);
    setFlag(QSGNode::OwnsGeometry);

    m_material = new QSGFlatColorMaterial();
    m_material->setColor(Qt::white);
    setMaterial(m_material);
    setFlag(QSGNode::OwnsMaterial);
}

void GridPaintNode::setGridGeometry(float sizeX, float sizeY)
{
    float left = 10;
    float top = 10;
    float maxX = sizeX - top;
    float maxY = sizeY - left;

    float cellSizeX = maxX / m_SizeX;
    float cellSizeY = maxY / m_SizeY;

    QSGGeometry* pGeometry = geometry();
    pGeometry->allocate((m_SizeX + m_SizeY) * 2 + 4);
    QSGGeometry::Point2D* points = pGeometry->vertexDataAsPoint2D();

    int indexVertex = 0;
    for (float x = left; x <= maxX; x += cellSizeX)
    {
        points[indexVertex].set(x, top);
        indexVertex++;
        points[indexVertex].set(x, maxY);
        indexVertex++;
    }
    points[indexVertex].set(maxX, top);
    indexVertex++;
    points[indexVertex].set(maxX, maxY);
    indexVertex++;

    for (float y = top; y <= maxY; y += cellSizeY)
    {
        points[indexVertex].set(left, y);
        indexVertex++;
        points[indexVertex].set(maxX, y);
        indexVertex++;
    }
    points[indexVertex].set(left, maxY);
    indexVertex++;
    points[indexVertex].set(maxX, maxY);
    indexVertex++;

    markDirty(QSGNode::DirtyGeometry);
}
