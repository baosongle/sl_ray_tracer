//
// Created by 包松乐 on 2022/7/31.
//

#ifndef SL_RAY_TRACER_CANVAS_H
#define SL_RAY_TRACER_CANVAS_H

#include <vector>
#include "tuple.h"

class canvas {
private:
    int width;
    int height;
    std::vector<std::vector<color>> colors;

public:
    canvas(int w, int h);
    [[nodiscard]] int getWidth() const;
    [[nodiscard]] int getHeight() const;
    [[nodiscard]] color getColorAt(int, int) const;
    void writeColor(color, int, int);
};


#endif //SL_RAY_TRACER_CANVAS_H
