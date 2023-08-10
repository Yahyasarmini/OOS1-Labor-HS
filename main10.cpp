
#include <string>
#include <iostream>
using namespace std;

class Person {
	string _name;
	int _check_out_duration;
public:
	Person(string name, int check_out_duration = 0);
	int get_check_out_duration() const;
	void print() const;
};

// Implmentierung des Konstruktors und der Methoden
Person::Person(string Name,int Dauer):_name(Name),_check_out_duration(Dauer){}
int Person::get_check_out_duration() const{
    return _check_out_duration;
}
void Person::print() const 
{ 
    cout << _name << ",";
}
class Lecturer : public Person
{
	int _examiner_id;
public:
	Lecturer(string name, int examiner_id);
	void print() const;
};

// Implmentierung des Konstruktors und der Methoden
Lecturer::Lecturer(string name,int ID):Person(name,90),_examiner_id(ID){}
void Lecturer::print() const{
    Person::print();
    cout << " Prüfernummer " <<_examiner_id << endl;
}
class Student : public Person
{
	int _matriculation_number;

public:
	Student(string name, int matriculation_number);
	void print() const;
};
// Implmentierung des Konstruktors und der Methoden
Student::Student(string name,int Matr_nr):Person(name,30),_matriculation_number(Matr_nr){}
void Student::print()const{
    Person::print();
    cout << " Matrikelnummer " <<_matriculation_number << endl;
}

int main(int argc, char *argv[]) {
    Student smith = Student("smith", 12345678);
    Lecturer miller = Lecturer("miller", 98);
    smith.print();
    cout << "Ausleihdauer: " << smith.get_check_out_duration() << " Tage(e)" << endl;
    miller.print();
    cout << "Ausleihdauer: " << miller.get_check_out_duration() << " Tage(e)" << endl;
}

