#ifndef ADVANCEDWORKER_H
#define ADVANCEDWORKER_H

#include "workers/workerbase.h"
#include "resourcelist.h"

namespace Student {


/*!
 * \brief The AdvancedWorker class
 */
class AdvancedWorker : public Course::WorkerBase
{
public:
    AdvancedWorker() = delete;

    AdvancedWorker(const std::shared_ptr<Course::iGameEventHandler>& eventhandler,
                   const std::shared_ptr<Course::iObjectManager>& objectmanager,
                   const std::shared_ptr<Course::PlayerBase>& owner,
                   const int& tilespaces = 1,
                   const Course::ResourceMap& cost =
                       ConstResourceMaps::AW_RECRUITMENT_COST,
                   const Course::ResourceMapDouble& efficiency =
                       ConstResourceMaps::AW_WORKER_EFFICIENCY
                );


    virtual ~AdvancedWorker() = default;

    virtual std::string getType() const override;

    virtual bool canBePlacedOnTile(
            const std::shared_ptr<Course::TileBase> &target) const override;

    virtual void doSpecialAction() override;

    virtual const Course::ResourceMapDouble tileWorkAction() override;

private:


}; //class

} //namescape

#endif // ADVANCEDWORKER_H
