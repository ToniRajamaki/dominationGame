#include "soldier.h"
#include "tiles/tilebase.h"
#include "interfaces/igameeventhandler.h"
#include "interfaces/iobjectmanager.h"

namespace Student {



Soldier::Soldier(const std::shared_ptr<Course::iGameEventHandler>& eventhandler,
                 const std::shared_ptr<Course::iObjectManager>& objectmanager,
                 const std::shared_ptr<Course::PlayerBase>& owner,
                 const int& tilespaces,
                 const Course::ResourceMap& cost,
                 const Course::ResourceMapDouble& efficiency):
    WorkerBase(
        eventhandler,
        objectmanager,
        owner,
        tilespaces,
        cost,
        efficiency)
{
}

std::string Soldier::getType() const
{
    return "Soldier";
}

bool Soldier::canBePlacedOnTile(const std::shared_ptr<Course::TileBase> &target) const
{
    return target->getOwner() == getOwner() and
            WorkerBase::canBePlacedOnTile(target);
}

void Soldier::doSpecialAction()
{

}


const Course::ResourceMapDouble Soldier::tileWorkAction()
{
    return ConstResourceMaps::SOLDIER_EFFICIENCY;
}


} //namespace
