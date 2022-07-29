//
// Created by 包松乐 on 2022/7/29.
//

#ifndef SL_RAY_TRACER_TUPLE_TEST_H
#define SL_RAY_TRACER_TUPLE_TEST_H

#include <gtest/gtest.h>
#include "tuple.h"

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

#endif //SL_RAY_TRACER_TUPLE_TEST_H
