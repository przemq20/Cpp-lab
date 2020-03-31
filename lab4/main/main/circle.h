#ifndef CIRCLE_H
#define CIRCLE_H

#include "shape.h"

namespace Shapes
{
    typedef std::pair<int, int> Point;

class Circle : public Shape
{
    // TODO:
private:
    int radius;
    Point center;

public:
    ~Circle() {};
    Circle(Point center, int radius);
    Circle(int xCenter, int yCenter, int radius);

    int getX() const { return center.first; }
    int getY() const { return center.second; }
    int getRadius() const { return radius; }

    bool isIn(Point point) const override;
    bool isIn(int x, int y) const override;

};
} // namespace Shapes

#endif // CIRCLE_H
