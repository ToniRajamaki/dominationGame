#ifndef PLAYER_H
#define PLAYER_H

#include "core/playerbase.h"
#include "core/basicresources.h"
#include "resourcelist.h"
#include "tiles/tilebase.h"
#include <vector>

namespace Student {



/*!
 * \brief The Player class
 */
class Player : public Course::PlayerBase
{
public:
    Player(const std::string& name,
           const std::vector<std::shared_ptr<Course::GameObject>> objects = {});

    virtual ~Player() = default;


    /*!
     * \brief get_player_resources, palauttaa pelaajan resurssit
     * \return
     */
    Course::ResourceMap get_player_resources();


    /*!
     * \brief save_player_resources, tallentaa pelaajan muuttuneet resurssit
     * \param resources
     */
    void save_player_resources(Course::ResourceMap resources);


    /*!
     * \brief does_have_enough_resources, tarkistaa onko pelaajalla tarpeeksi
     * resursseja
     * \param cost, hinta, johon pelaajan resursseja verrataan.
     * \return
     */
    bool does_have_enough_resources(Course::ResourceMap cost);


    /*!
     * \brief already_owned, tarkistaa onko kyseinen tiili jo pelaajan omassa
     * tiilivektorissa
     * \param tile, tarkistettavan tiilen pointteri
     * \return totuusarvo
     */
    bool already_owned(std::shared_ptr<Course::TileBase> tile);

    /*!
     * \brief addtile, lisää tiilipointterin pelaajan tiilivektoriin
     * \param tile, lisättävä tiilipointteri
     */
    void addtile(std::shared_ptr<Course::TileBase> tile);

    /*!
     * \brief get_tiles, palauttaa pelaajan omistuksessa olevat tiilet
     * \return vektori tiilistä jotka pelaaja omistaa
     */
    std::vector<std::shared_ptr<Course::TileBase>> get_tiles();

    /*!
     * \brief player_built_outpost, jos outpousti rakennetaan, asetetaan
     * has_outpost trueksi
     */
    void player_built_outpost();

    /*!
     * \brief does_player_have_outpost, tarkistaa onko pelaaja rakentanut
     * outpostin.
     * \return
     */
    bool does_player_have_outpost();



private:
    std::vector<std::shared_ptr<Course::TileBase>> m_tiles;
    std::string m_name;
    std::vector<std::weak_ptr<Course::GameObject>> m_objects;
    bool has_outpost; //Pelaajalla voi olla vain yksi Outpost!
    Course::ResourceMap player_resources;




};

}
#endif // PLAYER_H
