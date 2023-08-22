#ifndef NUCLEARPLANT_H
#define NUCLEARPLANT_H

#include "buildings/buildingbase.h"
#include "resourcelist.h"

namespace Student {


/*!
 * \brief The NuclearPlant class
 */
class NuclearPlant : public Course::BuildingBase
{
public:
    NuclearPlant();
    /*!
     * \brief NuclearPlant
     * \param eventhandler
     * \param objectmanager
     * \param owner
     * \param tilespaces
     * \param buildcost
     * \param production
     */
    explicit NuclearPlant(
            const std::shared_ptr<Course::iGameEventHandler>& eventhandler,
            const std::shared_ptr<Course::iObjectManager>& objectmanager,
            const std::shared_ptr<Course::PlayerBase>& owner,
            const int& tilespaces = 1,
            const Course::ResourceMap& buildcost =
            ConstResourceMaps::NP_BUILD_COST,
            const Course::ResourceMap& production =
            ConstResourceMaps::NP_PRODUCTION
            );

    virtual ~NuclearPlant() = default;

    virtual std::string getType() const override;

}; // class
} //namespace

#endif // NUCLEARPLANT_H
