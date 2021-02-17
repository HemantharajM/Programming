#include <iostream>
#include <memory>
#include <string>

int main()
{
  std::string addr = "192.168.0.1";
  
//  const char *arr = addr.c_str();
  std::shared_ptr<const char> ptr(addr.c_str());
}
