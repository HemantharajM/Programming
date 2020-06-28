#include <iostream>
#include <memory>

class Node
{
	public:
		std::unique_ptr<int> value;
		
		Node(int val) {
			std::cout << "Constructor called\n";
			value = std::make_unique<int>(val);
		}
		
		Node (Node &source) {
			std::cout <<"copy constructor is called\n";
			value = source.value;
			source.value = nullptr;
		}
		
		Node (Node &&source) {
			std::cout <<"Move constructor is called\n";
			
			value = source.value;
			source.value = nullptr;			
		}
	
		Node& operator=(Node &&source) {
			std::cout <<"Move assignment operator is called\n";

			if(this == &source) {
				return *this;
			}
			value = source.value;
			source.value = nullptr;
		}	

		~Node() {
			std::cout <<"Destructor called\n";
			//delete value;
		}

};


int main()
{
	Node a(5);
	Node b(6);
	
	std::cout << "A value address is " << a.value.get() << " B value address is " << b.value.get() << "\n";	
	if(true){
		Node c = a;
		std::cout << "C value address is " << c.value.get() << "\n";
	}

	std::cout << "A value address is " << a.value.get() << " B value address is " << b.value.get() << "\n";
} 
