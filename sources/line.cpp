#include <cassert>
#include "line.h"

Point::Point(double x, double y) {
    this->x = x;
    this->y = y;
}

int Point::equal(const Point& other) const { 
    return (other.x == x) && (other.y == y);
}

int Line::parallel(const Line& other) const {
    return k == other.k;
}

int Line::in(const Point& p) const {
    return k * p.x + b == p.y;
}


Line::Line(const Point& p1, const Point& p2) { 
    assert(!p1.equal(p2));

    // just the Cramer rule
    double D = p1.x - p2.x;
    if (D == 0.0) { 
        this->b = p1.x;
        this->k = 0;
    } else {
        this->k = (p1.y - p2.y) / D; 
        this->b = (p1.x * p2.y - p2.x * p1.y) / D;
    }
}

Point Line::intersection(const Line& l1, const Line& l2) {
    assert(!l1.parallel(l2));
    Point res(0, 0);
    // just the Cramer rule 
    double D = l2.k - l1.k;
    res.x = (l1.b - l2.b) / D;
    res.y = (l1.b * l2.k - l1.k * l2.b) / D;
    return res; 
}

Line Line::perpendicular(const Line& l, const Point& p) {
    // using normal vector
    return Line(1/l.k, l.k * p.y - p.x);
}

Line::Line(double k, double b) {
    this->k = k;
    this->b = b;
}