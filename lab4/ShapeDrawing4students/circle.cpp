#include "circle.h"
#include <cmath>
namespace Shapes
{
	typedef std::pair<int, int> Point;

	Circle::Circle(Point center, int radius) : radius(radius),center(center.first, center.second) {
	}

	Circle::Circle(int xCenter, int yCenter, int radius) : radius(radius), center(xCenter, yCenter) {
	}

	bool Circle::isIn(Point point) const {
		double distance = (double)sqrt((point.first - this->center.first) * (point.first - this->center.first) 
			+ (point.second - this->center.second) * (point.second - this->center.second));
		if (distance <= this->getRadius()) {
			return true;
		}
		else {
			return false;
		}
	}
	bool Circle::isIn(int x, int y) const {
		double distance = (double)sqrt((x - this->center.first) * (x - this->center.first)
			+ (y - this->center.second) * (y - this->center.second));
		if (distance <= this->getRadius()) {
			return true;
		}
		else {
			return false;
		}
	}
}