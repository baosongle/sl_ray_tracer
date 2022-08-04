//
// Created by 包松乐 on 2022/8/2.
//

#include <gtest/gtest.h>
#include "matrix.h"
#include "epsilon.h"

TEST(MatrixTest, CreateMatrix4x4) {
    auto m = matrix(
            4, 4,
            1.0, 2.0, 3.0, 4.0,
            5.5, 6.5, 7.5, 8.5,
            9.0, 10.0, 11.0, 12.0,
            13.5, 14.5, 15.5, 16.5
            );

    EXPECT_TRUE(equal(1, m.get(0, 0)));
    EXPECT_TRUE(equal(4, m.get(0, 3)));
    EXPECT_TRUE(equal(5.5, m.get(1, 0)));
    EXPECT_TRUE(equal(7.5, m.get(1, 2)));
    EXPECT_TRUE(equal(11, m.get(2, 2)));
    EXPECT_TRUE(equal(13.5, m.get(3, 0)));
    EXPECT_TRUE(equal(15.5, m.get(3, 2)));
}

TEST(MatrixTest, CreateMatrix2x2) {
    auto m = matrix(
            2, 2,
            -3.0, 5.0,
            1.0, -2.0
            );
    EXPECT_TRUE(equal(-3.0, m.get(0, 0)));
    EXPECT_TRUE(equal(5.0, m.get(0, 1)));
    EXPECT_TRUE(equal(1.0, m.get(1, 0)));
    EXPECT_TRUE(equal(-2.0, m.get(1, 1)));
}

TEST(MatrixTest, CreateMatrix3x3) {
    auto m = matrix(
            3, 3,
            -3.0, 5.0, 0.0,
            1.0, -2.0, -7.0,
            0.0, 1.0, 1.0
    );
    EXPECT_TRUE(equal(-3.0, m.get(0, 0)));
    EXPECT_TRUE(equal(5.0, m.get(0, 1)));
    EXPECT_TRUE(equal(0.0, m.get(0, 2)));
    EXPECT_TRUE(equal(1.0, m.get(1, 0)));
    EXPECT_TRUE(equal(-2.0, m.get(1, 1)));
    EXPECT_TRUE(equal(-7.0, m.get(1, 2)));
    EXPECT_TRUE(equal(0.0, m.get(2, 0)));
    EXPECT_TRUE(equal(1.0, m.get(2, 1)));
    EXPECT_TRUE(equal(1.0, m.get(2, 2)));
}

TEST(MatrixText, MatrixEquality1) {
    auto a = matrix(
            4, 4,
            1.0, 2.0, 3.0, 4.0,
            5.0, 6.0, 7.0, 8.0,
            9.0, 8.0, 7.0, 6.0,
            5.0, 4.0, 3.0, 2.0
            );
    auto b = matrix(
            4, 4,
            1.0, 2.0, 3.0, 4.0,
            5.0, 6.0, 7.0, 8.0,
            9.0, 8.0, 7.0, 6.0,
            5.0, 4.0, 3.0, 2.0
    );
    EXPECT_EQ(a, b);
}

TEST(MatrixText, MatrixEquality2) {
    auto a = matrix(
            4, 4,
            0.0, 2.0, 3.0, 4.0,
            5.0, 6.0, 7.0, 8.0,
            9.0, 8.0, 7.0, 6.0,
            5.0, 4.0, 3.0, 2.0
    );
    auto b = matrix(
            4, 4,
            1.0, 2.0, 3.0, 4.0,
            5.0, 6.0, 7.0, 8.0,
            9.0, 8.0, 7.0, 6.0,
            5.0, 4.0, 3.0, 2.0
    );
    EXPECT_TRUE(a != b);
}
