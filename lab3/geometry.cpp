#include "geometry.h"
#include <cmath>
#include <iostream>

// Point
int Point::getX() const {
    return x;
}

int Point::getY() const {
    return y;
}

void Point::setX(const int new_x) {
    x = new_x;
}

void Point::setY(const int new_y) {
    y = new_y;
}

// PointArray
PointArray::PointArray(const Point points[], const int size): contents{new Point[size]}, length{size} {
    for (auto i = 0; i < size; ++i) {
        contents[i] = points[i];
    }
}

PointArray::PointArray(const PointArray& pa): contents{new Point[pa.length]}, length{pa.length} {
    for (auto i = 0; i < pa.length; ++i) {
        contents[i] = *pa.get(i);
    }
}

void PointArray::resize(int n) {
    Point *newContents = new Point[n];
    for (auto i = 0; i < n; ++i) {
        newContents[i] = contents[i];
    }
    delete[] contents;
    contents = newContents;
    length = n;
}

void PointArray::push_back(const Point &p) {
    resize(length+1);
    contents[length-1] = p;
}

void PointArray::insert(const int position, const Point &p) {
    if (position < 0 || position > length) {
        return;
    }
    if (position == length) {
        push_back(p);
    }
    resize(length+1);
    for (auto i = length-1; i > position; --i) {
        contents[i] = contents[i-1];
    }
    contents[position] = p;
}

void PointArray::remove(const int pos) {
    if (pos < 0 || pos > length) {
        return;
    }
    for (auto i = pos; i < length - 1; ++i) {
        contents[i] = contents[i+1];
    }
}

int PointArray::getSize() const {
    return length;
}

void PointArray::clear() {
    resize(0);
}

Point *PointArray::get(const int position) {
    return &contents[position];
}

const Point *PointArray::get(const int position) const {
    return &contents[position];
}

// Polygon
int Polygon::instances = 0;

int Polygon::getNumPolygons() {
    return instances;
}

const PointArray *Polygon::getPoints() {
    return &pa;
}

// Rectangle
Rectangle::Rectangle(Point lower_left, Point upper_right): Polygon((Point []){lower_left, upper_right}, 2), lower_left{lower_left}, upper_right{upper_right} {}

Rectangle::Rectangle(int p1, int p2, int p3, int p4): Polygon((Point []){Point{p1, p2}, Point{p3, p4}}, 2), lower_left{p1, p2}, upper_right{p3, p4} {}

double Rectangle::area() {
    return (upper_right.getX() - lower_left.getX()) * (upper_right.getY() - lower_left.getY());
}

// Triangle
Triangle::Triangle(Point p1, Point p2, Point p3): Polygon((Point []){p1, p2, p3}, 3), p1{p1}, p2{p2}, p3{p3} {}

double Triangle::area() {
    double a = std::sqrt(std::pow(p1.getX() - p2.getX(), 2) + std::pow(p1.getY() - p2.getY(), 2));
    double b = std::sqrt(std::pow(p1.getX() - p3.getX(), 2) + std::pow(p1.getY() - p3.getY(), 2));
    double c = std::sqrt(std::pow(p2.getX() - p3.getX(), 2) + std::pow(p2.getY() - p3.getY(), 2));
    double s = (a + b + c) / 2;
    return std::sqrt(s * (s - a) * (s - b) * (s - c));
}


void printAttributes(Polygon *poly) {
    std::cout << "Area: " << poly->area() << "\n";
    std::cout << "Coordinates:\n";
    PointArray points = *poly->getPoints();
    for (auto i = 0; i < points.getSize(); ++i) {
        std::cout << "(" << (*points.get(i)).getX() << ", " << (*points.get(i)).getY() << ")\n";
    }
}

void test() {
    // Point
    Point p1;
    std::cout << p1.getX() << p1.getY() << "\n";;

    Point p2(2, 3);
    std::cout << p2.getX() << p2.getY() << "\n";

    p2.setX(5);
    p2.setY(7);
    std::cout << p2.getX() << p2.getY() << "\n";

    Point p3 {0, 7};
    std::cout << p3.getX() << p3.getY() << "\n";

    // PointArray
    const Point points[] {p1, p2};
    PointArray pa {points, 2};
    std::cout << (*pa.get(0)).getX() << (*pa.get(1)).getY() << "\n";

    // Rectangle
    Rectangle rec1 {p1, p2};
    std::cout << rec1.area() << " " << Polygon::getNumPolygons() << "\n";

    Rectangle rec2 {0, 0, 5, 7};
    std::cout << rec2.area() << " " << Polygon::getNumPolygons() << "\n";

    // Triangle
    Triangle tri {p1, p2, p3};
    std::cout << tri.area() << " " << Polygon::getNumPolygons() << "\n";

    PointArray triPa = *tri.getPoints();
    for (auto i = 0; i < triPa.getSize(); ++i) {
        std::cout << (*triPa.get(i)).getX() << (*triPa.get(i)).getY() << "\n";
    }
}

int main() {
    //test();
    //std::cout << "\n\n\n";

    std::cout << "Rectangle Lower left coordinates:\n";

    std::cout << "X: ";
    int llX;
    std::cin >> llX;

    std::cout << "Y: ";
    int llY;
    std::cin >> llY;

    std::cout << "Rectangle Upper right coordinates:\n";

    std::cout << "X: ";
    int urX;
    std::cin >> urX;

    std::cout << "Y: ";
    int urY;
    std::cin >> urY;

    Rectangle rec {{llX, llY}, {urX, urY}};

    std::cout << "Triangle:\n";

    std::cout << "Point 1:\n";
    std::cout << "X: ";
    int p1X;
    std::cin >> p1X;

    std::cout << "Y: ";
    int p1Y;
    std::cin >> p1Y;

    std::cout << "Point 2:\n";
    std::cout << "X: ";
    int p2X;
    std::cin >> p2X;

    std::cout << "Y: ";
    int p2Y;
    std::cin >> p2Y;

    std::cout << "Point 3:\n";
    std::cout << "X: ";
    int p3X;
    std::cin >> p3X;

    std::cout << "Y: ";
    int p3Y;
    std::cin >> p3Y;

    Triangle tri {Point{p1X, p1Y}, Point{p2X, p2Y}, Point{p3X, p3Y}};

    std::cout << "\nRectangle Attributes:\n";
    printAttributes(&rec);
    std::cout << "\nTriangle Attributes:\n";
    printAttributes(&tri);
}
