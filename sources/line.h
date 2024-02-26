struct Point {
    double x;
    double y;
    Point(double x, double y);
    int equal (const Point& other) const;
};

struct Line {
    double k;
    double b;

    Line(const Point& p1, const Point& p2); 
    Line(double k, double b); 
    int parallel(const Line& other) const;
    int in(const Point& p) const;
    Point intersection(const Line& l1, const Line& l2);
    Line perpendicular(const Line& l, const Point& p);
};