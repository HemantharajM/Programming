//Passing arguments to the thread using variadic Template
#include <chrono>
#include <iostream>
#include <string>
#include <thread>

void PrintId(int id) {
  std::this_thread::sleep_for(std::chrono::milliseconds(50));
  std::cout << "ID = " << id << std::endl;
}

void PrintIdandName(int id ,std::string name) {
  std::this_thread::sleep_for(std::chrono::milliseconds(50));
  std::cout << "ID = " << " and Name = " << name << std::endl;
}

int main()
{
  std::thread t(PrintId, 1);
  std::thread t1(PrintIdandName, 2, "simpson");


  std::this_thread::sleep_for(std::chrono::milliseconds(150));
  std::cout << "Finished Main loop\n";

  t.join();
  t1.join();
}
