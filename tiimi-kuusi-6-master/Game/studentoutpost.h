#ifndef STUDENTOUTPOST_H
#define STUDENTOUTPOST_H

#include "buildings/outpost.h"
#include "resourcelist.h"
#include "tiles/tilebase.h"

namespace Student {


/*!
 * \brief The StudentOutpost class
 */
class StudentOutpost : public Course::Outpost
{

public:

    StudentOutpost();

    explicit StudentOutpost(
            const std::shared_ptr<Course::iGameEventHandler>& eventhandler,
            const std::shared_ptr<Course::iObjectManager>& objectmanager,
            const std::shared_ptr<Course::PlayerBase>& owner,
            const int& tilespaces = 1,
            const Course::ResourceMap& buildcost = ConstResourceMaps::SOP_BUILD_COST,
            const Course::ResourceMap& production = ConstResourceMaps::SOP_PRODUCTION
            );

    virtual ~StudentOutpost() = default;

    virtual std::string getType() const override;



    /*!
     * \brief ClaimAndConquer, Toimii kuten kurssin Outpostin onBuildAction,
     * mutta rangena 2.
     * \return
     */
    std::vector<std::shared_ptr<Course::TileBase>> ClaimAndConquer();


}; //class

} //namespace

#endif // STUDENTOUTPOST_H
