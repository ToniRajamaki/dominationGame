#include "studentoutpost.h"
#include "interfaces/iobjectmanager.h"
#include "tiles/tilebase.h"
#include <iostream>
#include <algorithm>

namespace Student {



StudentOutpost::StudentOutpost(
        const std::shared_ptr<Course::iGameEventHandler>& eventhandler,
        const std::shared_ptr<Course::iObjectManager>& objectmanager,
        const std::shared_ptr<Course::PlayerBase>& owner,
        const int& tilespaces,
        const Course::ResourceMap& buildcost,
        const Course::ResourceMap& production
        ):
    Outpost(eventhandler,
                 objectmanager,
                 owner,
                 tilespaces,
                 buildcost,
                 production)
{
}

//Kaytetaan tarkoituksella Outpost nimea eika StudentOutpost.
std::string StudentOutpost::getType() const
{
    return "Outpost";
}

std::vector<std::shared_ptr<Course::TileBase> > StudentOutpost::ClaimAndConquer()
{
    std::vector< std::shared_ptr<Course::TileBase> > neighbours =
            lockObjectManager()->getTiles(getCoordinatePtr()->neighbours(2));


    for(auto it = neighbours.begin(); it != neighbours.end(); ++it)
    {
        // If the Tile doesn't have owner, set it's owner to buildings owner.
        if( not (*it)->getOwner() )
        {
            (*it)->setOwner(getOwner());
        }
    }
    lockObjectManager()->getTile(getCoordinate())->setOwner(getOwner());

    return neighbours;
}

} //namespace
