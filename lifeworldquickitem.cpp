#include "lifeworldquickitem.h"
#include <QQuickWindow>

LifeWorldQuickItem::LifeWorldQuickItem()
{
    setFlag(ItemHasContents, true);
    m_world = new LifeWorld(10, 10);

}


QSGNode *LifeWorldQuickItem::updatePaintNode(QSGNode *oldNode, QQuickItem::UpdatePaintNodeData *)
{
    GraphNode *n= static_cast<GraphNode *>(oldNode);


    if (!n)
    {
        n = new GraphNode();
        n->gridNode = new GridPaintNode(m_world->WorldX(), m_world->WorldY());
        n->gridNode->setGridGeometry(window()->width(), window()->height());
        n->appendChildNode(n->gridNode);
    }

    return n;
}
