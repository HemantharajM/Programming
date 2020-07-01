#include <iostream>

int main()
{
  int id = 0;

  ++id;
  auto f1 = [id]() { std::cout << "value of id is " << id << "\n";};
  auto f2 = [&id]() {std::cout << "value of id is " << id << "\n";};
  auto f3 = [id]() mutable { std::cout << "value of id is " << ++id << "\n";};

  f1();
  f2();
  f3();
}
