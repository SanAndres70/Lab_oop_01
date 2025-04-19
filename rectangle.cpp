#include "rectangle.h"
#include <cmath>

Rectangle::Rectangle(const string& name, const Point& p1, const Point& p2)
    : Figure(name), p1(p1), p2(p2) {}

string Rectangle::getName() const {
    return name;
}

string Rectangle::getDescription() const {
    return "Прямоугольник с углами (" + to_string(p1.x) + ", " + to_string(p1.y) +
           ") и (" + to_string(p2.x) + ", " + to_string(p2.y) + ")";
}

double Rectangle::getArea() const {
    return abs((p2.x - p1.x) * (p2.y - p1.y));
}
