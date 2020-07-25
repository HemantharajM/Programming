//This exercise to check that how locking works
#include <iostream>
#include <chrono>
#include <memory>
#include <thread>
#include <unordered_map>
#include <mutex>

using node = std::unordered_map<int, std::unique_ptr<int>> ;

std::mutex mtx;
std::mutex mtx1;

class Node 
{
  public:
    std::shared_ptr<node> value;
    Node() {
      value = std::make_shared<node>();
      (*value)[1] = std::make_unique<int>(0);
      (*value)[2] = std::make_unique<int>(0);
    }

    void change(int a,int sec,int val,int who)
    { 
      std::this_thread::sleep_for(std::chrono::milliseconds(sec));
      auto itr = value->at(a).get();

      std::lock_guard<std::mutex> lck(mtx);
      (*itr) = val;

      std::cout <<"Changed by " << who << std::endl;
      print();
    }

    void print()
    {
      std::cout <<"Printing modified value\n";
      for(auto itr = (*value).begin(); itr != (*value).end(); ++itr) {
        std::cout << itr->first << ", " << (*itr->second) << std::endl;
      }
    }
    
  private:
      std::mutex mtx;
};

//std::mutex Node::mtx;

int main()
{
  Node a;
  Node b = a;
  (*a.value->at(1)) = 1;
  (*b.value->at(2)) = 2;
  std::cout <<"Before modification\n";
  a.print();

  for(int i =0; i < 2; ++i) {
    if(i == 0) {
      std::thread t(&Node::change,&a,1,5,3,1);
      t.detach();
    }else { 
      std::thread t(&Node::change,&b,2,1,10,2);
      t.detach();
    }
  }
  

  std::this_thread::sleep_for(std::chrono::milliseconds(2000));

  std::cout << "After modified\n";
  a.print();
}
