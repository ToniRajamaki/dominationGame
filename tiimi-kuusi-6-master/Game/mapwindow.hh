#ifndef MAPWINDOW_HH
#define MAPWINDOW_HH

#include <QMainWindow>
#include <QObject>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QMouseEvent>
#include <QGraphicsSceneMouseEvent>
#include <QDebug>
#include <QEvent>
#include <QApplication>
#include "exceptions/illegalaction.h"

#include <math.h>
#include <map>
#include <utility>

#include "tiles/tilebase.h"
#include <tiles/forest.h>
#include <tiles/grassland.h>
#include "water.h"
#include <desert.h>
#include "rocky_mountains.h"
#include "buildings/farm.h"
#include "studentoutpost.h"
#include "buildings/headquarters.h"
#include "mine.h"
#include "nuclearplant.h"
#include "buildings/buildingbase.h"
#include "interfaces/igameeventhandler.h"
#include "graphics/simplegamescene.h"
#include "objectmanager.h"
#include "gameeventhandler.h"
#include "core/resourcemaps.h"
#include "core/basicresources.h"
#include "workers/basicworker.h"
#include "advancedworker.h"
#include "eliteworker.h"
#include "soldier.h"
#include "player.h"
#include <cstdlib>
#include <stdio.h>
#include <time.h>
#include <QTimer>

#include "windows/gamescene.h"
#include "graphics/simplemapitem.h"
#include <QPainter>
#include <QPoint>

namespace Ui {
class MapWindow;
}

/*!
 * \brief The MapWindow class
 */
class MapWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MapWindow(QWidget *parent = 0,
                       std::shared_ptr<Course::iGameEventHandler> GEHandler = {}
                       );
    ~MapWindow();



    /*!
     * \brief drawItem, piirtää objektin
     * \param obj, piirrettävä objecktin gamesceneen (talo,worker,tiili)
     */
    void drawItem( std::shared_ptr<Course::GameObject> obj);


    /*!
     * \brief setStatus, asettaa tekstin statuslabeliin joka ui:ssa alaosassa
     * \param text, asetettava teksti
     */
    void setStatus(std::string text);

    /*!
     * \brief getResource palauttaa stringinä viedyn resourcen
     * \param resource course::resourcemap
     */
    std::string getResource(Course::BasicResource resource);





    /*!
     * \brief getImageByString, Hakee halutun kuvan resourceista.
     * \param object_name, haettavan objectin nimi
     * \return
     */
    QPixmap getImageByString(std::string object_name);

    /*!
     * \brief paintWorker, piirtää workerin gamesceneen.
     * \param tile, tiili jonne worker piirretään
     */
    void paintWorker(std::shared_ptr<Course::TileBase> tile);

    /*!
     * \brief paintBuilding, piirtää rakennuksen gamesceneen
     * \param tile, tiili jonne rakennus piirretään
     * \param building, rakennus, joka piirretään
     */
    void paintBuilding(std::shared_ptr<Course::TileBase> tile,QPixmap building);

    /*!
     * \brief update_deal, luo uuden diilin, ja piirtää sen ui:hin
     */
    void update_deal();

    /*!
     * \brief update_player_resources, päivittää pelajaan resurssit
     */
    void update_player_resources();

    /*!
     * \brief add_new_worker, lisää uudeen workerin ja kutsuu piirto funktioita
     * \param worker, lisättävä worker
     * \param cost, workerin kustannus maksu
     * \param tile, tiili, jonne worker lisätään
     */
    void add_new_worker(std::shared_ptr<Course::WorkerBase> worker, Course::ResourceMap cost, std::shared_ptr<Course::TileBase> tile);

    /*!
     * \brief add_new_building, lisää uuden rakennuksen ja kutsuu piirtofunktioita
     * \param building, lisättävä rakennus
     * \param cost, rakennus kustannus maksu
     * \return
     */
    bool add_new_building(std::shared_ptr<Course::BuildingBase> building, Course::ResourceMap cost);

    /*!
     * \brief draw_tiles, piirtää tiilet gamesceneen
     */
    void draw_tiles();

    /*!
     * \brief print_total_production, piirtää game_ui:hin paljonko vuorossa-
     * olevan pelaajan kokotuotannon kaikista tiileistä.
     */
    void print_total_production();

    /*!
     * \brief gamewon, disabloi napit ja ilmoittaa pelin voittajan,
     * tätä kutsutaan kun rakennetaan nuclearplant
     */
    void gamewon();

public slots:

    /*!
     * \brief print_tile_info, kirjoittaa tiilen yleiset tiedot game_ui:hin
     * \param coordinates, koordinaatit jossa tiili on
     */
    void print_tile_info(Course::Coordinate coordinates);


    /*!
     * \brief save_activate_tile, Tallentaa tilen koordinaatit, jota klikattu
     *  viimeksi, eli joka on "aktiivinen".
     * \param coordinates, tiilen koordinaatit
     */
    void save_activate_tile(Course::Coordinate coordinates);

    /*!
     * \brief init_game, alustaa pelin, asettaa pelaajien resurssit, aloitus
     * rakennukset jne.
     * \param name1, pelaaja 1
     * \param name2, pelaaja 2
     * \param interval, aika, kauanko kestää että vuoro vaihtuu itsestään.
     */
    void init_game(std::string name1, std::string name2, int interval);

private:
    Ui::MapWindow* m_ui;
    QTimer *timer;
    std::shared_ptr<Course::iGameEventHandler> m_GEHandler = nullptr;
    std::shared_ptr<Student::GameScene> m_gamescene = nullptr;

    std::shared_ptr<Student::GameEventHandler> gameEventHandler;
    std::shared_ptr<Student::ObjectManager> objectManager;

    std::shared_ptr<Student::Player> player1;
    std::shared_ptr<Student::Player> player2;
    std::shared_ptr<Student::Player> current_player;

    Course::Coordinate last_clicked_tile;

    int timer_interval;
    int time_used_counter;
    int round_count;

    Course::BasicResource sell_resource;
    int sell_amount;

    Course::BasicResource buy_resource;
    int buy_amount;

private slots:

    // Lisää kyseisen rakennuksen, kutsuu add_new_building metodia
    void on_add_farm_button_clicked();
    void on_add_outpost_button_clicked();
    void on_add_hq_button_clicked();
    void on_add_mine_button_clicked();

    //lisää nuclearplantin, kutsuu add_new_buildingia ja gamewon metodia
    void on_add_np_button_clicked();

    // lisää kyseisen workerin, kutsuu add_new_worker metodia
    void on_addBWButton_clicked();
    void on_addAWButton_clicked();
    void on_addEWButton_clicked();

    // päättää pelaajan vuoron, kutsuu update_player_resourcia
    void on_TurnButton_clicked();


    // timeri joka asettaa vaihaa vuoroa annetun ajan mukaan
    void timer_event();
    void on_deal_button_clicked();
};

#endif // MapWINDOW_HH

