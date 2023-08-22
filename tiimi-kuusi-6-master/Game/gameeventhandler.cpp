#include "gameeventhandler.h"
#include "exceptions/baseexception.h"


namespace Student {


GameEventHandler::GameEventHandler()
{

}

std::pair<Course::BasicResource, int> GameEventHandler::getRandomResource()
{

    std::pair<Course::BasicResource, int> rng_resource_pair = {};

    int resource_type = (rand()%5)+1;
    int amount = ((rand()%120+20)*5);

    switch (resource_type) {

    case 1: rng_resource_pair = {Course::BasicResource::MONEY,amount}; break;

    case 2: rng_resource_pair = {Course::BasicResource::FOOD,amount}; break;

    case 3: rng_resource_pair = {Course::BasicResource::WOOD,amount}; break;

    case 4: rng_resource_pair = {Course::BasicResource::STONE,amount}; break;

    case 5: rng_resource_pair = {Course::BasicResource::ORE,amount}; break;

    default: break;
    }
    return rng_resource_pair;
}

std::map<Course::BasicResource, int> GameEventHandler::getProduction(std::shared_ptr<Course::TileBase> tile)
{
    Course::ResourceMapDouble worker_efficiency = {
        {Course::BasicResource::NONE, 0},
        {Course::BasicResource::MONEY, 0},
        {Course::BasicResource::FOOD, 0},
        {Course::BasicResource::WOOD, 0},
        {Course::BasicResource::STONE, 0},
        {Course::BasicResource::ORE, 0}
    };
    Course::ResourceMap workers_upkeep_cost;

    Course::ResourceMap total_production = tile->BASE_PRODUCTION;
    auto m_workers = tile->getWorkers();
    auto m_buildings = tile->getBuildings();

    //Olettaa etta workerit ovat tyytyvaisia. "satisfied".
    for( auto worker : m_workers)
    {
     Course::ResourceMapDouble efficiency = worker->WORKER_EFFICIENCY;
        efficiency = multiplyResourceMapDoubles
                (efficiency,ConstResourceMaps::WORKER_SATISFACTIONER);


        worker_efficiency = mergeResourceMapDoubles(worker_efficiency, efficiency);
    }
    total_production = multiplyResourceMap(tile->BASE_PRODUCTION, worker_efficiency);

    if(m_workers.size() != 0)
    {
        for( auto building : m_buildings)
        {
            Course::ResourceMap production = building->PRODUCTION_EFFECT;

            total_production = mergeResourceMaps(total_production,
                                                 production);
        }
    }
    //Workerien ruoka- ja rahakulut.
    workers_upkeep_cost = calculate_upkeep(m_workers);
    total_production = mergeResourceMaps(total_production,workers_upkeep_cost);

    return total_production;
}

Course::ResourceMap GameEventHandler::calculate_upkeep(std::vector<std::shared_ptr<Course::WorkerBase>> workers)
{
    Course::ResourceMap workers_upkeep_cost = {
        {Course::BasicResource::MONEY, 0},
        {Course::BasicResource::FOOD, 0},
    };

    for (auto worker : workers)
    {
        if(worker->getType() == "BasicWorker")
        {
            workers_upkeep_cost[Course::BasicResource::MONEY] -= 1;
            workers_upkeep_cost[Course::BasicResource::FOOD] -= 1;
        } else if(worker->getType() == "AdvancedWorker")
        {
            workers_upkeep_cost[Course::BasicResource::MONEY] -= 2;
            workers_upkeep_cost[Course::BasicResource::FOOD] -= 2;
        } else if(worker->getType() == "EliteWorker")
        {
            workers_upkeep_cost[Course::BasicResource::MONEY] -= 3;
            workers_upkeep_cost[Course::BasicResource::FOOD] -= 3;
        } else if(worker->getType() == "Soldier"){
            workers_upkeep_cost[Course::BasicResource::MONEY] -= 0;
            workers_upkeep_cost[Course::BasicResource::FOOD] -= 0;
        } else{

            throw Course::BaseException("No upkeep cost for worker in GEhandler calculate_upkeep!");
}


}
     return workers_upkeep_cost;
}

bool GameEventHandler::modifyResource(std::shared_ptr<Course::PlayerBase> player, Course::BasicResource resource, int amount)
{

    std::shared_ptr<Student::Player> pl = std::dynamic_pointer_cast<Student::Player>(player);

    Course::ResourceMap player_resources = pl->get_player_resources();

    player_resources[resource] += amount;

    pl->save_player_resources(player_resources);

    return true;

}

bool GameEventHandler::modifyResources(std::shared_ptr<Course::PlayerBase> player, Course::ResourceMap resources)
{
    if(player == nullptr) //Jos tilella ei ole omistajaa, player on nullptr.
    {
        return false;
    }
    std::shared_ptr<Student::Player> pl = std::dynamic_pointer_cast<Student::Player>(player);

    Course::ResourceMap new_resources = mergeResourceMaps(pl->get_player_resources(),resources);

    pl->save_player_resources(new_resources);

    return true;
}

bool GameEventHandler::obj_placement_permission(std::shared_ptr<Course::TileBase> tile,
                                                std::shared_ptr<Course::iObjectManager> ObjectManager,
                                                std::shared_ptr<Student::Player> current_player)
{
    std::vector<Course::Coordinate> neighbours = tile->getCoordinatePtr()->neighbours(1);

    //Lisataan kohde tiili omiin naapureihinsa.
    neighbours.push_back(tile->getCoordinate());

    for(auto n : neighbours)
    {
        try
        {
            auto n_tile = ObjectManager->getTile(n);
            if(n_tile->getBuildingCount() > 0 and
                    n_tile->getOwner() == current_player)
            {
                return true;
            }

        } catch (...)
        {

        }
    }
    return false;
}



}
