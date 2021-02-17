#include <iostream>
#include <thread>
#include <chrono>

class Vehicle
{
  public:
    Vehicle(): _id(0) {}
    void addID(int id) {_id = id;}
    void PrintId()
    {
      std::cout << "Vehicle id is " << _id << std::endl;
    }

  private:
    int _id;
};


int main()
{
  Vehicle v1, v2;

  std::thread t1(&Vehicle::addID, v1, 1);
  std::thread t2(&Vehicle::addID, &v2, 2);

  t1.join();
  t2.join();

  v1.PrintId();
  v2.PrintId();
}
