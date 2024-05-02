#include <gtest/gtest.h>
#include "../sources/line.h"

TEST(LineTest, PointOnLine) {
    EXPECT_TRUE(Line::make_line(1.0, 0.0)->in(Point(2.0, 2.0)));
    EXPECT_FALSE(Line::make_line(1.0, 1.0)->in(Point(2.0, 1.0)));
}

TEST(LineTest, ParallelLines) {
    EXPECT_TRUE(Line::make_line(1.0/2, 1)->parallel(Line::make_line(1.0/2, 42).value()));
    EXPECT_FALSE(Line::make_line(1.0/2, 1)->parallel(Line::make_line(1.0/3, 1).value()));
}

TEST(PointTest, SamePoints) {
    EXPECT_TRUE(Point(1.0/2, 1).equal(Point(1.0/2, 1)));
    EXPECT_FALSE(Point(1.0/2, 1).equal(Point(1.0/3, 1)));
}

TEST(LineTest, FromPoints) {
    Line l = Line::make_line(Point(1.0, 2.0), Point(2.0, 4.0)).value();
    EXPECT_EQ(l.k(), 2.0);
    EXPECT_EQ(l.b(), 0.0);
}

TEST(LineTest, FromCoeff) {
    Line l = Line::make_line(1.0, 2.0).value();
    EXPECT_TRUE(l.in(Point(2, 4)));
}

TEST(LineTest, Perpendicular) {
    Line l = Line::make_line(4,0).value();
    Line p = Line::perpendicular(l, Point(0, 0)).value();
    EXPECT_TRUE(p.in(Point(8, 2)));
}

TEST(LineTest, Intersection) {
    Line l1 = Line::make_line(2, 0).value();
    Line l2 = Line::make_line(Point(1, 2), Point(2, 0)).value();
    Point p = Line::intersection(l1, l2).value();
    EXPECT_EQ(p.x, 1);
    EXPECT_EQ(p.y, 2);
}

TEST (LineTest, wrong_make_line) {
    EXPECT_FALSE(Line::make_line(Point(0.0, 0.0), Point(0.0, 0.0)));
}

TEST(LineTest, wrong_perpendicular) {
    Line l1 = (Line::make_line(Point(0.0, 0.0), Point(1.0, 0.0))).value();
    EXPECT_FALSE(Line::perpendicular(l1, Point(0.0, 0.0)));
}

int main() {
    testing::InitGoogleTest();
    return RUN_ALL_TESTS();
}
