/*
 * Check the implementation of virtual function
 */

#include <iostream>

class A 
{
  public:
    virtual void print()
    {
      std::cout << "From A\n";
    }
};

class B : public A
{
  public:
    void print()
    {
      std::cout << "From B\n";
    }
};

int main()
{
  A a;
  B b;

  a.print();
  b.print();

  return 0;
}
