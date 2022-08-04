//
// Created by 包松乐 on 2022/8/2.
//

#ifndef SL_RAY_TRACER_MATRIX_H
#define SL_RAY_TRACER_MATRIX_H

#include <vector>

class matrix {
private:
    std::vector<double> elements;
    uint32_t row;
    uint32_t col;

public:
    matrix(unsigned a, unsigned b, ...);
    double get(unsigned a, unsigned b);
};


#endif //SL_RAY_TRACER_MATRIX_H
