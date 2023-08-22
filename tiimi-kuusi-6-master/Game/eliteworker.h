#ifndef ELITEWORKER_H
#define ELITEWORKER_H

#include "workers/workerbase.h"
#include "resourcelist.h"

namespace Student {


/*!
 * \brief The EliteWorker class
 */
class EliteWorker  : public Course::WorkerBase
{
public:
    EliteWorker() = delete;

    EliteWorker(const std::shared_ptr<Course::iGameEventHandler>& eventhandler,
                const std::shared_ptr<Course::iObjectManager>& objectmanager,
                const std::shared_ptr<Course::PlayerBase>& owner,
                const int& tilespaces = 1,
                const Course::ResourceMap& cost =
                    ConstResourceMaps::AW_RECRUITMENT_COST,
                const Course::ResourceMapDouble& efficiency =
                    ConstResourceMaps::AW_WORKER_EFFICIENCY);

    virtual ~EliteWorker() = default;

    virtual std::string getType() const override;

    virtual bool canBePlacedOnTile(
            const std::shared_ptr<Course::TileBase> &target) const override;

    virtual void doSpecialAction() override;

    virtual const Course::ResourceMapDouble tileWorkAction() override;

private:

};


}
#endif // ELITEWORKER_H
