#include <iostream>
#include <memory>


class Node
{
	public:
		int value = 5;
		
		~Node()
		{
			std::cout << "Destructor called\n";
		}
};

int main()
{
	std::unique_ptr<Node> uptr = std::make_unique<Node>();

	if(true) {
		std::cout << "Inside if\n";
		Node * int_ptr = uptr.get();
		std::cout << "Unique_ptr address is " << uptr.get() << "\n";
		std::cout << "Raw pointer address is " << int_ptr << "\n"; 	
	}
		
	std::cout << "Outside if\n";	
}
