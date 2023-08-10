#include<iostream>
using namespace std;
void print_rectangle(int x,int y=0){
    if (y==0)
    {
        y=x;
    }
    
for (int i = 0; i < y; i++)
{
    for (int k = 0; k < x; k++)
    {
        cout << "X ";
    }
    std::cout << std::endl;
    
}
 std::cout << std::endl;

}
int main(){
   std::cout << "x = 2, y = 5: " << std::endl;
	print_rectangle(2, 5);
    std::cout << "x = 3, y = 3: " << std::endl;
	print_rectangle(3, 3);
    std::cout << "x = 4: " << std::endl;
	print_rectangle(4);
  return 0;
}
