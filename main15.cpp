#include <array>
#include <iostream>
using namespace std;

const unsigned int length = 10;

// hier die Funktion 'sort' implementieren
template<typename T>
array<T,length> sort(array<T,length> arr){
    T temp;
    for (unsigned  int i = 0; i < length-1; i++)
    {
        for (unsigned  int j = 0; j < length-i-1; j++)
        {
            if (arr[j]> arr[j+1])
            {
                temp = arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }  
    }
    return arr;
}

int main(int argc, char *argv[]) 
{
    array<int,length> int_container = {10, 2, 7, 5, 8, 3, 4, 1, 9, 6};
    array<int, length> sorted_int_container = sort(int_container);

    for (size_t i = 0; i < sorted_int_container.size(); i++) {
        cout << i << ": " << sorted_int_container[i] << endl;
    }

    array<char,length> char_container = {'j', 'm', 'e', 't', 'k', 'o', 'p', 's', 'a', 'f'};
    array<char, length> sorted_char_container = sort(char_container);

    for (size_t i = 0; i < sorted_char_container.size(); i++) {
        cout << i << ": " << sorted_char_container[i] << endl;
    }
}
