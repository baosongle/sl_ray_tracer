//
// Created by 包松乐 on 2022/7/31.
//

#include "canvas.h"
#include <cassert>

canvas::canvas(int w, int h) {
    assert(w > 0);
    assert(h > 0);
    this->width = w;
    this->height = h;
    this->colors = std::vector(w, std::vector(h, color(0, 0, 0)));
}

int canvas::getWidth() const {
    return this->width;
}

int canvas::getHeight() const {
    return this->height;
}

color canvas::getColorAt(int w, int h) const {
    assert(w < width);
    assert(h < height);
    return this->colors[w][h];
}

void canvas::writeColor(color c, int w, int h) {
    assert(w < width);
    assert(h < height);
    this->colors[w][h] = c;
}


