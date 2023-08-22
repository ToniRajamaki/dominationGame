#include <QtTest>
#include <QTest>
#include <QString>

// add necessary includes here
#include "interfaces/iobjectmanager.h"
#include "objectmanager.h"
#include "interfaces/igameeventhandler.h"
#include "gameeventhandler.h"
#include "core/worldgenerator.h"
#include "tiles/forest.h"
#include "exceptions/baseexception.h"

class ObjManagerTest : public QObject
{
    Q_OBJECT

public:
    ObjManagerTest();
    ~ObjManagerTest();

private Q_SLOTS:
    void test_tile_generation();
    void getTile_unhappy_cases();
    void getTile_methods_test();
};

ObjManagerTest::ObjManagerTest()
{

}

ObjManagerTest::~ObjManagerTest()
{

}

//Testaa throwaako getTile saadessaan rajat ylittavat koordinaatit.
void ObjManagerTest::getTile_unhappy_cases()
{
    std::shared_ptr<Student::ObjectManager> objectManager =
    std::make_shared<Student::ObjectManager>();

    std::shared_ptr<Student::GameEventHandler> gameEventHandler =
    std::make_shared<Student::GameEventHandler>();

    Course::WorldGenerator& worldGen = Course::WorldGenerator::getInstance();
    worldGen.addConstructor<Course::Forest>(1);
    worldGen.generateMap(10,10,1, objectManager, gameEventHandler);

    //Koordinaatit (11,11) ylittavat pelirajat.
    QVERIFY_EXCEPTION_THROWN(objectManager->getTile(Course::Coordinate(11,11)), Course::BaseException);
}

//Testaa saadaanko sama tiili haettaessa id:lla ja koordinaateilla.
void ObjManagerTest::getTile_methods_test()
{
    std::shared_ptr<Student::ObjectManager> objectManager =
            std::make_shared<Student::ObjectManager>();

    std::shared_ptr<Student::GameEventHandler> gameEventHandler =
            std::make_shared<Student::GameEventHandler>();

    Course::WorldGenerator& worldGen = Course::WorldGenerator::getInstance();
    worldGen.addConstructor<Course::Forest>(1);
    worldGen.generateMap(15,11,404, objectManager, gameEventHandler);

    QVERIFY(objectManager->getTile(164)
            == objectManager->getTile(Course::Coordinate(14,10)));
}

//Generoi eri maaran tiilia ja testaa tallentuuko ne objmanageriin oikein.
void ObjManagerTest::test_tile_generation()
{
    std::shared_ptr<Student::ObjectManager> objectManager =
    std::make_shared<Student::ObjectManager>();

    std::shared_ptr<Student::GameEventHandler> gameEventHandler =
    std::make_shared<Student::GameEventHandler>();

    for(unsigned int x = 0; x < 21 ; ++x)
    {
        for(unsigned int y = 0; y < 16 ; ++y)
        {
            Course::WorldGenerator& worldGen = Course::WorldGenerator::getInstance();
            worldGen.addConstructor<Course::Forest>(1);
            worldGen.generateMap(x,y,404, objectManager, gameEventHandler);

            //Generoituuko ja tallentuuko tileja oikea maara huomioiden generointiarvot.         
            QVERIFY((objectManager->getTiles().size() == x*y));
        }
    }
}


QTEST_APPLESS_MAIN(ObjManagerTest)

#include "tst_objmanagertest.moc"
