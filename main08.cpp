#include <iostream>
using namespace std;

class Point {
private:
    double _x;
    double _y;
public:
    Point(double x = 0.0, double y = 0.0) : _x(x), _y(y) {

    }
    double get_x(){
        return _x;
    }
    double get_y(){
        return _y;
    }
    void set_x(double x) 
    { 
        _x = x; 
    }
    void set_y(double y) 
    { 
        _y = y; 
    }
    void move(double dx, double dy) {
        _x += dx;
        _y += dy;
    }
    void print(bool newline = true) const {
        cout << "(" << _x << ", " << _y << ")";
        if (newline) cout << endl;
    }
};

class Circle {
private:
    Point _centre;
    double _radius;
public:
    Circle(const Point& centre = Point(), double radius = 1.0)
        : _centre(centre), _radius(radius) {

        }
    const Point& get_centre()  
    { 
        return _centre; 
    }
    double get_radius()  
    { 
        return _radius; 
    }
    void set_centre( Point& centre) 
    {
         _centre = centre; 
    }
    void set_radius(double radius) 
    { 
        _radius = radius; 
    }
    void move(double dx, double dy) {
        _centre.move(dx, dy);
    }
    void print(bool newline = true) 
     {
        cout << "[" <<"(" << _centre.get_x() << ", " << _centre.get_y() << "), "  << _radius << "]";
        if (newline) cout << endl;
     }
};

int main(int argc, char *argv[]) {
    Point p;
    Circle c(p);
    cout << "Ausgabe 1:" << endl;
    p.print();
    c.print();
    p.set_x(1.1);
    p.set_y(2.2);
    c.set_centre(p);
    c.set_radius(3.3);
    cout << "Ausgabe 2:" << endl;
    p.print(false);
    cout << " == (" << p.get_x() << ", " << p.get_y() << ")"
        << endl;
    c.print();
    p.move(1.0, 1.0);
    c.move(2.0, 2.0);
    cout << "Ausgabe 3:" << endl;
    p.print();
    c.print();
    return 0;
}
