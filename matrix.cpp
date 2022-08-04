//
// Created by 包松乐 on 2022/8/2.
//

#include "matrix.h"
#include <cstdarg>

matrix::matrix(unsigned int a, unsigned int b, ...) {
    va_list ap;
    va_start(ap, b);
    for (int i = 0; i < a * b; i++) {
        double val = va_arg(ap, double);
        elements.push_back(val);
    }
    va_end(ap);

    row = a;
    col = b;
}

double matrix::get(unsigned int a, unsigned int b) {
    return elements[a * col + b];
}

bool matrix::operator==(const matrix &m) const {
    return row == m.row && col == m.col && elements == m.elements;
}
