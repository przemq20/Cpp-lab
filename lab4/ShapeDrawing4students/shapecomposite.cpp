#include <memory>
#include "shapecomposite.h"

typedef std::pair<int, int> Point;

Shapes::ShapeComposite::ShapeComposite(std::shared_ptr<Shape> shape1, std::shared_ptr<Shape> shape2, ShapeOperation operation)
	: shape1(shape1), shape2(shape2), operation(operation) {}

bool Shapes::ShapeComposite::isIn(int x, int y) const {
	if (this->operation == ShapeOperation::SUM) {
		return (shape1->isIn(x, y) || shape2->isIn(x, y));
	}
	else if (this->operation == ShapeOperation::INTERSECTION) {
		return (shape1->isIn(x, y) && shape2->isIn(x, y));
	}
	else if (this->operation == ShapeOperation::DIFFERENCE) {
		return (shape1->isIn(x, y) && !shape2->isIn(x, y));
	}
}

bool Shapes::ShapeComposite::isIn(Point point) const {
	if (this->operation == ShapeOperation::SUM) {
		return (shape1->isIn(point.first, point.second) || shape2->isIn(point.first, point.second));
	}
	else if (this->operation == ShapeOperation::INTERSECTION) {
		return (shape1->isIn(point.first, point.second) && shape2->isIn(point.first, point.second));
	}
	else if (this->operation == ShapeOperation::DIFFERENCE) {
		return (shape1->isIn(point.first, point.second) && !shape2->isIn(point.first, point.second));
	}
}
