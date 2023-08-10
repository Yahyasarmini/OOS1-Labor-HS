#include <iostream>
#include <string>
using namespace std;
// Klasse Customer definieren
class Customer{
    static int _s_count;
    static int _s_id_generator;
    string _name;
    string _location;
    int _age;
    double _business_done;
    int _transaction_count;
    int _id;
    public: 
    Customer(string name, int age,string location){
        _name=name;
        _age=age;
        _location=location;
        _s_count++;
        //_s_id_generator++;
        _id = ++_s_id_generator;
    }
    ~Customer(){
        _s_count--;
        //_s_id_generator--;
    }
    //Setter
    void set_s_count(int s_count){
        _s_count=s_count;
    }
    void set_s_id_generator(int s_id_generator){
        _s_id_generator=s_id_generator;
    }
    void set_business_done(double Umsatz){
    _business_done=Umsatz;
    }
    void set_Name(string Name){
        _name=Name;
    }
    void set_location(string location){
        _location=location;
    }
    void set_age(int age){
        _age=age;
    }
    void set_transaction_count(int count){
        _transaction_count=count;
    }
    void set_ID(int id){
        _id=id;
    }
    //Getter
    int get_ID(){
        return _id;
    }
    int get_tranasaction_count(){
        return _transaction_count;
    }
    int get_age(){
        return _age;
    }
    string get_location(){
        return _location;
    }
    string get_Name(){
        return _name;
    }
    int get_s_id_generator(){
        return _s_id_generator;
    }
    double get_business_done(){
        return _business_done;
    }

    void do_business(double amount){
        _business_done+= amount;
        _transaction_count++;
    }
    static int get_s_count() {
    return _s_count;
    }
    /*
    Kunde Simon aus Heilbronn (ID = 2, 23 Jahre) hatte 3 Transaktion(en) und 633.99 Euro Umsatz
    Kunde Michael aus Karlsruhe (ID = 3, 21 Jahre) hatte 1 Transaktion(en) und 199 Euro Umsatz
    Kunde Claudia aus Nagold (ID = 4, 30 Jahre) hatte 1 Transaktion(en) und 1000 Euro Umsatz
    */
    void print(){
        std::cout << "Kunde " << _name << " aus " << _location << " (ID = " << _id << ", " << _age << " Jahre) hatte " << Customer::get_tranasaction_count() << " Transaktion(en) und " << _business_done << " Euro Umsatz" << std::endl;
    }

};
int Customer::_s_id_generator=0;
int Customer::_s_count=0;

int main(int argc, char *argv[]) {
    Customer peter = Customer("Peter", 17, "Stuttgart");
	Customer simon = Customer("Simon", 23, "Heilbronn");
    peter.~Customer();
	Customer micheal = Customer("Michael", 21, "Karlsruhe");
	Customer claudia = Customer("Claudia", 30, "Nagold");
    std::cout << "Anzahl Kunden: " << Customer::get_s_count() << std::endl;
	simon.do_business(230);
	simon.do_business(400);
	claudia.do_business(1000);
	micheal.do_business(199);
	simon.do_business(3.99);
	simon.print();
	micheal.print();
	claudia.print();
    claudia.~Customer();
    std::cout << "Anzahl Kunden: " << Customer::get_s_count() << std::endl;
	return 0;
}


