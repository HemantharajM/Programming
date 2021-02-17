#include <iostream>
#include <memory>


class B
{
	public:
		int value = 5;
		~B()
		{
			std::cout << "Destructor called \n";
			std::cout << "Value is " << value << "\n";
		}
};

		

class C
{
	public:
		std::unique_ptr <B> b_ptr = nullptr;
		
};

class A
{
	public:
		C* c;
		void print()
		{
			std::cout << "Value in class is " << c->b_ptr->value <<"\n";
		}
};

int main()
{
	C c;
	c.b_ptr = std::make_unique<B>();
	
	A a;
	a.c = &c;
	
}
