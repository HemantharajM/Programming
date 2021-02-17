//Locking console using mutex
#include<chrono>
#include<mutex>
#include<iostream>
#include<thread>
#include<future>

std::mutex m1;

void funcA() {  
  std::this_thread::sleep_for(std::chrono::milliseconds(10));
//  m1.lock();
  std::cout << "ThreadA\n";
  std::cout <<"ThreadA\n";
 // m1.unlock();
}

void funcB() {
  std::this_thread::sleep_for(std::chrono::milliseconds(10));
 // m1.lock();
  std::cout <<"ThreadB\n";
  std::cout <<"ThreadB\n";
  //m1.unlock();
}

int main()
{
  std::future<void> ftr = std::async(funcA);
  std::future<void> ftr1 = std::async(funcB);

  ftr.get();
  ftr1.get();
}
