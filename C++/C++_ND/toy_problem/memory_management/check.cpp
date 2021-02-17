#include <iostream>
#include <memory>

int main()
{
	std::unique_ptr<int> ptr = std::make_unique<int>();
	*ptr = 3;
	
	std::unique_ptr<int> anotherptr = std::move(ptr);

	if(ptr != NULL) {
		std::cout << "Pointer is there\n";
		std::cout << "value is ptr " << (*ptr) << std::endl;
	} else {
		std::cout << "Value in anotherptr " << (*anotherptr) << std::endl; 
	}
		
	ptr = NULL;
	
	if(ptr != NULL) {
		std::cout << "Pointer is alive\n";
	//	delete ptr;
	}

	if(ptr != NULL) {
	}

	return 0;
}
