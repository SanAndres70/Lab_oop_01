#include "circle.h"
#include <cmath>
#include <stdexcept>

Circle::Circle(const string& name, const Point& center, double radius)
    : Figure(name), center(center), radius(radius) {
    if (radius < EPS) {
        throw invalid_argument("Радиус должен быть положительным.");
    }
}

string Circle::getName() const {
    return name;
}

string Circle::getDescription() const {
    return "Круг с центром (" + to_string(center.x) + ", " +
           to_string(center.y) + ") и радиусом " + to_string(radius);
}

double Circle::getArea() const {
    return M_PI * radius * radius;
}
