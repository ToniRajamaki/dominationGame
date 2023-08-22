#ifndef OBJECTMANAGER_H
#define OBJECTMANAGER_H

#endif // OBJECTMANAGER_H

#include <memory>
#include <vector>
#include "interfaces/iobjectmanager.h"
#include "core/coordinate.h"

namespace Student {

class TileBase;
class Coordinate;

/*!
 * \brief The ObjectManager class
 */
class ObjectManager : public Course::iObjectManager
{
public:
    ObjectManager();
    /**
     * @brief Default destructor.
     */
    virtual ~ObjectManager() = default;


    void addTiles(
            const std::vector<std::shared_ptr<Course::TileBase>>& tiles);


    std::shared_ptr<Course::TileBase> getTile(
            const Course::Coordinate& coordinate);


     std::shared_ptr<Course::TileBase> getTile(const Course::ObjectId& id);


     std::vector<std::shared_ptr<Course::TileBase>> getTiles(
            const std::vector<Course::Coordinate>& coordinates);


     /*!
      * \brief getTiles, palauttaa tiles_ vectorin johon on tallennettu kaikki
      * tiilet
      * \return
      */
     std::vector<std::shared_ptr<Course::TileBase>> getTiles();

    std::vector<std::shared_ptr<Course::TileBase>> tiles_;

};

}

