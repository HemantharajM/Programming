#include <iostream>
#include <thread>
#include <chrono>

class Vehicle
{
  public:
    Vehicle(): _id(0) {}
    void addID(int id) {
      std::cout << "Start a thread id is " << _id << "\n";
      _id = id;
    }
    
    void create_thread(int id)
    {
      t1 = std::thread(&Vehicle::addID,this,id);
    }
    
    void PrintId()
    {
      std::cout << "Vehicle id is " << _id << std::endl;
    }

   ~Vehicle()
   {
      t1.join(); 
   }

  private:
    int _id;
    std::thread t1;
};


int main()
{
  Vehicle v1, v2;
 
  v1.create_thread(1);
  v2.create_thread(2);

  std::this_thread::sleep_for(std::chrono::milliseconds(100));
  v1.PrintId();
  v2.PrintId();
}

