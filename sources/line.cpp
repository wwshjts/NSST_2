#include "line.h"
#define EPS 0.000001

static bool double_equal(double a, double b_) {
    return std::abs(a - b_) < EPS;
}

Point::Point() : x { 0 }, y { 0 } {};

Point::Point(double x, double y) {
    this->x = x;
    this->y = y;
}

int Point::equal(const Point& other) const { 
    return double_equal(other.x, x) && double_equal(other.y, y);
}

int Line::parallel(const Line& other) const {
    return double_equal(k_, other.k_);
}

int Line::in(const Point& p) const {
    return double_equal(k_ * p.x + b_, p.y);
}

Line::Line(const Point& p1, const Point& p2) { 
    assert(!p1.equal(p2));
    assert(p1.x != p2.x);

    double D = p1.x - p2.x;
    this->k_ = (p1.y - p2.y) / D; 
    this->b_ = (p1.x * p2.y - p2.x * p1.y) / D;
}

std::optional<Point> Line::intersection(const Line& l1, const Line& l2) {
    if (l1.parallel(l2)) {
        return std::nullopt;
    }
    Point res; 
    // if the lines are not parallel D != 0
    double D = l2.k_ - l1.k_;
    res.x = (l1.b_ - l2.b_) / D;
    res.y = (l1.b_ * l2.k_ - l1.k_ * l2.b_) / D;
    return res;
}

std::optional<Line> Line::perpendicular(const Line& l, const Point& p) {
    if (double_equal(l.k_, 0)) {
        return std::nullopt;
    }

    Line res;
    // using normal vector
    res.k_ = 1 / l.k_;
    res.b_ = l.k_ * p.y - p.x;
    return res;
}

Line::Line(double k, double b) {
    this->k_ = k;
    this->b_ = b;
}

std::optional<Line> Line::make_line(const Point& p1, const Point& p2) {
    if (p1.equal(p2) || double_equal(p1.x, p2.x)) {
        return std::nullopt;
    }
    return Line(p1, p2);
}

std::optional<Line> Line::make_line(double k, double b) {
    return Line(k, b);
}

