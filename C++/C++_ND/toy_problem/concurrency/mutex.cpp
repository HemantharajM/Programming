//Working of mutex and data race problem solved
#include <chrono>
#include <iostream>
#include <memory>
#include <mutex>
#include <thread>
#include <future>
#include <vector>
#include <algorithm>

class Vehicle
{
  public:
    Vehicle(int id): _id(id) {}
  private:
    int _id;
};

class Waiting_Vehicle
{
  public:
   Waiting_Vehicle() {
    // _tmpvehicle = 0;
   }
    
   void print_size()
   {
     _mutex.lock();
     std::cout <<"Number of vehicle is " << _vehicle.size() << std::endl;
     _mutex.unlock();
   }

   void push_back(Vehicle v)
   {
     //int oldnum = _tmpvehicle;
     //std::this_thread::sleep_for(std::chrono::milliseconds(1));
     //_tmpvehicle = oldnum + 1;
     _mutex.lock();
     _vehicle.emplace_back(v);
     _mutex.unlock();
   }

  private:
   //int _tmpvehicle;
   std::vector<Vehicle> _vehicle;
   std::mutex _mutex;
};

int main()
{
  std::shared_ptr<Waiting_Vehicle> wait_vehicle(new Waiting_Vehicle);
  std::vector<std::future<void>> vehicles;
  for(int i = 0; i < 1000; ++i) {
    Vehicle v(i);
    vehicles.emplace_back(std::async(std::launch::async, &Waiting_Vehicle::push_back, wait_vehicle,v));
  }

  std::for_each(vehicles.begin(), vehicles.end(), [](std::future<void> &it) {
    it.wait();
  });

  wait_vehicle->print_size();
}
