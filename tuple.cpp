//
// Created by 包松乐 on 2022/7/29.
//

#include "tuple.h"
#include <cassert>

static int const POINT = 1;
static int const VECTOR = 0;

tuple::tuple(double x, double y, double z, int w): x(x), y(y), z(z), w(w) {
}

tuple point(double x, double y, double z) {
    return {x, y, z, POINT};
}

tuple vector(double x, double y, double z) {
    return {x, y, z, VECTOR};
}

bool tuple::isPoint() const {
    return this->w == POINT;
}

bool tuple::isVector() const {
    return this->w == VECTOR;
}

static bool equal(double a, double b) {
    double const epsilon = 0.00001;
    double diff = a > b ? a - b : b - a;
    return diff < epsilon;
}

bool tuple::operator==(const tuple& t) const {
    return t.w == this->w && equal(t.x, this->x) && equal(t.y, this->y) && equal(t.z, this->z);
}

tuple tuple::operator+(const tuple &t) const {
    assert(!(this->isPoint() && t.isPoint()));
    return {this->x + t.x, this->y + t.y, this->z + t.z, this->w + t.w};
}
