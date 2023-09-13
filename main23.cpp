#include <iostream>
#include <vector>
using namespace std;
/*
Der Preis für ein einzelnes Produkt soll auf die gleiche Art und Weise 
abgefragt werden können wie für ein Paket in dem Produkte und/oder weitere 
Pakete enthalten sein können, die wiederum Produkte und/oder weitere Pakete 
enthalten können. Nutzen Sie hierzu das Composite Pattern. Implementieren sie das 
Interface IComponent sowie die Klassen Product und Box, sodass das gegebene Hauptprogramm 
die folgende Ausgabe erzeugt:

Preisermittlung für ein einfaches Produkt:
Preis: 10
*/
class IComponent{
    public :
    virtual int get_price()=0;
    virtual void add(IComponent *component){}
};
class Product : public IComponent{
    private: 
    int _price;
    public : 
    Product(int price){
        this->_price=price;
    }
    int get_price()override {
        return _price;
    }
};
class Box: public IComponent
{
    public:
        vector<IComponent*> components;
        int get_price() override
        {
            int price = 0;
            for(size_t i = 0; i < components.size(); i++)
            {
                price += components[i]->get_price();
            }
            return price;
        }
        virtual void add(IComponent* component)
        {
            components.push_back(component);
        }
};

void calculate_price(IComponent *component)
{
    cout << "Preis: " << component->get_price() << endl;
}

int main(int argc, char* argv[]) {

    cout << "Preisermittlung für ein einfaches Produkt: " << endl;
    IComponent *product = new Product(10);
    calculate_price(product);
    cout << endl << endl;

    cout << "Preisermittlung für eine verschachtelte Box: " << endl;
    IComponent *outer_box = new Box;
    IComponent *inner_box_1 = new Box;
    IComponent *product_1 = new Product(10);
    IComponent *product_2 = new Product(5);
    IComponent *product_3 = new Product(4);
    inner_box_1->add(product_1);
    inner_box_1->add(product_2);
    IComponent *inner_box_2 = new Box;
    inner_box_2->add(product_3);
    outer_box->add(inner_box_1);
    outer_box->add(inner_box_2);
    IComponent *product_4 = new Product(7);
    inner_box_2->add(product_4);
    calculate_price(outer_box);
    cout << endl << endl;

    return 0;
}

