//
// Created by 包松乐 on 2022/7/31.
//

#include "canvas.h"
#include <cassert>
#include <fstream>

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

static int scaleTo255(double const d) {
    int a = d * 255;
    if (a < 0) {
        return 0;
    } else if (a > 255) {
        return 255;
    } else {
        return a;
    }
}

void canvas::toFile(const std::string& path) const {
    using std::endl;
    std::ofstream out;
    out.open(path);
    out << "P3" << endl << width << " " << height << endl << "255" << endl;
    for (auto w = 0; w < width; w++) {
        for (auto h = 0; h < height; h++) {
            if (h != 0) {
                out << " ";
            }
            auto c = getColorAt(w, h);
            out << scaleTo255(c.red()) << " " << scaleTo255(c.green()) << " " << scaleTo255(c.blue());
        }
        out << endl;
    }
    out.close();
}
