#ifndef STAGE_H
#define STAGE_H

#include <iosfwd>

namespace Shapes
{
class Shape;
}

class Stage // since I don't use it, i don't put it in Shapes namespace
{
    int width, height;

    constexpr static char emptySymbol{' '};
    constexpr static char shapeSymbol{'*'};

public:
    Stage(int width, int height) : width(width), height(height)
    {}

    void drawShape2Stream(const Shapes::Shape* shape, std::ostream& stream) const {};  // sadly my lack of time doesn't allow me to implement it
};

#endif // STAGE_H
