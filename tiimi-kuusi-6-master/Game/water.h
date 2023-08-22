#ifndef WATER_H
#define WATER_H

#include "tiles/tilebase.h"
#include "resourcelist.h"


namespace Student{

/*!
 * \brief The Water class
 */
class Water : public Course::TileBase
{
public:
    Water() = delete;

    Water(const Course::Coordinate& location,
          const std::shared_ptr<Course::iGameEventHandler>& eventhandler,
          const std::shared_ptr<Course::iObjectManager>& objectmanager,
          const unsigned int& max_build = 1,
          const unsigned int& max_work = 4,
          const Course::ResourceMap& production =
           ConstResourceMaps::WATER_BP);


    virtual ~Water() = default;

    virtual std::string getType() const override;
};

#endif // WATER_H
}
