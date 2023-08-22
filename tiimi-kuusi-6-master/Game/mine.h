#ifndef MINE_H
#define MINE_H

#include "buildings/buildingbase.h"
#include "resourcelist.h"

namespace Student {


/*!
 * \brief The Mine class
 */
class Mine : public Course::BuildingBase
{
public:
    Mine();

    explicit Mine(
            const std::shared_ptr<Course::iGameEventHandler>& eventhandler,
            const std::shared_ptr<Course::iObjectManager>& objectmanager,
            const std::shared_ptr<Course::PlayerBase>& owner,
            const int& tilespaces = 1,
            const Course::ResourceMap& buildcost =
            ConstResourceMaps::MINE_BUILD_COST,
            const Course::ResourceMap& production =
            ConstResourceMaps::MINE_PRODUCTION
            );


    virtual ~Mine() = default;


    virtual std::string getType() const override;


}; //class
} //namespace

#endif // MINE_H
