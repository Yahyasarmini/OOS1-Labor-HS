#include <iostream>
#include <list>
#include <string>
#include <map>
#include <exception>

using namespace std;

// Ausnahme-Klasse implementieren
class OutOfStockException : public exception
{
private:
    string exceptionName;

public:
    OutOfStockException(string exceptionName_)
        : exceptionName(exceptionName_)
    {
    }

    const char* what() const noexcept override
    {
        return exceptionName.c_str();
    }
};

// Interface ISubscriber implementieren
class ISubscriber
{
public:
    virtual void update(string text) = 0;
};

// Klassen Customer und GoldCustomer implementieren
class Customer : public ISubscriber
{
private:
    int customerID;
    static int idGenerator;

public:
    Customer()
    {
        customerID = ++idGenerator;
    }

    void update(string text) override
    {
        cout << "Customer " << customerID << ": neue Nachricht verfügbar --> " << text << endl;
    }
};

class GoldCustomer : public ISubscriber
{
private:
    int goldCustomerID;
    static int idGenerator;

public:
    GoldCustomer()
    {
        goldCustomerID = ++idGenerator;
    }

    void update(string text) override
    {
        cout << "GoldCustomer " << goldCustomerID << ": neue Nachricht verfügbar --> " << text << endl;
    }
};

int Customer::idGenerator = 100;
int GoldCustomer::idGenerator = 0;

class Store
{
private:
    list<ISubscriber*> subscribers;
    map<string, unsigned int> productAvailability {{"iPhone", 0}, {"Galaxy", 5}};

public:
    void subscribe(ISubscriber* subscriber)
    {
        subscribers.push_back(subscriber);
    }

    void unsubscribe(ISubscriber* subscriber)
    {
        subscribers.remove(subscriber);
    }

    void notifySubscribers(string product, bool isNew)
    {
        string text;

        if (isNew)
        {
            text = "Neue Artikel vom Typ " + product + " verfügbar." ;
        }
        else
        {
            text = "Artikel vom Typ " + product + " nicht mehr verfügbar";
        }

        for (const auto& subscriber : subscribers)
        {
            subscriber->update(text);
        }
    }

    void deliverProducts(string product, unsigned int quantity)
    {
        unsigned int previousStock = productAvailability[product];
        productAvailability[product] += quantity;
        unsigned int newStock = productAvailability[product];

        cout << "Vorrätige Artikel vom Typ " << product << ": " << previousStock << endl;
        cout << "Ausgelieferte Artikel vom Typ " << product << ": " << quantity << endl;
        cout << "Neuer Bestand: " << newStock << endl;

        if (previousStock == 0 && newStock > 0)
        {
            notifySubscribers(product, true);
        }
        else if (previousStock > 0 && newStock == 0)
        {
            notifySubscribers(product, false);
        }
    }

    void sellProducts(string product, unsigned int quantity)
    {
        unsigned int previousStock = productAvailability[product];

        if (previousStock < quantity)
        {
            string exceptionName = "Es sind " + to_string(previousStock) + " Artikel vom Typ " + product + " verfügbar. Es können nicht " + to_string(quantity) + " Artikel verkauft werden.";
            throw OutOfStockException(exceptionName);
        }
        else
        {
            productAvailability[product] -= quantity;
        }

        unsigned int newStock = productAvailability[product];

        cout << "Vorrätige Artikel vom Typ " << product << ": " << previousStock << endl;
        cout << "Verkaufte Artikel vom Typ " << product << ": " << quantity << endl;
        cout << "Neuer Bestand: " << newStock << endl;

        if (previousStock == 0 && newStock > 0)
        {
            notifySubscribers(product, true);
        }
        else if (previousStock > 0 && newStock == 0)
        {
            notifySubscribers(product, false);
        }
    }
};

void manageStore()
{
    try
    {
        Store* store = new Store;
        ISubscriber* customer1 = new Customer();
        store->subscribe(customer1);
        ISubscriber* customer2 = new GoldCustomer();
        store->subscribe(customer2);
        ISubscriber* customer3 = new GoldCustomer();
        store->subscribe(customer3);
        store->deliverProducts("iPhone", 5);
        store->unsubscribe(customer3);
        store->sellProducts("iPhone", 3);
        ISubscriber* customer4 = new Customer();
        store->subscribe(customer4);
        store->deliverProducts("iPhone", 5);
        store->sellProducts("iPhone", 7);
        store->unsubscribe(customer1);
        ISubscriber* customer5 = new GoldCustomer();
        store->subscribe(customer5);
        store->deliverProducts("iPhone", 15);
        store->sellProducts("Galaxy", 8);
    }
    catch (OutOfStockException& e)
    {
        cout << e.what() << endl;
    }
    catch (exception& e)
    {
        cout << e.what() << endl;
    }
    catch (...)
    {
        cout << "Ein unbekannter Fehler ist aufgetreten." << endl;
    }
}

int main()
{
    manageStore();
    return 0;
}
