#ifndef FIGURE_H
#define FIGURE_H
#define EPS 0.000001

#include <string>
#include "point.h"
#include <iostream>

using namespace std;

class Figure {
protected:
    string name;

public:
    Figure() = default;
    Figure(const string& name) : name(name) {}
    virtual ~Figure() = default;
    virtual string getName() const = 0;
    virtual string getDescription() const = 0;
    virtual double getArea() const = 0;
};

#endif
