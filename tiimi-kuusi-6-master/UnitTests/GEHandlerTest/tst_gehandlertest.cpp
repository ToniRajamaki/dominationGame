#include <QtTest>

// add necessary includes here
#include "interfaces/igameeventhandler.h"
#include "gameeventhandler.h"
#include "player.h"

class GEHandlerTest : public QObject
{
    Q_OBJECT

public:
    GEHandlerTest();
    ~GEHandlerTest();

private Q_SLOTS:
    void test_modifyresources();
    void test_modifyresource();

};

GEHandlerTest::GEHandlerTest()
{

}

GEHandlerTest::~GEHandlerTest()
{

}

//Muokkaa pelaajan Stone maaraa modifyresource() metodilla.
//Tarkistetaan onko lopputulos oikein.
void GEHandlerTest::test_modifyresource()
{
    //Pelaajan kaikki resurssit ovat aluksi 1000.
    std::shared_ptr<Student::Player> player =
    std::make_shared<Student::Player>("Jaakko");

    std::shared_ptr<Student::GameEventHandler> gameEventHandler =
    std::make_shared<Student::GameEventHandler>();

    const Course::ResourceMap result =  {
        {Course::BasicResource::MONEY, 1000},
        {Course::BasicResource::FOOD, 1000},
        {Course::BasicResource::WOOD, 1000},
        {Course::BasicResource::STONE, 900},
        {Course::BasicResource::ORE, 1000}
    };
    gameEventHandler->modifyResource(player,Course::BasicResource::STONE, -100);

    QVERIFY(player->get_player_resources() == result);
}



//Muokkaa pelaajan resursseja modifyresources() metodilla.
//Tarkistetaan onko lopputulos oikein.
void GEHandlerTest::test_modifyresources()
{
    //Pelaajan kaikki resurssit ovat aluksi 1000.
    std::shared_ptr<Student::Player> player =
    std::make_shared<Student::Player>("Jaakko");

    std::shared_ptr<Student::GameEventHandler> gameEventHandler =
    std::make_shared<Student::GameEventHandler>();

    const Course::ResourceMap modifier =  {
        {Course::BasicResource::MONEY, -100},
        {Course::BasicResource::FOOD, -100},
        {Course::BasicResource::WOOD, -100},
        {Course::BasicResource::STONE, -100},
        {Course::BasicResource::ORE, -100}
    };

    const Course::ResourceMap result =  {
        {Course::BasicResource::MONEY, 900},
        {Course::BasicResource::FOOD, 900},
        {Course::BasicResource::WOOD, 900},
        {Course::BasicResource::STONE, 900},
        {Course::BasicResource::ORE, 900}
    };

    gameEventHandler->modifyResources(player,modifier);

    QVERIFY(player->get_player_resources() == result);
}

QTEST_APPLESS_MAIN(GEHandlerTest)

#include "tst_gehandlertest.moc"
