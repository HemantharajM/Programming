#include <iostream>

int main()
{
  int *ptr =(int *) 0x613c20;

  *ptr = 5;

  std::cout << "Address and value is " << ptr << " " << (*ptr) << "\n";
}
