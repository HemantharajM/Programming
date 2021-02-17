#include <iostream>
#include <memory>
#include <vector>
#include <algorithm>

class Node
{
	public:
		int value;

		Node(int val)
		{
			value = val;
		}

		~Node()
		{
			std::cout << "Destructor called for value is " << value << "\n";
		}
};

int main()
{
	std::vector<std::shared_ptr<Node>> ptr;
	
	for(int i = 0; i < 5; ++i) {
		
		auto newnode = std::find_if(ptr.begin(), ptr.end(), [i](const std::shared_ptr<Node>& node) { return node->value == i;});
	
		if(newnode  == ptr.end()) {
			ptr.emplace_back(std::make_shared<Node>(i));
				
		}
	}	
	
	std::vector<std::shared_ptr<Node>>::iterator it = std::find_if(ptr.begin(), ptr.end(), [](const std::shared_ptr<Node>& node) { return node->value == 3;});
		
	Node * raw_ptr = (*it).get();	
	std::cout << "Output is " << raw_ptr->value << "\n";	
}
