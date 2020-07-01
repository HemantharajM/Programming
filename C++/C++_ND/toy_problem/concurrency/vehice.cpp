#include <iostream>
#include <thread>

class Vehicle
{
  public:
    Vehicle(int id) : _id(id) {}
    //callable operator 
    void operator()() {
      std::cout << "Vehicle class "<< _id  << " is created\n";
    }

  private:
    int _id;
};

int main()
{
  //create thread
  //std::thread t1((Vehicle(1))); //extra paranthessis

  std::thread t1 = std::thread(Vehicle(2)); //copy initialization

  //std::thread t3{ Vehicle() }; //uniform initialization with braces

  //
  std::cout << "Finished of work in main\n";

  t1.join();
 // t2.join();
  //t3.join();

  return 0;
}
