#include "mapwindow.hh"
#include "ui_mapwindow.h"
#include <iostream>
#include <string>

#include "graphics/simplemapitem.h"
#include "core/worldgenerator.h"
#include <QPixmap>
#include <QGraphicsPixmapItem>
#include <math.h>



MapWindow::MapWindow(QWidget *parent,
                     std::shared_ptr<Course::iGameEventHandler> handler):
    QMainWindow(parent),
    m_ui(new Ui::MapWindow),
    m_GEHandler(handler),
    m_gamescene(new Student::GameScene(this)),
    gameEventHandler(std::make_shared<Student::GameEventHandler>()),
    objectManager(std::make_shared<Student::ObjectManager>()),
    player1(std::make_shared<Student::Player>("Player 1")),
    player2(std::make_shared<Student::Player>("Player 2")),
    last_clicked_tile(Course::Coordinate(0,0)),
    timer_interval(0),
    time_used_counter(0),
    round_count(1)
{
    m_ui->setupUi(this);
    this->setWindowTitle("Pirkanmaan valloitus");

    Student::GameScene* sgs_rawptr = m_gamescene.get();

    m_ui->graphicsView->setScene(dynamic_cast<QGraphicsScene*>(sgs_rawptr));

    timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(timer_event()));


    connect(m_gamescene.get(), &Student::GameScene::sendtileid,
                this, &MapWindow::print_tile_info);

    connect(m_gamescene.get(), &Student::GameScene::sendtileid,
                this, &MapWindow::save_activate_tile);
}

MapWindow::~MapWindow()
{
    delete m_ui;
}

void MapWindow::setStatus(std::string text)
{
    QString q_text = QString::fromStdString(text);
    m_ui->statusLabel->setText(q_text);
}

std::string MapWindow::getResource(Course::BasicResource resource)
{
    std::string resource_string;

    switch (resource) {

    case Course::BasicResource::MONEY: return ("Money");

    case Course::BasicResource::FOOD: return ("Food");

    case Course::BasicResource::WOOD: return ("Wood");

    case Course::BasicResource::STONE: return ("Stone");

    case Course::BasicResource::ORE:  return ("Ore");

    default: break;
    }

    return "";
}

QPixmap MapWindow::getImageByString(std::string object_name)
{
    if(object_name == "Farm")
    {
        QPixmap building_image(":/farmimage.png");
        return building_image.scaled(QSize(25,25));

    } else if (object_name == "HeadQuarters")
    {
        QPixmap building_image(":/building_image.png");
         return building_image.scaled(QSize(25,25));


    } else if (object_name == "Mine")
    {
        QPixmap building_image(":/mineimage.png");
        return building_image.scaled(QSize(25,25));

    } else if(object_name == "Outpost")
    {
        QPixmap building_image(":/outpostimage.png");
        return building_image.scaled(QSize(25,25));


    } else if(object_name == "NuclearPlant")
    {
        QPixmap building_image(":/npimage.png");
        return building_image.scaled(QSize(25,25));


    } else if ( object_name == "Money"){
        QPixmap building_image(":/money.png");
        return building_image.scaled(QSize(28,28));


    }else if ( object_name == "Stone"){
        QPixmap building_image(":/stoneimage.png");
        return building_image.scaled(QSize(28,28));

    }else if ( object_name == "Wood"){
        QPixmap building_image(":/woodimage.png");
        return building_image.scaled(QSize(28,28));


    }else if ( object_name == "Ore"){
        QPixmap building_image(":/oreimage.png");
         return building_image.scaled(QSize(28,28));


    }else if ( object_name == "Food"){
        QPixmap building_image(":/foodimage.png");
         return building_image.scaled(QSize(28,28));


    } else if (object_name == "Arrow"){
        QPixmap building_image(":/arrowimage.png");
         return building_image.scaled(QSize(60,30));
    }else
    {
        throw Course::BaseException("No image for object found!");
    }
}

void MapWindow::paintWorker(std::shared_ptr<Course::TileBase> tile)
{
    int x = tile->getCoordinate().x();
    int y = tile->getCoordinate().y();

    QPixmap image(":/worker_image.png");
    QGraphicsPixmapItem* worker_image = m_gamescene->addPixmap(image);

    switch (tile->getWorkerCount()) {

    case 1: worker_image->setPos(x*70+24,y*70+32); break;

    case 2: worker_image->setPos(x*70+30,y*70+32); break;

    case 3: worker_image->setPos(x*70+36,y*70+32); break;

    case 4: worker_image->setPos(x*70+42,y*70+32); break;

    default: break;

    }
    m_ui->graphicsView->viewport()->update();
}

void MapWindow::paintBuilding(std::shared_ptr<Course::TileBase> tile,QPixmap building)
{
    int x = tile->getCoordinate().x();
    int y = tile->getCoordinate().y();

    QGraphicsPixmapItem* item = m_gamescene->addPixmap(building);

    switch (tile->getBuildingCount()) {

    case 1: item->setPos(x*70+6,y*70+6); break;

    case 2: item->setPos(x*70+39,y*70+6); break;

    case 3: item->setPos(x*70+6,y*70+39); break;

    case 4: item->setPos(x*70+39,y*70+39); break;

    default: break;

    }
    m_ui->graphicsView->viewport()->update();
}



void MapWindow::update_deal()
{
    std::pair <Course::BasicResource,int> sell_deal
            = gameEventHandler->getRandomResource();
    sell_resource = sell_deal.first;

    std::pair <Course::BasicResource,int> buy_deal
            = gameEventHandler->getRandomResource();
    buy_resource = buy_deal.first;

    while(sell_resource == buy_resource)
    {
        std::pair <Course::BasicResource,int> sell_deal
                = gameEventHandler->getRandomResource();

        sell_resource = sell_deal.first;
    }

    sell_amount = sell_deal.second;
    std::string sell_resource_string =getResource(sell_resource);

    buy_amount = buy_deal.second;
    std::string buy_resource_string =getResource(buy_resource);



    m_ui->sell_image_label->setPixmap(getImageByString(sell_resource_string));
    m_ui->sell_amount_label->setNum(sell_amount);

    m_ui->arrow_image_label->setPixmap(getImageByString("Arrow"));

    m_ui->buy_image_label->setPixmap(getImageByString(buy_resource_string));
    m_ui->buy_amount_label->setNum(buy_amount);



//    m_ui->deal_label->setText("Sell:  "+QString::number(sell_amount)+ " " +
//                              QString::fromStdString(sell_resource_string)+"\n"+
//                              "Buy:  "+QString::number(buy_amount)+ " " +
//                              QString::fromStdString(buy_resource_string));


}

void MapWindow::update_player_resources()
{
    Course::ResourceMap resources = current_player->get_player_resources();

    m_ui->MoneyPlayerLabel->setText
            (QString::number(resources[Course::BasicResource::MONEY]));

    m_ui->FoodPlayerLabel->setText
            (QString::number(resources[Course::BasicResource::FOOD]));

    m_ui->WoodPlayerLabel->setText
            (QString::number(resources[Course::BasicResource::WOOD]));

    m_ui->StonePlayerLabel->setText
            (QString::number(resources[Course::BasicResource::STONE]));

    m_ui->OrePlayerLabel->setText
            (QString::number(resources[Course::BasicResource::ORE]));
}

void MapWindow::add_new_worker(std::shared_ptr<Course::WorkerBase> worker, Course::ResourceMap cost, std::shared_ptr<Course::TileBase> tile)
{


    if(!gameEventHandler->obj_placement_permission(tile, objectManager, current_player)
            and worker->getType() != "Soldier")
    {
        setStatus("Can't add worker here! No building in neighbour.");
        return;
    }

    try {
        //(Pelaajalla on varaa workeriin) JA (pelaaja omistaa tilen TAI kukaan ei omista).
        if(!current_player->does_have_enough_resources(cost))
        {
            setStatus(current_player->getName()+" does not have enough resources.");
        } else if (!(tile->getOwner() == current_player || tile->getOwner() == nullptr))
        {
            setStatus("This tile is owned by another player.");
        } else
        {
            if (!current_player->already_owned(tile)){
                current_player->addtile(tile);
            }
            tile->setOwner(current_player);
            tile->addWorker(worker);

            //Maksu workerista, vahennetaan pelaajalta resursseja.
            for (auto resource : cost)
            {
                gameEventHandler->modifyResource
                        (current_player,resource.first,-resource.second);
            }

            update_player_resources();
            print_total_production();
            drawItem(worker);
            print_tile_info(last_clicked_tile); //Tilen inffot ajantasalle.
            paintWorker(tile);

            std::string status = current_player->getName()+" has hired "+
                    worker->getType()+" to work on "+tile->getType()+".";
            setStatus(status);
            m_ui->graphicsView->viewport()->update();

        }
    } catch (Course::IllegalAction) {
        setStatus("There is no space for more workers!");

    }
}

bool MapWindow::add_new_building(std::shared_ptr<Course::BuildingBase> building, Course::ResourceMap cost)
{
    std::shared_ptr<Course::TileBase> tile = objectManager->getTile(last_clicked_tile);

    if(!gameEventHandler->obj_placement_permission(tile, objectManager, current_player))
    {
        setStatus("Can't build here! No building in neighbour.");
        return false;
    }

    try {     
        //(Pelaajalla on varaa rakennukseen) JA (pelaaja omistaa tilen TAI kukaan ei omista).
        if(!current_player->does_have_enough_resources(cost))
        {
            setStatus(current_player->getName()+" does not have enough resources.");
        } else if(!(tile->getOwner() == current_player || tile->getOwner() == nullptr))
        {
            setStatus("This tile is owned by another player.");
        } else
        {
            //Tarkistetaan halutaanko listata tiili pelaajan tiilivektoriin.
            if (!current_player->already_owned(tile)){
                current_player->addtile(tile);
            }
            tile->setOwner(current_player);
            tile->addBuilding(building);

            //Maksu rakennuksesta, vahennetaan pelaajalta resursseja.
            for (auto resource : cost)
            {
                gameEventHandler->modifyResource
                        (current_player,resource.first,-resource.second);
            }
            update_player_resources();
            print_total_production();
            drawItem(building);
            print_tile_info(last_clicked_tile); //Tilen inffot ajantasalle.
            std::string building_type = building->getType();
            QPixmap building_image = MapWindow::getImageByString(building_type);
            paintBuilding(tile,building_image);
            m_ui->graphicsView->viewport()->update();

            std::string status = current_player->getName()+" has built "+
                    building_type+" on "+tile->getType()+" biome.";
            setStatus(status);

            if(building->getType() == "NuclearPlant")
            {
                gamewon();
            }

            return true;
        }

    } catch (Course::IllegalAction) {
        setStatus("There is no space for more buildings!");
    }

    return false;
}

void MapWindow::draw_tiles()
{
    for(unsigned int i = 0; i < 165; i++)
    {
        auto item = objectManager->getTile(i);
        drawItem(item);
    }
}

void MapWindow::print_total_production()
{
    Course::ResourceMap total_production;
    std::vector<std::shared_ptr<Course::TileBase>> player_tiles = current_player->get_tiles();
    for(auto tile : player_tiles)
    {
       total_production =
               Course::mergeResourceMaps(total_production,gameEventHandler->getProduction(tile));
    }
    m_ui->MoneyPlayerLabel_2->setNum(total_production[Course::BasicResource::MONEY]);
    m_ui->FoodPlayerLabel_2->setNum(total_production[Course::BasicResource::FOOD]);
    m_ui->WoodPlayerLabel_2->setNum(total_production[Course::BasicResource::WOOD]);
    m_ui->StonePlayerLabel_2->setNum(total_production[Course::BasicResource::STONE]);
    m_ui->OrePlayerLabel_2->setNum(total_production[Course::BasicResource::ORE]);
}

void MapWindow::gamewon()
{
    setStatus(current_player->getName() + " has won the game by building Nuclear Plant!");
    m_ui->TurnButton->setDisabled(true);
    m_ui->addAWButton->setDisabled(true);
    m_ui->addBWButton->setDisabled(true);
    m_ui->addEWButton->setDisabled(true);
    m_ui->add_hq_button->setDisabled(true);
    m_ui->add_farm_button->setDisabled(true);
    m_ui->add_mine_button->setDisabled(true);
    m_ui->add_outpost_button->setDisabled(true);
    m_ui->add_np_button->setDisabled(true);
    m_ui->deal_button->setDisabled(true);
    timer->stop();

}

void MapWindow::print_tile_info(Course::Coordinate coordinates)
{

    auto tile = objectManager->getTile(coordinates);

    std::string tile_type = (tile->getType());
    QString q_tile_type = QString::fromStdString(tile_type);
    int y_coord = tile->getCoordinate().y();
    int x_coord = tile->getCoordinate().x();

    std::vector<std::shared_ptr<Course::BuildingBase>> buildings =
            tile->getBuildings();
    std::vector<std::shared_ptr<Course::WorkerBase>> workers =
            tile->getWorkers();

    m_ui->InfoText->setText("Owner: ");

    m_ui->TileTypeLabel->setText(q_tile_type + "  ("+QString::number(x_coord)+
                                 "," + QString::number(y_coord)+")");

    if (tile->getOwner() == nullptr)
    {
       QString q_owner = "No owner";
       m_ui->InfoText->append(q_owner);
    } else
    {
        std::string owner = tile->getOwner()->getName();
        QString q_owner = QString::fromStdString(owner);
        m_ui->InfoText->append(q_owner);
    }


    unsigned int build_count = tile->getBuildingCount();
    unsigned int max_build = tile->MAX_BUILDINGS;
    m_ui->InfoText->append("\nBuildings:     ( "
                           + QString::number(build_count) + "/"
                           + QString::number(max_build)+ " )");

    for(unsigned int i = 0; i < buildings.size(); ++i)
    {
        QString building_type = QString::fromStdString(buildings.at(i)->getType());
        m_ui->InfoText->append(building_type);
    }


    unsigned int worker_count = tile->getWorkerCount();
    unsigned int max_workers = tile->MAX_WORKERS;
    m_ui->InfoText->append("\nWorkers:     ( "
                           + QString::number(worker_count) + "/"
                           + QString::number(max_workers)+ " )");

    for(unsigned int i = 0; i < workers.size(); ++i)
    {
        QString worker_type = QString::fromStdString(workers.at(i)->getType());
        m_ui->InfoText->append(worker_type);
    }

    for(auto resource : tile->BASE_PRODUCTION)
    {
        switch (resource.first) {

        case Course::BasicResource::MONEY:
            m_ui->InfoText->append("\n\nBase Production:\nMoney: "+QString::number(resource.second)); break;

        case Course::BasicResource::FOOD:
            m_ui->InfoText->append("Food: "+QString::number(resource.second)); break;

        case Course::BasicResource::WOOD:
            m_ui->InfoText->append("Wood: "+QString::number(resource.second)); break;

        case Course::BasicResource::STONE:
            m_ui->InfoText->append("Stone: "+QString::number(resource.second)); break;

        case Course::BasicResource::ORE:
            m_ui->InfoText->append("Ore: "+QString::number(resource.second)); break;

        default: break;
        }
    }

    std::map<Course::BasicResource, int> tile_production = gameEventHandler->getProduction(tile);

    m_ui->MoneyLabel->setNum(tile_production[Course::BasicResource::MONEY]);
    m_ui->OreLabel->setNum(tile_production[Course::BasicResource::ORE]);
    m_ui->StoneLabel->setNum(tile_production[Course::BasicResource::STONE]);
    m_ui->FoodLabel->setNum(tile_production[Course::BasicResource::FOOD]);
    m_ui->WoodLabel->setNum(tile_production[Course::BasicResource::WOOD]);

}

void MapWindow::save_activate_tile(Course::Coordinate coordinates)
{
    last_clicked_tile = coordinates;
}

void MapWindow::init_game(std::string name1, std::string name2, int interval)
{
    if(name1 == ""){
        player1->setName("Player 1");
    } else
    {
    player1->setName(name1);
    }
    if(name2=="")
    {
    player2->setName("Player 2");
    }else
    {
    player2->setName(name2);
    }

    Course::WorldGenerator& worldGen = Course::WorldGenerator::getInstance();
    worldGen.addConstructor<Course::Forest>(20);
    worldGen.addConstructor<Course::Grassland>(35);
    worldGen.addConstructor<Student::Desert>(25);
    worldGen.addConstructor<Student::Water>(7);
    worldGen.addConstructor<Student::rocky_mountains>(7);
    worldGen.generateMap(15,11,time(NULL), objectManager, gameEventHandler);

    draw_tiles();

    current_player = player1; //Kumpi pelaajista aloittaa.

    //Pelaajien aloitustiilet.
    auto tile = objectManager->getTile(152);
    auto tile2 = objectManager->getTile(12);

    //Aloitus hq:t pelaajille.
    std::shared_ptr<Course::HeadQuarters> hq =
            std::make_shared<Course::HeadQuarters>(gameEventHandler,objectManager,player1);
    std::shared_ptr<Course::HeadQuarters> hq2 =
            std::make_shared<Course::HeadQuarters>(gameEventHandler,objectManager,player2);
    tile->setOwner(player1);
    tile2->setOwner(player2);
    tile->addBuilding(hq);
    tile2->addBuilding(hq2);
    drawItem(hq);
    drawItem(hq2);

    paintBuilding(tile,MapWindow::getImageByString("HeadQuarters"));
    paintBuilding(tile2,MapWindow::getImageByString("HeadQuarters"));


    m_ui->outpost_label->setPixmap(getImageByString("Outpost"));
    m_ui->farm_label->setPixmap(getImageByString("Farm"));
    m_ui->mine_label->setPixmap(getImageByString("Mine"));
    m_ui->hq_label->setPixmap(getImageByString("HeadQuarters"));
    m_ui->np_label->setPixmap(getImageByString("NuclearPlant"));

    m_ui->moneyPic->setPixmap(getImageByString("Money"));
    m_ui->foodPic->setPixmap(getImageByString("Food"));
    m_ui->woodPic->setPixmap(getImageByString("Wood"));
    m_ui->stonePic->setPixmap(getImageByString("Stone"));
    m_ui->orePic->setPixmap(getImageByString("Ore"));

    m_ui->CurrentPlayerLabel->setText("Current player: "+
                                      QString::fromStdString(current_player->getName()));

    update_deal();
    update_player_resources();

    m_ui->graphicsView->viewport()->update();

    if(interval != 0)
    {
        timer_interval = interval;
        //peliin paivittyy sekunnin valein jaljella oleva aika.
        timer->start(1000);
    } else {
        m_ui->label_13->setText("");
    }
}

void MapWindow::on_add_farm_button_clicked()
{
    std::shared_ptr<Course::Farm> farmi =
            std::make_shared<Course::Farm>(gameEventHandler,objectManager,current_player);

   add_new_building(farmi, Course::ConstResourceMaps::FARM_BUILD_COST);


}

void MapWindow::on_addBWButton_clicked()
{
    std::shared_ptr<Course::BasicWorker> basicworker =
            std::make_shared<Course::BasicWorker>(gameEventHandler,objectManager,current_player);
    std::shared_ptr<Course::TileBase> tile = objectManager->getTile(last_clicked_tile);
    add_new_worker(basicworker, Course::ConstResourceMaps::BW_RECRUITMENT_COST, tile);

}

void MapWindow::drawItem( std::shared_ptr<Course::GameObject> obj)
{
    m_gamescene->drawItem(obj);
}

void MapWindow::on_TurnButton_clicked()
{
    setStatus("");
    //Generoidaan resurssit pelaajalle, joka lopetti vuoronsa.
    for(unsigned int i = 0; i < 165; i++)
    {
        auto tile = objectManager->getTile(i);
        if(tile->getOwner() == current_player and tile->getWorkerCount()!=0)
        {
            tile->generateResources();
        }
    }
    //Vuoro vaihtuu
    if(current_player == player2)
    {
        current_player = player1;
    } else
    {
        current_player = player2;
    }

    print_total_production();
    update_player_resources();

    m_ui->deal_button->setEnabled(true);
    update_deal(); //Uusi diili pelaajalle.

    m_ui->CurrentPlayerLabel->setText("Current player: "+
                                      QString::fromStdString(current_player->getName()));

    round_count += 1;
    m_ui->round_label->setNum(round_count);

    if(timer_interval != 0)
    {
        time_used_counter = 0;
        timer->start(1000);
    }
}

void MapWindow::on_addEWButton_clicked()
{
    std::shared_ptr<Student::EliteWorker> new_worker =
            std::make_shared<Student::EliteWorker>(gameEventHandler,objectManager,current_player);

    std::shared_ptr<Course::TileBase> tile = objectManager->getTile(last_clicked_tile);
    add_new_worker(new_worker, Student::ConstResourceMaps::ELITE_WORKER_COST, tile);
}

void MapWindow::on_add_hq_button_clicked()
{
    std::shared_ptr<Course::HeadQuarters> hq =
            std::make_shared<Course::HeadQuarters>(gameEventHandler,objectManager,current_player);

   add_new_building(hq, Course::ConstResourceMaps::HQ_BUILD_COST);
}

void MapWindow::on_add_outpost_button_clicked()
{
    if(current_player->does_player_have_outpost())
    {
        std::string status = current_player->getName()+" already owns an Outpost"
                                                       " and cannot built another!";
        setStatus(status);
        return;
    }

    std::shared_ptr<Student::StudentOutpost> outpost =
            std::make_shared<Student::StudentOutpost> (gameEventHandler,objectManager,current_player);

    if(add_new_building(outpost, Student::ConstResourceMaps::SOP_BUILD_COST))
    {
        auto neighbour_tiles = outpost->ClaimAndConquer();

        for(auto tile : neighbour_tiles){
            std::shared_ptr<Student::Soldier> soldier = std::make_shared
                    <Student::Soldier>(gameEventHandler,objectManager,current_player);

            add_new_worker(soldier,
                           Student::ConstResourceMaps::SOLDIER_RECRUITMENT_COST,
                           tile);
        }
        current_player->player_built_outpost();

        auto tile = objectManager->getTile(last_clicked_tile);
        std::string status = current_player->getName()+" has built Outpost"+
                " on "+tile->getType()+" biome and hired Soldiers to protect it.";
        setStatus(status);
    }
}

void MapWindow::on_addAWButton_clicked()
{
    std::shared_ptr<Student::AdvancedWorker> advancedworker =
            std::make_shared<Student::AdvancedWorker>(gameEventHandler,objectManager,current_player);

    std::shared_ptr<Course::TileBase> tile = objectManager->getTile(last_clicked_tile);
    add_new_worker(advancedworker, Student::ConstResourceMaps::AW_RECRUITMENT_COST, tile);
}

void MapWindow::on_add_mine_button_clicked()
{
    std::shared_ptr<Student::Mine> mine =
            std::make_shared<Student::Mine>(gameEventHandler,objectManager,current_player);

   add_new_building(mine, Student::ConstResourceMaps::MINE_BUILD_COST);
}


void MapWindow::on_add_np_button_clicked()
{
    std::shared_ptr<Student::NuclearPlant> np =
            std::make_shared<Student::NuclearPlant>(gameEventHandler,objectManager,current_player);

    add_new_building(np, Student::ConstResourceMaps::NP_BUILD_COST);
}

void MapWindow::timer_event()
{
    time_used_counter += 1;

    m_ui->time_left_label->setNum(timer_interval - time_used_counter);
    m_ui->graphicsView->viewport()->update();

    if(time_used_counter == timer_interval)
    {
        on_TurnButton_clicked();
    }
}

void MapWindow::on_deal_button_clicked()
{
    if(!current_player->does_have_enough_resources({{sell_resource,sell_amount}}))
    {
        setStatus("You do not have enough resources!");
    } else
    {
        //Pelaaja myy resursseja
        gameEventHandler->modifyResource
                (current_player, sell_resource, -sell_amount);

        //Pelaaja ostaa resursseja
        gameEventHandler->modifyResource
                (current_player, buy_resource, buy_amount);

        update_player_resources();
        m_ui->deal_button->setDisabled(true);
    }

}
