//
// Created by 包松乐 on 2022/7/29.
//

#include "tuple.h"
#include "epsilon.h"
#include <cassert>
#include <cmath>

static int const POINT = 1;
static int const VECTOR = 0;

tuple::tuple(double x, double y, double z, int w) : x(x), y(y), z(z), w(w) {
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

bool tuple::operator==(const tuple &t) const {
    return t.w == w && equal(t.x, x) && equal(t.y, y) && equal(t.z, z);
}

tuple tuple::operator+(const tuple &t) const {
    assert(!(this->isPoint() && t.isPoint()));
    return {this->x + t.x, this->y + t.y, this->z + t.z, this->w + t.w};
}

tuple tuple::operator-(const tuple &t) const {
    return {this->x - t.x, this->y - t.y, this->z - t.z, this->w - t.w};
}

tuple tuple::operator-() const {
    return {-this->x, -this->y, -this->z, -this->w};
}

tuple tuple::operator*(double a) const {
    return {this->x * a, this->y * a, this->z * a, this->w};
}

tuple tuple::operator/(double a) const {
    return {this->x / a, this->y / a, this->z / a, this->w};
}

double tuple::magnitude() const {
    return sqrt(this->x * this->x + this->y * this->y + this->z * this->z);
}

tuple tuple::normalize() const {
    auto m = this->magnitude();
    return *this / m;
}

double tuple::operator*(const tuple &t) const {
    assert(this->isVector());
    assert(t.isVector());
    return this->x * t.x + this->y * t.y + this->z * t.z;
}

tuple tuple::cross(const tuple &t) const {
    return vector(
            this->y * t.z - this->z * t.y,
            this->z * t.x - this->x * t.z,
            this->x * t.y - this->y * t.x
    );
}

color::color(double red, double green, double blue): tuple(red, green, blue, 0) {
}

double color::red() const {
    return this->x;
}

double color::green() const {
    return this->y;
}

double color::blue() const {
    return this->z;
}

bool color::operator==(const color &t) const {
    return equal(this->red(), t.red()) && equal(this->blue(), t.blue()) && equal(this->green(), t.green());
}

color color::operator*(const color &t) const {
    return {this->red() * t.red(), this->green() * t.green(), this->blue() * t.blue()};
}
