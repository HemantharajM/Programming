//Running single thread output thread id
#include <iostream>
#include <thread>

int main()
{
  std::cout << "Hello concurrent world! from main thread id = " << std::this_thread::get_id() << std::endl;

  return 0;
}
