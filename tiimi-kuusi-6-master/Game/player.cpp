#include "player.h"


namespace Student {


Player::Player(const std::string& name,
               const std::vector<std::shared_ptr<Course::GameObject> > objects):
    Course::PlayerBase(name,objects),
    m_tiles(),
    m_name(name),
    m_objects(),
    has_outpost(false),
    player_resources(Course::ResourceMap(Student::ConstResourceMaps::PLAYER_STARTING_RESOURCES))

{
    for( auto it = objects.begin(); it != objects.end(); ++it)
    {
        m_objects.push_back(std::weak_ptr<Course::GameObject>(*it));
    }

}

Course::ResourceMap Player::get_player_resources()
{
    return player_resources;
}

void Player::save_player_resources(Course::ResourceMap resources)
{
    player_resources = resources;
}

bool Player::does_have_enough_resources(Course::ResourceMap cost)
{
    for (auto resource : cost) {
        if(player_resources[resource.first] - cost[resource.first] < 0 ) {
            return false;
        }
    }
    return true;
}


// tarkistaa onko parametri tiili pelaajan tiili vektorissa
bool Player::already_owned(std::shared_ptr<Course::TileBase> tile)
{

    for(auto pltile : m_tiles)
    {
     if(pltile->getCoordinate().x() == tile->getCoordinate().x()
             and pltile->getCoordinate().y() == tile->getCoordinate().y()){
         return true;
     }
}
    return false;


}

void Player::addtile(std::shared_ptr<Course::TileBase> tile)
{
    m_tiles.push_back(std::shared_ptr<Course::TileBase>(tile));
}

std::vector<std::shared_ptr<Course::TileBase> > Player::get_tiles()
{
    return m_tiles;
}

void Player::player_built_outpost()
{
    has_outpost = true;
}

bool Player::does_player_have_outpost()
{
    return has_outpost;
}




}
