//
// Created by 包松乐 on 2022/7/31.
//

#include <gtest/gtest.h>
#include "canvas.h"

TEST(CanvasTest, CreatingCanvas) {
    auto a = canvas(10, 20);
    EXPECT_EQ(10, a.getWidth());
    EXPECT_EQ(20, a.getHeight());

    for (auto w = 0; w < a.getWidth(); w++) {
        for (auto h = 0; h < a.getHeight(); h++) {
            auto c = a.getColorAt(w, h);
            EXPECT_EQ(c, color(0, 0, 0));
        }
    }
}

TEST(CanvasTest, WritePixel) {
    auto a = canvas(10, 20);
    auto red = color(1, 0, 0);

    a.writeColor(red, 2, 3);
    EXPECT_EQ(red, a.getColorAt(2, 3));
}