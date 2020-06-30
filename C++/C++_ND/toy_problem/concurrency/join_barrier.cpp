//Use join as barrier to control flow of execution
#include <chrono>
#include <iostream>
#include <thread>

void threadfunc() {
  std::this_thread::sleep_for(std::chrono::milliseconds(50));
  std::cout <<"Finished work 1 in thread\n";

  std::this_thread::sleep_for(std::chrono::milliseconds(50));
  std::cout <<"Finished work 2 in thread\n";

}

int main() {
  //Create thread
  std::thread t(threadfunc);

  //wait for thread join
  t.join();

  //Main work
  std::this_thread::sleep_for(std::chrono::milliseconds(50));
  std::cout <<"Finished work 1 in main\n";

  std::this_thread::sleep_for(std::chrono::milliseconds(50));
  std::cout <<"Finished work 2 in main\n";

}
