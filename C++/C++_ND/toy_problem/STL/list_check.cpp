#include <iostream>
#include <list>


int main()
{
  std::list<int> value;
  value.push_back(5);
  value.push_back(10);
  value.emplace_back(20);

  auto itr = value.end();
  std::advance(itr,value.size()-1);
  (*itr) = 3;


  for(auto itr: value) {
    std::cout <<"value is " << itr << " address " << &itr << std::endl;
  }
}
