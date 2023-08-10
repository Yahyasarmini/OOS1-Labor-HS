#include<iostream>
#include <string>
using namespace std;
class Student
{
private:// innerhalb der Klasse Zugänglich
    string _name;
    string _first_name;
public:
Student(string Name,string First_name);
~Student();

string getName();
string getFirstname();

void print(bool neueZ = false)  
    {
        if(neueZ==true){
            cout<< "print() mit Parameter; ";
        }
        else{
            cout << "print() ohne Parameter; ";
        }
         cout << "Student: " << _first_name << " " << _name << endl;
    }

};
Student::Student(string name, string first_name){
    _name=name;
    _first_name=first_name;
    cout << "Parametrisierter Konstruktor Student: " << _first_name << " " << _name << endl;
}
Student::~Student(){
    cout << "Destruktor Student: " << _first_name << " " << _name << endl;
}


string Student::getName(){
    return _name;
}
string Student::getFirstname(){
    return _first_name;
}
class Employee
{
    private: 
    string _name;
    string _first_name;
    public:
     Employee() : Employee("Erika", "Mustermann") {
            cout << "Standardkonstruktor Employee: " << _first_name << " " << _name << endl;
        };
       
    Employee(string vorname,string nachname): _name{nachname},_first_name{vorname}
    {
        cout << "Parametrisierter Konstruktor Employee: " << _first_name << " " << _name << endl;
    }
    ~Employee(){
        cout << "Destruktor Employee: " << _first_name << " " << _name << endl;
    }
    Employee( Student &student) : _name(student.getName()), _first_name(student.getFirstname()) {
            cout << "Konvertierungskonstruktor Employee: " << _first_name << " " << _name << endl;
        };
    /*
    Employee(Student stud){
    _name=stud.getName();
    _first_name=stud.getFirstname();
    cout << "Konvertierungskonstruktor Employee: " << _first_name << " " << _name << endl;
}
*/
void print(bool neuez = false) 
    {
        //cout << "Mitarbeiter: " << _first_name << " " << _name;
        if (neuez==true) {
            cout << "print() mit Parameter; ";
        }
        else{
            cout << "print() ohne Parameter; "; 
        }
        cout << "Mitarbeiter: " << _first_name << " " << _name << endl;
    }

};

int main(int argc, char *argv[])
{
    Student stud_mustermann = Student("Mustermann", "Max");
    Employee empl_mustermann = Employee(stud_mustermann);
    Employee mit_default = Employee();
    stud_mustermann.print();
    stud_mustermann.print(true);
    empl_mustermann.print();
    mit_default.print();
    Student *p_stud_mustermann = nullptr;
    cout << "Block wird betreten" << endl;
    {
        p_stud_mustermann = new Student("Mustermann", "Markus");
        p_stud_mustermann->print(true);
    }
    cout << "Block wurde verlassen" << endl;
    delete p_stud_mustermann;
    return 0;
}