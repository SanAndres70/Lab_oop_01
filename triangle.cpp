#include "triangle.h"
#include <cmath>
#include <stdexcept>

Triangle::Triangle(const string& name, const Point& a, const Point& b, const Point& c)
    : Figure(name), a(a), b(b), c(c) {
    double area = Triangle::getArea();
    if (area < EPS) {
        throw invalid_argument("Ошибка: Треугольник с нулевой площадью (вершины коллинеарны).");
    }
}

string Triangle::getName() const {
    return name;
}

string Triangle::getDescription() const {
    return "Треугольник с вершинами (" + to_string(a.x) + ", " + to_string(a.y) + "), (" +
           to_string(b.x) + ", " + to_string(b.y) + "), (" +
           to_string(c.x) + ", " + to_string(c.y) + ")";
}

double Triangle::getArea() const {
    return abs((a.x * (b.y - c.y) +
                     b.x * (c.y - a.y) +
                     c.x * (a.y - b.y)) / 2.0);
}
