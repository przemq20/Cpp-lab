#include "rectangle.h"

namespace Shapes
{
	typedef std::pair<int, int> Point;


	Rectangle::Rectangle(Point bottomLeft, Point upperRight):
		bottomLeft(bottomLeft.first, bottomLeft.second), upperRight(upperRight.first, upperRight.second){
	}

	Rectangle::Rectangle(int xFrom, int yFrom, int xTo, int yTo) :
		bottomLeft(xFrom, yFrom), upperRight(xTo, yTo) {
	}

	bool Rectangle::isIn(Point point) const {
		if (point.first >= bottomLeft.first && point.first <= upperRight.first
			&& point.second >= bottomLeft.second && point.second <= upperRight.second) {
			return true;
		}
		return false;
	}
	bool Rectangle::isIn(int x, int y) const {
		if (x >= bottomLeft.first && x <= upperRight.first
			&& y >= bottomLeft.second && y <= upperRight.second) {
			return true;
		}
		return false;
	}
}