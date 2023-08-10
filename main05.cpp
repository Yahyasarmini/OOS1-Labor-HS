#include<iostream>
using namespace std;
class Point{
    double x,y;
    public:
    void set_x(double _x){
        x=_x;
    }
    double get_x(){
        return x;
    }
    void set_y(double _y){
        y=_y;
    }
    double get_y(){
        return y;
    }
    void print(){
        cout << "print-Methode:\n"; 
        cout << "X = " << x ;
        cout << "\n";
        cout << "Y = " << y;
        cout << "\n";

    }
};
// hier die Klasse Punkt implementieren

int main(int argc, char* argv[]) {
    Point p;
    p.set_x(1);
    p.set_y(10);
    p.print();
    p.set_x(5);
    cout << "X ohne print(): " << p.get_x() << endl;
    cout << "Y ohne print(): " << p.get_y() << endl;
    return 0;
}
