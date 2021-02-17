#include <iostream>
#include <memory>
#include <vector>

class Edge
{
	public:
		int value = 0;
		
		Edge(int val)
		{
			value = val;
		}
		
		~Edge()
		{
			std::cout << "Destructor value is " << value << "\n";
		}
};


void func(std::unique_ptr<Edge> &temp)
{
	std::unique_ptr<Edge> pt = std::move(temp); 
}


int main()
{
	std::unique_ptr<Edge> edge = std::make_unique<Edge>(4);
	std::unique_ptr<Edge> edge1 = std::make_unique<Edge>(5);
	
	std::vector<std::unique_ptr<Edge>> edges;

	edge->value = 12;	
	edges.push_back(std::move(edge));
	edges.push_back(std::move(edge1));
		
	std::cout <<"Function before call\n";
	func(edges[0]);
	std::cout <<"Function after call\n";	
	if(true) {
		std::cout <<"Inside if\n";	
		Edge* edge2 = (edges[edges.size()-1]).get();
		edge2->value = 10;
//		std::unique_ptr<Edge> edge3 = std::move(edge2);
 	}
	
	std::cout << "Outside if\n";
}
