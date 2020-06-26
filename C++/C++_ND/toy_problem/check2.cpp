#include <iostream>
#include <memory>

class Node
{
	public:	
		int value;
		std::shared_ptr<Node> next_node;
		std::weak_ptr<Node> prev_node;
		
		Node(int val)
		{
			std::cout << "Constructor called\n";
			value = val;
			next_node = nullptr;
			//prev_node = nullptr;
		}
		
		~Node ()
		{
			std::cout << "Destructor called\n";
			std::cout << "Value is " << value << "\n";	
		//	delete next_node;	
		}	
};


int main()
{
	std::shared_ptr<Node> root = std::make_shared<Node>(3);
	root->next_node = std::make_shared<Node>(2);
	root->prev_node = root;

	root->next_node->next_node = std::make_shared<Node>(1);
	root->next_node->prev_node = root->next_node;
		
	if(true){
		std::cout << "Inside the if\n";
		std::shared_ptr<Node> another_ptr = root;	
	}
	

	std::cout << "Outside the if\n";
}	
