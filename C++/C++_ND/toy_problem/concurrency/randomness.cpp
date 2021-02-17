//Randomness occur while thread converts to runnable
#include <chrono>
#include <iostream>
#include <thread>

void threadfunc() {
  std::this_thread::sleep_for(std::chrono::milliseconds(50));
  std::cout <<"Finshed work 1 in thread\n";

  std::this_thread::sleep_for(std::chrono::milliseconds(50));
  std::cout <<"Finsidhed work 2 in thread\n";

}

int main() {
  //Create thread
  std::thread t(threadfunc);

  //Main work
  std::this_thread::sleep_for(std::chrono::milliseconds(50));
  std::cout <<"Finshed work 1 in main\n";

  std::this_thread::sleep_for(std::chrono::milliseconds(50));
  std::cout <<"Finshed work 2 in main\n";

  //wait for thread join
  t.join();
}
