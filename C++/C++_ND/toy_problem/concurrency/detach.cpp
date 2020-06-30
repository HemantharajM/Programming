//Detach work, avoid aborted
#include <chrono>
#include <iostream>
#include <thread>

void threadEvenfunc() {
  std::this_thread::sleep_for(std::chrono::milliseconds(1));
  std::cout <<"Finished thread Even\n";
}

void threadOddfunc() {
  std::this_thread::sleep_for(std::chrono::milliseconds(1));
  std::cout <<"Finished thread Odd\n";
}

int main()
{
  for(int i = 0; i < 6; ++i) {
    if(i % 2 == 0) {
      std::thread t(threadEvenfunc);
      //false to joinable
      t.detach();
    }else {
      std::thread t(threadOddfunc);
      //false to joinable
      t.detach();
    }
  } 

  //wait for main work
  std::this_thread::sleep_for(std::chrono::milliseconds(1));
  std::cout << "Finished Main\n";

}
    
