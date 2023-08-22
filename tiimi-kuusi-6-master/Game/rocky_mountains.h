#ifndef ROCKY_MOUNTAINS_H
#define ROCKY_MOUNTAINS_H
#include "tiles/tilebase.h"
#include "resourcelist.h"

namespace Student {

/*!
 * \brief The rocky_mountains class
 */
class rocky_mountains : public Course::TileBase
{
public:

    rocky_mountains() = delete;

    rocky_mountains(const Course::Coordinate& location,
                    const std::shared_ptr<Course::iGameEventHandler>& eventhandler,
                    const std::shared_ptr<Course::iObjectManager>& objectmanager,
                    const unsigned int& max_build = 4,
                    const unsigned int& max_work = 4,
                    const Course::ResourceMap& production =
                     ConstResourceMaps::ROCKY_MOUNTAINS_BP);

    virtual ~rocky_mountains() = default;
    std::string getType() const;
};
}
#endif // ROCKY_MOUNTAINS_H
