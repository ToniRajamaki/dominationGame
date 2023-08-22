#ifndef DESERT_H
#define DESERT_H

#include "tiles/tilebase.h"
#include "resourcelist.h"

namespace Student {

/*!
 * \brief The Desert class
 */
class Desert : public Course::TileBase
{
public:

    Desert() = delete;


    Desert(const Course::Coordinate& location,
           const std::shared_ptr<Course::iGameEventHandler>& eventhandler,
           const std::shared_ptr<Course::iObjectManager>& objectmanager,
           const unsigned int& max_build = 4,
           const unsigned int& max_work = 4,
           const Course::ResourceMap& production =
            ConstResourceMaps::DESERT_BP);



    virtual ~Desert() = default;
    virtual std::string getType() const override;

};















}


#endif // DESERT_H
