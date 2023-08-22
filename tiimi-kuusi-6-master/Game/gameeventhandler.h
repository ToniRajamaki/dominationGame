#ifndef GAMEEVENTHANDLER_H
#define GAMEEVENTHANDLER_H

#endif // GAMEEVENTHANDLER_H

#include <memory>
#include <vector>
#include "interfaces/igameeventhandler.h"
#include <map>
#include "resourcelist.h"
#include "core/basicresources.h"
#include "tiles/tilebase.h"
#include "player.h"
#include "core/playerbase.h"
#include "desert.h"
#include <iostream>
#include <core/coordinate.h>
#include "interfaces/iobjectmanager.h"
#include <stdlib.h>
#include <stdio.h>
#include <utility>

namespace Student {
class TileBase;
class PlayerBase;
class GameObject;
class Coordinate;

/*!
 * \brief The GameEventHandler class
 */
class GameEventHandler : public Course::iGameEventHandler
{
public:
    GameEventHandler();

    virtual ~GameEventHandler() = default;


    /*!
     * \brief getRandomResource, arpoo resurssin ja luvun väliltä 100-700
     * \return palauttaa pair
     */
    std::pair<Course::BasicResource, int> getRandomResource();


    /*!
     * \brief getProduction palauttaa tilen tuotannon yhdellä erällä huomioiden workerit/buildingit.
     * Olettaa workereiden olevan tyytyväisiä "satisfied".
     * \param tile, jonka tuotanto palautetaan.
     * \return resourcemap tuotannosta.
     */
    std::map<Course::BasicResource, int> getProduction(std::shared_ptr<Course::TileBase> tile);


    /*!
     * \brief calculate_upkeep laskee workereiden kuluttaman ruoka- ja rahamäärän.
     * \param workers vector, joka on saatu halutusta tiilestä.
     * \return resourcemap workereiden yhteenlasketusta kulutuksesta.
     */
    Course::ResourceMap calculate_upkeep(std::vector<std::shared_ptr<Course::WorkerBase>> workers);


    /*!
      * \brief modifyResource muuttaa pelaajan jonkin resurssin määrää.
      * \param player, jonka resurssia muokataan.
      * \param resource, muokattava resurssi.
      * \param amount, määrä jonka verran resurssia vähennetään tai lisätään.
      * \return true
      */
     bool modifyResource(std::shared_ptr<Course::PlayerBase> player,
                                 Course::BasicResource resource,
                                 int amount);

     /*!
      * \brief modifyResources muuttaa pelaajan kaikkien resurssien määrää kerralla.
      * \param player, jonka resursseja muutetaan.
      * \param resources, resourcemap muutettavien resurssien määrästä.
      * \return true
      */
     bool modifyResources(std::shared_ptr<Course::PlayerBase> player,
                                  Course::ResourceMap resources);

     /*!
      * \brief obj_placement_permission tarkistaa onko naapurissa kyseisen pelaajan
      * omistamaa rakennusta.  Tällä saadaan pelin kentälle "etenemismekaniikka".
      * \param tile, jonka naapurit tarkistetaan.
      * \param objectmanager
      * \param current_player, jonka täytyy omistaa tile ja talo naapurista.
      * \return totuusarvo onko naapurissa pelaajan omistama tile ja talo. Jos on, niin pelaaja
      * pystyy rakentamaan uuden talon/workerin parametrina saatavaan tileen.
      */
     bool obj_placement_permission(std::shared_ptr<Course::TileBase> tile,
                                   std::shared_ptr<Course::iObjectManager> objectmanager,
                                   std::shared_ptr<Student::Player> current_player);

};
}
