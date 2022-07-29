//
// Created by 包松乐 on 2022/7/29.
//

#include "tuple.h"

tuple::tuple(double x, double y, double z, int w): x(x), y(y), z(z), w(w) {
}

tuple point(double x, double y, double z) {
    return {x, y, z, 1};
}

tuple vector(double x, double y, double z) {
    return {x, y, z, 0};
}

bool tuple::isPoint() const {
    return this->w == 1;
}

bool tuple::isVector() const {
    return this->w == 0;
}

static bool equal(double a, double b) {
    double const epsilon = 0.00001;
    double diff = a > b ? a - b : b - a;
    return diff < epsilon;
}

bool tuple::operator==(const tuple& t) const {
    return t.w == this->w && equal(t.x, this->x) && equal(t.y, this->y) && equal(t.z, this->z);
}
