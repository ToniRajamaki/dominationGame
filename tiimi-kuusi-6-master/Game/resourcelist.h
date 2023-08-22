#ifndef RESOURCELIST_H
#define RESOURCELIST_H

#include "core/basicresources.h"

namespace Student {

namespace ConstResourceMaps {

const Course::ResourceMap EMPTY = {};




const Course::ResourceMap WATER_BP = {
    {Course::BasicResource::MONEY, 5},
    {Course::BasicResource::FOOD, 10},
    {Course::BasicResource::WOOD, 0},
    {Course::BasicResource::STONE, 0},
    {Course::BasicResource::ORE, 0}
};


//Tile-Desert Basic Production
const Course::ResourceMap DESERT_BP = {
    {Course::BasicResource::MONEY, 0},
    {Course::BasicResource::FOOD, -3},
    {Course::BasicResource::WOOD, 0},
    {Course::BasicResource::STONE, 1},
    {Course::BasicResource::ORE, 0}
};

const Course::ResourceMap ROCKY_MOUNTAINS_BP = {
    {Course::BasicResource::MONEY, 0},
    {Course::BasicResource::FOOD, 0},
    {Course::BasicResource::WOOD, 0},
    {Course::BasicResource::STONE, 8},
    {Course::BasicResource::ORE, 8}
};



const Course::ResourceMap PLAYER_STARTING_RESOURCES = {
    {Course::BasicResource::MONEY, 1000},
    {Course::BasicResource::FOOD, 1000},
    {Course::BasicResource::WOOD, 1000},
    {Course::BasicResource::STONE, 1000},
    {Course::BasicResource::ORE, 1000}
};

const Course::ResourceMapDouble WORKER_SATISFACTIONER= {
    {Course::BasicResource::MONEY, 1},
    {Course::BasicResource::FOOD, 1},
    {Course::BasicResource::WOOD, 1},
    {Course::BasicResource::STONE, 1},
    {Course::BasicResource::ORE, 1}
};

const Course::ResourceMapDouble AW_WORKER_EFFICIENCY = {
    {Course::MONEY, 0.50},
    {Course::FOOD, 1.25},
    {Course::WOOD, 1.25},
    {Course::STONE, 0.75},
    {Course::ORE, 0.75}
};



const Course::ResourceMap AW_RECRUITMENT_COST = {
    {Course::MONEY, 25},
    {Course::FOOD, 35}
};

const Course::ResourceMapDouble ELITE_WORKER_EFFICIENCY = {
    {Course::MONEY, 1},
    {Course::FOOD, 1.5},
    {Course::WOOD, 1.5},
    {Course::STONE, 1.25},
    {Course::ORE, 1.25}
};

const Course::ResourceMap ELITE_WORKER_COST = {
    {Course::MONEY, 50},
    {Course::FOOD, 50},
};

const Course::ResourceMapDouble SOLDIER_EFFICIENCY = {
    {Course::MONEY, 0},
    {Course::FOOD, 0},
    {Course::WOOD, 0},
    {Course::STONE, 0},
    {Course::ORE, 0}
};

const Course::ResourceMap SOLDIER_RECRUITMENT_COST = {};

const Course::ResourceMap MINE_BUILD_COST = {
    {Course::BasicResource::MONEY, 150},
    {Course::BasicResource::FOOD, 100},
    {Course::BasicResource::WOOD, 80},
    {Course::BasicResource::STONE, 200}
};
const Course::ResourceMap MINE_PRODUCTION = {
    {Course::BasicResource::MONEY, -1},
    {Course::BasicResource::FOOD, -2},
    {Course::BasicResource::ORE, 8}
};

//NP = NuclearPlant
const Course::ResourceMap NP_BUILD_COST = {
    {Course::BasicResource::MONEY, 1500},
    {Course::BasicResource::FOOD, 1500},
    {Course::BasicResource::WOOD, 1500},
    {Course::BasicResource::STONE, 1500}
};
const Course::ResourceMap NP_PRODUCTION = {
    {Course::BasicResource::MONEY, -1},
    {Course::BasicResource::FOOD, -2},
    {Course::BasicResource::ORE, 12}
};

//StudentOutpost
const Course::ResourceMap SOP_BUILD_COST = {
    {Course::BasicResource::MONEY, 350},
    {Course::BasicResource::FOOD, 100},
    {Course::BasicResource::WOOD, 250},
    {Course::BasicResource::STONE, 250}
};

const Course::ResourceMap SOP_PRODUCTION = {
    {Course::BasicResource::MONEY, -5},
    {Course::BasicResource::FOOD, -2}
};




}
}
#endif // RESOURCELIST_H
