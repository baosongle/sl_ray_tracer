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
