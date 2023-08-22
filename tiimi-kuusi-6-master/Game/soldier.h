#ifndef SOLDIER_H
#define SOLDIER_H


#include "workers/workerbase.h"
#include "resourcelist.h"

namespace Student {


/*!
 * \brief The Soldier class
 */
class Soldier : public Course::WorkerBase
{
public:
    Soldier() = delete;

    Soldier(const std::shared_ptr<Course::iGameEventHandler>& eventhandler,
                   const std::shared_ptr<Course::iObjectManager>& objectmanager,
                   const std::shared_ptr<Course::PlayerBase>& owner,
                   const int& tilespaces = 1,
                   const Course::ResourceMap& cost =
                       ConstResourceMaps::SOLDIER_RECRUITMENT_COST,
                   const Course::ResourceMapDouble& efficiency =
                       ConstResourceMaps::SOLDIER_EFFICIENCY
                );

    virtual ~Soldier() = default;

    virtual bool canBePlacedOnTile(
            const std::shared_ptr<Course::TileBase> &target) const override;

    virtual void doSpecialAction() override;

    virtual std::string getType() const override;

    virtual const Course::ResourceMapDouble tileWorkAction() override;

private:



}; //class
} //namescape)

#endif // SOLDIER_H

