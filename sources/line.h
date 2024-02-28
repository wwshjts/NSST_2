struct Point {
    double x;
    double y;
    Point(double x, double y);
    int equal (const Point& other) const;
};

// lines of the form y = k * x + b
// so this struct can't handle the lines like x = 42
struct Line {
    double k;
    double b;

    // only if the points do not lie on the same vertical line and p1 != p2
    Line(const Point& p1, const Point& p2); 
    Line(double k, double b); 
    int parallel(const Line& other) const;
    int in(const Point& p) const;
    // only if the lines are not parallel
    static Point intersection(const Line& l1, const Line& l2);
    // only if line l is not horizontal
    static Line perpendicular(const Line& l, const Point& p);
};