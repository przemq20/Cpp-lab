#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "shape.h"

namespace Shapes
{
	typedef std::pair<int, int> Point;

	class Rectangle : public Shape
	{
    private:
        Point bottomLeft;
        Point upperRight;

    public:

        Rectangle(Point bottomLeft, Point upperRight);
        Rectangle(int xFrom, int yFrom, int xTo, int yTo);
        ~Rectangle() {};

        int getBottomLeftX() const { return bottomLeft.first; }
        int getBottomLeftY() const { return bottomLeft.second; }
        int getUpperRightX() const { return upperRight.first; }
        int getUpperRightY() const { return upperRight.second; } 
        int getX() const { return bottomLeft.first; }
        int getY() const { return bottomLeft.second; }
        int getXTo() const { return upperRight.first; }
        int getYTo() const { return upperRight.second; }

        bool isIn(Point point) const override;
        bool isIn(int x, int y) const override;

    };
} // namespace Shapes

#endif // RECTANGLE_H
