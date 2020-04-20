#ifndef LIFEWORLDQUICKITEM_H
#define LIFEWORLDQUICKITEM_H

#include <QQuickItem>
#include "gridpaintnode.h"
#include "lifeworld.h"

class LifeWorldQuickItem : public QQuickItem
{
    Q_OBJECT
public:
    LifeWorldQuickItem();

protected:
    QSGNode *updatePaintNode(QSGNode *, UpdatePaintNodeData *);

private:
    LifeWorld* m_world;
    class GraphNode:public QSGNode{
    public:
        GridPaintNode* gridNode;
    };
};

#endif // LIFEWORLDQUICKITEM_H
