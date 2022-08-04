//
// Created by 包松乐 on 2022/8/4.
//

#ifndef SL_RAY_TRACER_EPSILON_H
#define SL_RAY_TRACER_EPSILON_H

double const epsilon = 0.00001;

bool equal(double a, double b) {
    if (a >= b) {
        return (a - b) < epsilon;
    } else {
        return equal(b, a);
    }
}

#endif //SL_RAY_TRACER_EPSILON_H
