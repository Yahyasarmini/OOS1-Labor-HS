#include <iostream>
using namespace std;

int main() {
    int i;

    cout << "Anzahl eingeben: \n";
    cin >> i;

    int myArray[i];
    double summe = 0;

    for (int n = 0; n < i; n++) {
        cout << "Zahl eingeben: \n";
        cin >> myArray[n];
        summe += myArray[n];
    }

    //cout << "Zahlen im Array: ";
    for (int k = 0; k < i; k++) {
        cout << "Zahl[" << k << "]: " << myArray[k] << " \n";
    }
    //cout << endl;

    cout << "Durchschnitt: " << summe / i << endl;

    return 0;
}
