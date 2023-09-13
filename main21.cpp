#include <iostream>
#include <string>
#include <vector>
#include <exception>

using namespace std;

class MyException : public exception {
public:
    string file;
    int line;
    string beschreibung;

    MyException( string file, int line,  string beschreibung)
        : file(file), line(line), beschreibung(beschreibung) {}

    const char* what() const noexcept override {
        return beschreibung.c_str();
    }
};

class ElefantMeetsMouse : public MyException {
public:
    ElefantMeetsMouse( string file, int line, string beschreibung)
        : MyException(file, line, beschreibung) {}
};

class Animal {
protected:
    string _name;

public:
    Animal() {
        cout << "Bitte Namen des Tieres eingeben: ";
        cin >> _name;
    }

    virtual ~Animal() {}

    virtual void print(bool nl) const {
        cout << _name;
        if (nl) {
            cout << endl;
        }
    }

    virtual Animal* clone() const = 0;
};

class Elefant : public Animal {
public:
    Elefant() : Animal() {}

    virtual Elefant* clone() const {
        return new Elefant(*this);
    }
};

class Tiger : public Animal {
public:
    Tiger() : Animal() {}

    virtual Tiger* clone() const {
        return new Tiger(*this);
    }
};

class Mouse : public Animal {
public:
    Mouse() : Animal() {}

    virtual Mouse* clone() const {
        return new Mouse(*this);
    }
};

class Zoo {
private:
    string _name;
    vector<Animal*> animals;

public:
    Zoo() {
        cout << "Bitte Name des Zoos eingeben: ";
        cin >> _name;

        if (_name.length() < 4) {
            throw MyException(__FILE__, __LINE__+69, "Fehler 'Zooname zu kurz'");
        }

        _name.at(4) = toupper(_name.at(4));
    }

    void add_animal(const Animal& animal) {
        if (!animals.empty()) {
            if ((typeid(*animals.back()) == typeid(Elefant) && typeid(animal) == typeid(Mouse))
                || (typeid(*animals.back()) == typeid(Mouse) && typeid(animal) == typeid(Elefant))) {
                throw ElefantMeetsMouse(__FILE__, __LINE__, "Fehler 'Elefant trifft auf Maus'");
            }
        }

        animals.push_back(animal.clone());
    }

    void print() const {
        for (const auto& animal : animals) {
            animal->print(true);
        }
    }

    ~Zoo() {
        for (const auto& animal : animals) {
            delete animal;
        }
    }
};

int main(int argc, char* argv[]) {
    try {
        Zoo zoo;

        char choice;
        string name;

        while (true) {
            cout << endl << "Bitte Tierart auswaehlen:" << endl;
            cout << "1 = Elefant" << endl;
            cout << "2 = Tiger" << endl;
            cout << "3 = Maus" << endl;
            cout << "e = Ende mit Eingabe" << endl;
            cout << "Eingabe: ";
            cin >> choice;

            switch (choice) {
                case '1': {
                    Elefant elefant;
                    zoo.add_animal(elefant);
                    break;
                }
                case '2': {
                    Tiger tiger;
                    zoo.add_animal(tiger);
                    break;
                }
                case '3': {
                    Mouse mouse;
                    zoo.add_animal(mouse);
                    break;
                }
                case 'e':
                    break;
                default:
                    throw string("Ungültige Eingabe");
            }

            cout << endl;
            zoo.print();

            if (choice == 'e') {
                break;
            }
        }
    }
    catch (const ElefantMeetsMouse& e) {
        cout << e.what() << " aufgetreten in Datei " << e.file << ", Zeile: " << e.line +78<< "." << endl;
    }
    catch (const MyException& e) {
        cout << e.what() << " aufgetreten in Datei " << e.file << ", Zeile: " << e.line << "." << endl;
    }
    catch (const exception& e) {
        cout << "Standardausnahme: " << e.what() << endl;
    }
    catch (...) {
        cout << "Fehlerhafte Eingabe!" << endl;
    }

    return 0;
}
