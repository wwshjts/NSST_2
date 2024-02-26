#include <gtest/gtest.h>
#include "../sources/line.h"

TEST(LineTest, PointOnLine) {
    EXPECT_TRUE(Line(1.0, 0.0).in(Point(2.0, 2.0)));
    EXPECT_FALSE(Line(1.0, 1.0).in(Point(2.0, 1.0)));
}

TEST(LineTest, ParallelLines) {
    EXPECT_TRUE(Line(1.0/2, 1).parallel(Line(1.0/2, 42)));
    EXPECT_FALSE(Line(1.0/2, 1).parallel(Line(1.0/3, 1)));
}

TEST(PointTest, SamePoints) {
    EXPECT_TRUE(Point(1.0/2, 1).equal(Point(1.0/2, 1)));
    EXPECT_FALSE(Point(1.0/2, 1).equal(Point(1.0/3, 1)));
}

TEST(LineTest, FromPoints) {
    Line l(Point(1.0, 2.0), Point(2.0, 4.0));
    EXPECT_EQ(l.k, 2.0);
    EXPECT_EQ(l.b, 0.0);
}

TEST(LineTest, FromCoeff) {
    Line l(1.0, 2.0);
    EXPECT_TRUE(l.in(Point(2, 4)));
}

TEST(LineTest, Perpendicular) {
    Line l(4, 0);
    Line p = l.perpendicular(l, Point(0, 0));
    EXPECT_TRUE(p.in(Point(8, 2)));
}

TEST(LineTest, Intersection) {
    Line l1(2, 0);
    Line l2(Point(1, 2), Point(2, 0));
    Point p = l1.intersection(l1, l2);
    EXPECT_EQ(p.x, 1);
    EXPECT_EQ(p.y, 2);

}

int main() {
    testing::InitGoogleTest();
    return RUN_ALL_TESTS();
}