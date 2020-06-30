#include <iostream>

int main()
{
  int *ptr = new int;

  (*ptr) = 4;

  std::cout << "Address and value is " << ptr << " " << (*ptr) << "\n";
  
  int inter = 0;
  std::cout << "Address and value is " << ptr  << " " << (*ptr) << "\n";
}
