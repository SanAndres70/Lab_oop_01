#include "rectangle.h"
#include <cmath>

Rectangle::Rectangle(const string& name, const Point& p1, const Point& p2)
    : Figure(name), p1(p1), p2(p2) {
    if (p2.get_x() <= p1.get_x() || p2.get_y() <= p1.get_y()) {
        throw invalid_argument("Некорректные координаты: p2 должна быть правее и выше p1");
    }
}

string Rectangle::getName() const {
    return name;
}

string Rectangle::getDescription() const {
    return "Прямоугольник с углами (" + to_string(p1.get_x()) + ", " + to_string(p1.get_y()) +
           ") и (" + to_string(p2.get_x()) + ", " + to_string(p2.get_y()) + ")";
}

double Rectangle::getArea() const {
    return (p2.get_x() - p1.get_x()) * (p2.get_y() - p1.get_y());
}
