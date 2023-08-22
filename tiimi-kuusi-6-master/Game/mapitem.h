#ifndef MAPITEM_H
#define MAPITEM_H
#include <QGraphicsItem>
#include <QPainter>
#include <QObject>
#include "tiles/tilebase.h"
#include "buildings/buildingbase.h"
#include "objectmanager.h"
#include "gameeventhandler.h"
#include "buildings/farm.h"


#include <memory>
#include <map>

#include "core/gameobject.h"

namespace Student {

/*!
 * \brief The MapItem class
 */
class MapItem : public QGraphicsItem
{

public:
    MapItem(const std::shared_ptr<Course::GameObject> &obj, int size);

    QRectF boundingRect() const override;

    void paint(QPainter *painter,
               const QStyleOptionGraphicsItem *option,
               QWidget *widget);

    const std::shared_ptr<Course::GameObject> &getBoundObject();

    void updateLoc();

    bool isSameObj(std::shared_ptr<Course::GameObject> obj);

    int getSize() const;

    void setSize(int size);

private:
    const std::shared_ptr<Course::GameObject> m_gameobject;
    QPoint m_scenelocation;
    int m_size;


    // mappi johon on lisätty jokaiselle peliobjektille väri (R,G,B)
    static std::map<std::string, QColor> c_mapcolors;


    static void addNewColor(std::string type);
};

}
#endif // MAPITEM_H
