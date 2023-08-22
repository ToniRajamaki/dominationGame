QT += testlib
QT -= gui

TARGET = tst_objmanagertest

CONFIG += qt console warn_on depend_includepath testcase
CONFIG -= app_bundle
CONFIG += c++14

TEMPLATE = app

SOURCES +=  tst_objmanagertest.cpp \
    ../../Course/CourseLib/buildings/buildingbase.cpp \
    ../../Course/CourseLib/buildings/farm.cpp \
    ../../Course/CourseLib/buildings/headquarters.cpp \
    ../../Course/CourseLib/buildings/outpost.cpp \
    ../../Course/CourseLib/core/basicresources.cpp \
    ../../Course/CourseLib/core/coordinate.cpp \
    ../../Course/CourseLib/core/gameobject.cpp \
    ../../Course/CourseLib/core/placeablegameobject.cpp \
    ../../Course/CourseLib/core/playerbase.cpp \
    ../../Course/CourseLib/core/worldgenerator.cpp \
    ../../Course/CourseLib/tiles/forest.cpp \
    ../../Course/CourseLib/tiles/grassland.cpp \
    ../../Course/CourseLib/tiles/tilebase.cpp \
    ../../Course/CourseLib/workers/basicworker.cpp \
    ../../Course/CourseLib/workers/workerbase.cpp \
    ../../Game/advancedworker.cpp \
    ../../Game/desert.cpp \
    ../../Game/gameeventhandler.cpp \
    ../../Game/objectmanager.cpp \
    ../../Game/player.cpp \

HEADERS += \
    ../../Course/CourseLib/buildings/buildingbase.h \
    ../../Course/CourseLib/buildings/farm.h \
    ../../Course/CourseLib/buildings/headquarters.h \
    ../../Course/CourseLib/buildings/outpost.h \
    ../../Course/CourseLib/core/basicresources.h \
    ../../Course/CourseLib/core/coordinate.h \
    ../../Course/CourseLib/core/gameobject.h \
    ../../Course/CourseLib/core/placeablegameobject.h \
    ../../Course/CourseLib/core/playerbase.h \
    ../../Course/CourseLib/core/resourcemaps.h \
    ../../Course/CourseLib/core/worldgenerator.h \
    ../../Course/CourseLib/exceptions/baseexception.h \
    ../../Course/CourseLib/exceptions/illegalaction.h \
    ../../Course/CourseLib/exceptions/invalidpointer.h \
    ../../Course/CourseLib/exceptions/keyerror.h \
    ../../Course/CourseLib/exceptions/notenoughspace.h \
    ../../Course/CourseLib/exceptions/ownerconflict.h \
    ../../Course/CourseLib/interfaces/igameeventhandler.h \
    ../../Course/CourseLib/interfaces/iobjectmanager.h \
    ../../Course/CourseLib/tiles/forest.h \
    ../../Course/CourseLib/tiles/grassland.h \
    ../../Course/CourseLib/tiles/tilebase.h \
    ../../Course/CourseLib/workers/basicworker.h \
    ../../Course/CourseLib/workers/workerbase.h \
    ../../Game/advancedworker.h \
    ../../Game/desert.h \
    ../../Game/gameeventhandler.h \
    ../../Game/objectmanager.h \
    ../../Game/player.h \
    ../../Game/resourcelist.h \

SUBDIRS += \
    ../../Game/Game.pro

INCLUDEPATH += \
            ../../Course/CourseLib/ \
            ../../Game/

DEPENDPATH += \
            ../../Course/CourseLib/


