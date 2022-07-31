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
    [[nodiscard]] bool isPoint() const;
    [[nodiscard]] bool isVector() const;
    [[nodiscard]] double magnitude() const;
    [[nodiscard]] tuple normalize() const;
    [[nodiscard]] tuple cross(const tuple&) const;
    bool operator==(const tuple&) const;
    tuple operator+(const tuple&) const;
    tuple operator-(const tuple&) const;
    double operator*(const tuple&) const;
    tuple operator-() const;
    tuple operator*(double) const;
    tuple operator/(double) const;
};

tuple point(double x, double y, double z);
tuple vector(double x, double y, double z);

class color : public tuple {
public:
    color(double, double, double);
    [[nodiscard]] double red() const;
    [[nodiscard]] double green() const;
    [[nodiscard]] double blue() const;

    bool operator==(const color&) const;
    color operator*(const color&) const;
};


#endif //SL_RAY_TRACER_TUPLE_H
