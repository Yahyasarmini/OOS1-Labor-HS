
#include<iostream>
using namespace std;

class Date {
	
	int _day, _month, _year;
public:
	Date(int day=0,int month=0,int year =0):_day(day),_month(month),_year(year){}
	Date operator+(int days);
	friend ostream & operator<<(ostream &, const Date &);
};

    Date Date::operator+(int days){
        Date datum;
        datum._day=_day+days;
        datum._month=_month;
        datum._year=_year;
        while (datum._day > 30) {
        datum._day -= 30;
        datum._month++;
        if (datum._month > 12) {
            datum._month = 1;
            datum._year++;
        }
    }    
        
        return datum;
    }
    ostream & operator<<(ostream & os, const Date & d) {
    os << d._day << "." << d._month << "." << d._year;
    return os;
}

int main(int argc, char *argv[])
{
    Date begin_task = Date(13,04,2023);
    cout << "Die Aufgabe beginnt am " << begin_task << endl;
    Date end_task = begin_task + 7;
    cout << "Die Aufgabe endet am " << end_task << endl;
    Date one_year_and_one_month_later = begin_task + 390;
    cout << "Ein Jahr und ein Monat nach Aufgabenbeginn ist der " << one_year_and_one_month_later << endl;
    Date three_years_and_five_months_later = begin_task + 1230;
    cout << "Drei Jahre und 5 Monate nach Aufgabenbeginn ist der " << three_years_and_five_months_later << endl;
}

