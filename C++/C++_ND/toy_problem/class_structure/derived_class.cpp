/*
 * Derived class implementation of initalization
 */

#include <iostream>

class A
{
  public: 

    void print() 
    {
      set();
      std::cout << "Value is " << val << std::endl;
    }
    
    virtual void set()
    {
      val = 100;
    }
    int val;
};

class B : public A
{
  public:
    B(int v)
    {
      val = v;
    }
    void set()
    {
      val = 10;
    }

  private:
    int v;
};

int main()
{
  A a;
  B b(4);

  b.print();
  a.print();
}
