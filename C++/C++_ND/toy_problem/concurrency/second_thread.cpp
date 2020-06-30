//Run multiple thread
#include <chrono>
#include <iostream>
#include <thread>

void threadFunction()
{
  std::this_thread::sleep_for(std::chrono::milliseconds(100));
  std::cout << "Finished work in thread\n";
}

int main()
{
  //Create thread object with function 
  std::thread t(threadFunction);

  std::this_thread::sleep_for(std::chrono::milliseconds(50));
  std::cout << "Finsihed work in main\n";

  //wait for thread to join
  t.join();
}
