#include <optional>
#include <cassert>
#include <cmath> // abs

struct Point {
    double x;
    double y;
    Point();
    Point(double x, double y);
    int equal (const Point& other) const;
};

// lines of the form y = k * x + b
// so this struct can't handle the lines like x = 42
class Line {
    double k_;
    double b_;

    Line() = default;
    Line(const Point& p1, const Point& p2); 
    Line(double k, double b);

public: 
    static std::optional<Line> make_line(const Point& p1, const Point& p2);
    static std::optional<Line> make_line(double k, double b);

    int parallel(const Line& other) const;
    int in(const Point& p) const;
    // only if the lines are not parallel
    static std::optional<Point> intersection(const Line& l1, const Line& l2);
    // only if line l is not horizontal
    static std::optional<Line> perpendicular(const Line& l, const Point& p);

    // getters
    double k() { return k_; }
    double b() { return b_; }
  
};
