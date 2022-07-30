//
// Created by 包松乐 on 2022/7/29.
//

#ifndef SL_RAY_TRACER_TUPLE_TEST_H
#define SL_RAY_TRACER_TUPLE_TEST_H

#include <gtest/gtest.h>
#include "tuple.h"
#include <cmath>

TEST(TupleTest, MakeVector) {
    tuple t = vector(4.3, -4.2, 3.1);
    EXPECT_EQ(4.3, t.x);
    EXPECT_EQ(-4.2, t.y);
    EXPECT_EQ(3.1, t.z);
    EXPECT_EQ(0, t.w);
    EXPECT_FALSE(t.isPoint());
    EXPECT_TRUE(t.isVector());
}

TEST(TupleTest, MakePoint) {
    tuple t = point(4.3, -4.2, 3.1);
    EXPECT_EQ(4.3, t.x);
    EXPECT_EQ(-4.2, t.y);
    EXPECT_EQ(3.1, t.z);
    EXPECT_EQ(1, t.w);
    EXPECT_TRUE(t.isPoint());
    EXPECT_FALSE(t.isVector());
}

TEST(TupleTest, PointEqual) {
    auto a = point(1, 2, 3);
    auto b = point(1, 2, 3);
    EXPECT_TRUE(a == b);
}

TEST(TupleTest, VectorEqual) {
    auto a = vector(3, 4, 5);
    auto b = vector(3, 4, 5);
    EXPECT_TRUE(a == b);
}

TEST(TupleTest, VectorNotEqualPoint) {
    auto a = vector(3, 4, 5);
    auto b = point(3, 4, 5);
    EXPECT_FALSE(a == b);
}

TEST(TupleTest, EqualIfDiffEpsilon) {
    auto a = point(1, 2, 3);
    auto b = point(1.00000001, 2, 3);
    EXPECT_FALSE(a.x == b.x);
    EXPECT_TRUE(a == b);
}

TEST(TupleTest, PointAddVectorGetPoint) {
    auto p = point(3, -2, 5);
    auto v = vector(-2, 3, 1);
    auto c = p + v;

    // point add vector get point
    EXPECT_TRUE(c.isPoint());

    // x, y and z add
    EXPECT_EQ(1, c.x);
    EXPECT_EQ(1, c.y);
    EXPECT_EQ(6, c.z);
}

TEST(TupleTest, VectorAddVectorGetVector) {
    auto a = vector(-3, 9, 6);
    auto b = vector(9, -4, -2);
    auto c = a + b;

    EXPECT_TRUE(c.isVector());
    EXPECT_EQ(6, c.x);
    EXPECT_EQ(5, c.y);
    EXPECT_EQ(4, c.z);
}

TEST(TupleTest, PointSubstractPointGetVector) {
    auto a = point(1, 2, 3);
    auto b = point(5, 6, 7);
    auto c = a - b;

    EXPECT_EQ(c, vector(-4, -4, -4));
}

TEST(TupleTest, VectorSubtractVectorGetVector) {
    auto a = vector(1, 4, 3);
    auto b = vector(2, 3, 1);
    auto c = a - b;

    EXPECT_TRUE(c.isVector());
    EXPECT_EQ(c, vector(-1, 1, 2));
}

TEST(TupleTest, NagatingTuple) {
    auto a = vector(1, 2, 3);
    auto c = -a;

    EXPECT_TRUE(c.isVector());
    EXPECT_EQ(c, vector(-1, -2, -3));
}

TEST(TupleTest, MultiplyVector) {
    auto a = vector(1, 2, 3);
    auto b = a * 3;
    auto c = a * 0.5;

    EXPECT_EQ(b, vector(3, 6, 9));
    EXPECT_EQ(c, vector(0.5, 1, 1.5));
}

TEST(TupleTest, DivideVector) {
    auto a = vector(1, 2, 3);
    auto b = a / 2;

    EXPECT_EQ(b, vector(0.5, 1, 1.5));
}

TEST(TupleTest, ComputeMagnitude) {
    auto a = vector(2, 1, 5);
    EXPECT_EQ(sqrt(30), a.magnitude());
}

TEST(TupleTest, NormalizeTuple) {
    auto a = vector(3, 0, 0);
    auto b = a.normalize();

    EXPECT_EQ(1, b.x);
    EXPECT_EQ(0, b.y);
    EXPECT_EQ(0, b.z);
    EXPECT_TRUE(b.isVector());
}

TEST(TupleTest, NormalizeTuple2) {
    auto a = vector(5, 6, 7);
    auto b = a.normalize();

    EXPECT_EQ(5 / sqrt(110), b.x);
    EXPECT_EQ(6 / sqrt(110), b.y);
    EXPECT_EQ(7 / sqrt(110), b.z);
    EXPECT_TRUE(b.isVector());
}

TEST(TupleTest, DotProduct) {
    auto a = vector(1, 2, 3);
    auto b = vector(11, 12, 13);
    auto c = a * b;

    EXPECT_EQ(74, c);
}

#endif //SL_RAY_TRACER_TUPLE_TEST_H
