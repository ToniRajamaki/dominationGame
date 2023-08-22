#include "mapitem.h"
#include "graphics/simplemapitem.h"



namespace Student{

std::map<std::string, QColor> MapItem::c_mapcolors = {{"Grassland", QColor((134), (232), (125))},
                                                     {"Desert", QColor((252), (236), (3))},
                                                     {"Forest", QColor((0), (117), (45))},
                                                     {"Rocky mountains",QColor((149),(150),(150))},
                                                     {"Water", QColor((2), (147), (214))},
                                                     {"Farm", QColor("transparent")},
                                                     {"Outpost", QColor("transparent")},
                                                     {"HeadQuarters", QColor("transparent")},
                                                     {"Mine", QColor("transparent")},
                                                     {"NuclearPlant", QColor("transparent")},
                                                     {"AdvancedWorker", QColor("transparent")},
                                                     {"BasicWorker", QColor("transparent")},
                                                     {"EliteWorker", QColor("transparent")},
                                                     {"Soldier", QColor("transparent")}
                                                     };

MapItem::MapItem(const std::shared_ptr<Course::GameObject> &obj, int size ):
        m_gameobject(obj),
        m_scenelocation(m_gameobject->getCoordinatePtr()->asQpoint()),
        m_size(size)

{
    addNewColor(m_gameobject->getType());
}

QRectF MapItem::boundingRect() const
{
    return QRectF(m_scenelocation * m_size, m_scenelocation * m_size + QPoint(m_size, m_size));
}

void MapItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED( option ); Q_UNUSED( widget );
    painter->setBrush(QBrush(c_mapcolors.at(m_gameobject->getType())));
    if ( m_gameobject->getType() == "" ){
        // Draw different types in different shapes
    }
    painter->drawRect(boundingRect());
}

const std::shared_ptr<Course::GameObject> &MapItem::getBoundObject()
{
    return m_gameobject;
}

void MapItem::updateLoc()
{
    if ( !m_gameobject ){
        delete this;
    } else {
        update(boundingRect()); // Test if necessary
        m_scenelocation = m_gameobject->getCoordinate().asQpoint();
    }
}

bool MapItem::isSameObj(std::shared_ptr<Course::GameObject> obj)
{
    return obj == m_gameobject;
}

int MapItem::getSize() const
{
    return m_size;
}

void MapItem::setSize(int size)
{
    if ( size > 0 && size <= 500 ){
        m_size = size;
    }
}

void MapItem::addNewColor(std::string type)
{
    if ( c_mapcolors.find(type) == c_mapcolors.end() ){
        std::size_t hash = std::hash<std::string>{}(type);
        c_mapcolors.insert({type, QColor((hash & 0xFF0000) >> 16, (hash & 0x00FF00) >> 8, (hash & 0x0000FF))});

    }
}

}



