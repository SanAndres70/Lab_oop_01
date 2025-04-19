#include "figure_factory.h"
#include "circle.h"
#include "rectangle.h"
#include "triangle.h"
#include <memory>
#include <iostream>

unique_ptr<Figure> FigureFactory::createCircle() {
    string name;
    askName(name);
    double x, y, r;
    cout << "Введите координаты центра (x y): ";
    cin >> x >> y;
    cout << "Введите радиус: ";
    cin >> r;

    unique_ptr<Figure> result;
    try {
        result = make_unique<Circle>(name, Point(x, y), r);
    } catch (...) {
        cerr << "Ошибка при создании круга.\n";
    }
    return result;
}


unique_ptr<Figure> FigureFactory::createRectangle() {
    string name;
    askName(name);
    double x1, y1, x2, y2;
    cout << "Введите координаты двух противоположных углов (x1 y1 x2 y2): ";
    cin >> x1 >> y1 >> x2 >> y2;

    unique_ptr<Figure> result;
    try {
        result = make_unique<Rectangle>(name, Point(x1, y1), Point(x2, y2));
    } catch (...) {
        cerr << "Ошибка при создании прямоугольника.\n";
    }
    return result;
}



unique_ptr<Figure> FigureFactory::createTriangle() {
    string name;
    askName(name);
    double x1, y1, x2, y2, x3, y3;
    cout << "Введите координаты трёх вершин (x1 y1 x2 y2 x3 y3): ";
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;

    unique_ptr<Figure> result;
    try {
        result = make_unique<Triangle>(name, Point(x1, y1), Point(x2, y2), Point(x3, y3));
    } catch (...) {
        cerr << "Ошибка при создании треугольника.\n";
    }
    return result;
}


string FigureFactory::askName(string &name) {
    cout << "Введите имя фигуры: ";
    cin >> name;
    return name;
}
