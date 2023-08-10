#include <iostream>
#include <string>
using namespace std;

/* HIER */
class Employee
{
    string _first_name;
    string _last_name;
 
public:
    Employee(const string, const string);
    void print() const;
};

Employee::Employee(const string f_n, const string l_n)
{
    /* HIER */
    _first_name=f_n;
    _last_name=l_n;
    
}
void Employee::print() const
{
    cout << _last_name << ", " << _first_name << endl;
}
class Manager : public Employee
{
    double _salary;

public:
    Manager(const string, const string, double );
    double get_income() const;
    void print() const;
};

Manager::Manager(const string f_n, const string l_n, double s = 0)
    : Employee(f_n, l_n) //Initialisierungsliste
{
    /* HIER */
    _salary=s;
}
double Manager::get_income() const
{
    /* HIER */
    return _salary;
}
void Manager::print() const
{
    cout << "Manager: ";
    Employee::print();
}
class Worker : public Employee
{
    double _hourly_earnings;
    double _hours;

public:
    Worker(const string, const string, double = 0.0, double = 0.0);
    double get_income() const;
    void print() const;
};
Worker::Worker(const string f_n, const string l_n,
                   double h_e, double h)
    : Employee(f_n, l_n)
{
    /* HIER */
    _hourly_earnings = h_e;
    _hours=h;
}
double Worker::get_income() const
{
    /* HIER */
    return _hourly_earnings * _hours;
}

void Worker::print() const
{
    cout << "Worker: ";
    Employee::print();
}
int main()
{
    Manager m("Yahya", "Sarmini", 1000.00);
    m.print();
    cout << "Gehalt: " << m.get_income() << endl << endl;
    Worker w("Peter", "Mueller", 15.00, 40);
    w.print();
    cout << "Lohn: " << w.get_income() << endl;
    return 0;
}
