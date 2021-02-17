#include <iostream>
#include <memory>

class Node
{
	public:
		int value;
		std::unique_ptr<Node> next_node;
		
		//Constructor
		Node(int val)
		{
			value = val;
			next_node = nullptr;
		}	

		~Node()
		{
			std::cout << "Destructor called\n";
			std::cout << "Value is " << value << "\n";
		}
};


void func(std::weak_ptr<Node> node1)
{
	std::shared_ptr<Node> temp = node1.lock();
	std::cout << "In function, value is " << temp << "\n";
	std::cout << "value is : " << temp->value << "\n";
	std::cout << "count is : " << temp.use_count() << "\n";
}

int main()
{
	std::shared_ptr<Node> root = std::make_shared<Node>(5);
	std::weak_ptr<Node> w_root = root;
	std::weak_ptr<Node> another_root = w_root;	
	std::cout << "Value of root is " << root << "\n";	
	//passing to function
	func(root);
	
	if(true) {
		std::cout << "Inside if \n";
		std::shared_ptr<Node> temp = std::make_shared<Node>(8);
		func(temp);
	}	

}
