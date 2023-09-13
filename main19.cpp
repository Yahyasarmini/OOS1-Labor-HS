#include <array>
#include <string>
#include <vector>
#include <iostream>

using namespace std;

class Meal {
    protected:
        string name;
        vector<string> zutaten;
    public:
        Meal(string name);
        void add_toppings(string topping);
        virtual void prepare()=0;
};

Meal::Meal(string name): name(name) {}
void Meal::add_toppings(string topping) {
    zutaten.push_back(topping);
}

class Pizza: public Meal {
    public:
        Pizza(string name);
        void add_toppings(string zutat);
        void prepare() override;
};

Pizza::Pizza(string name): Meal(name) {}
void Pizza::add_toppings(string topping) {
    Meal::add_toppings(topping);
}
void Pizza::prepare() {
    cout << "Pizza "<< name <<". Pizzaboden, belegt mit:" <<endl;
    for (string zutat : zutaten) {
        cout << "- " << zutat << endl;
    }
}

class Burger: public Meal {
    public:
        Burger(string name);
        void add_toppings(string topping);
        void prepare() override;
};
Burger::Burger(string name): Meal(name) {}
void Burger::add_toppings(string zutat){
    Meal::add_toppings(zutat);
}
void Burger::prepare() {
    cout << name <<". Brötchen mit:" <<endl;
    for (string zutat : zutaten) {
        cout << "- " << zutat << endl;
    }
}

int main(int argc, char* argv[])
{
    Pizza *mista = new Pizza("Mista");
    mista->add_toppings("Salami");
    mista->add_toppings("Pilzen");
    Meal *hawaii = new Pizza("Hawaii");
    hawaii->add_toppings("Schinken");
    hawaii->add_toppings("Ananas");
    Burger *hamburger = new Burger("Hamburger");
    hamburger->add_toppings("Hackfleisch");
    Meal *cheesburger = new Burger("Cheesburger");
    cheesburger->add_toppings("Hackfleisch");
    cheesburger->add_toppings("Käse");
    array<Meal *, 4> speisekarte = {mista, hawaii, hamburger, cheesburger};
    for (Meal *g : speisekarte)
    {
        g->prepare(); //*[1]
    }
    return 0;
}
