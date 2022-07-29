//
// Created by 包松乐 on 2022/7/29.
//

#ifndef SL_RAY_TRACER_TUPLE_H
#define SL_RAY_TRACER_TUPLE_H


class tuple {
public:
    double x;
    double y;
    double z;
    int w;

    tuple(double, double, double, int);
    bool isPoint() const;
    bool isVector() const;
};

tuple point(double x, double y, double z);
tuple vector(double x, double y, double z);

#endif //SL_RAY_TRACER_TUPLE_H
