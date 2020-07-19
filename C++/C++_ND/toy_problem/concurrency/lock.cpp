//Usage of lock on console
#include <chrono>
#include <iostream>
#include <mutex>
#include <future>
#include <thread>
std::mutex mtx;

class Vehicle
{
  public:
    Vehicle(int id):_id(id){}

    void drive()
    {
      while(true)
      {
        std::this_thread::sleep_for(std::chrono::milliseconds(150));
        std::unique_lock<std::mutex> lck(_mtx);
        //lck.lock();
        //if(true) {
        //  std::lock_guard<std::mutex> lck(_mtx);
        std::cout <<"Vehicle #" << _id << " is started and thread ID " << std::this_thread::get_id() << std::endl;
        //}
        lck.unlock(); 
        std::this_thread::sleep_for(std::chrono::milliseconds(150));
        lck.lock(); 
        // if(true) {
        //  std::lock_guard<std::mutex> lck(_mtx);
        std::cout <<"Vehicle #" << _id << " is stopped and thread ID " << std::this_thread::get_id() << std::endl;
        // }
        lck.unlock(); 
      }
    }
  private:
    int _id = 0;
    static std::mutex _mtx;
};

std::mutex Vehicle::_mtx;

void funcA(int id)
{
  std::this_thread::sleep_for(std::chrono::milliseconds(50));
  std::unique_lock<std::mutex> lock(mtx);
  std::cout <<"Thread A and id is " << id << " and thread ID "<< std::this_thread::get_id() << std::endl;
}

void funcB(int id)
{
  std::this_thread::sleep_for(std::chrono::milliseconds(50));
  std::unique_lock<std::mutex> lock(mtx);
  std::cout <<"Thread B and id is " << id <<  " and thread ID " << std::this_thread::get_id() << std::endl;
}


int main()
{
  Vehicle v1(1), v2(2);
  std::future<void> ftr1 = std::async(std::launch::async, &Vehicle::drive, &v1);
  std::future<void> ftr2 = std::async(std::launch::async, &Vehicle::drive, &v2);

  ftr1.get();
  ftr2.get();
}
