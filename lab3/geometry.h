class Point {
private:
    int x;
    int y;
public:
    Point(): x{0}, y{0} {}
    Point(int x, int y): x{x}, y{y} {}
    int getX() const;
    int getY() const;
    void setX(const int new_x);
    void setY(const int new_y);
};

class PointArray {
private:
    Point *contents;
    int length;

    void resize(int n);
public:
    // constructors
    PointArray(): contents{new Point[0]}, length{0} {}
    PointArray(const Point points[], const int size);
    PointArray(const PointArray& pa);
    // descructor
    ~PointArray() {
        delete[] contents;
    }
    // interface
    void push_back(const Point &p);
    void insert(const int position, const Point &p);
    void remove(const int pos);
    int getSize() const;
    void clear();
    Point *get(const int position);
    const Point *get(const int position) const;
};

class Polygon {
private:
    PointArray pa;
    static int instances;
public:
    // constructors
    Polygon(const Point points[], const int length): pa{PointArray(points, length)} {
        instances++;
    }
    Polygon(const PointArray points): pa{points} {
        instances++;
    }
    // descructor
    ~Polygon() {
        instances--;
    }
    // interface
    virtual double area() = 0;
    static int getNumPolygons();
    int getNumSides();
    const PointArray *getPoints();
};

class Rectangle: public Polygon {
private:
    Point lower_left;
    Point upper_right;
public:
    Rectangle(Point lower_left, Point upper_right);
    Rectangle(int p1, int p2, int p3, int p4);
    double area() override;
};

class Triangle: public Polygon {
private:
    Point p1;
    Point p2;
    Point p3;
public:
    Triangle(Point p1, Point p2, Point p3);
    double area() override;
};
