#include <chrono>
#include <iostream>
#include <memory>
#include <mutex>
#include <thread>
#include <unordered_map>
#include <vector>


struct data_node {
    data_node(int val) {
        data = val;
    }
    int data;
    std::mutex data_lock;
};

using node = std::unordered_map<int, std::unique_ptr<data_node>> ;

class Node 
{
  public:
    std::shared_ptr<node> value;
    Node() {
      value = std::make_shared<node>();
      (*value)[1] = std::make_unique<data_node>(0);
      (*value)[2] = std::make_unique<data_node>(0);
    }

    void change(int a,int sec,int val,int who)
    { 
      std::this_thread::sleep_for(std::chrono::milliseconds(sec));
      auto itr = value->at(a).get();
      std::lock_guard<std::mutex> lck(itr->data_lock);
      std::cout << "Thread execution is " << who << " started to change\n";
      std::this_thread::sleep_for(std::chrono::milliseconds(1000));
      itr->data = val;
      print();
      std::cout <<"Thread execution is " << who << " finished to change\n";
    }

    void print()
    {
      std::cout <<"Printing modified value\n";
      for(auto itr = (*value).begin(); itr != (*value).end(); ++itr) {
        std::cout << itr->first << ", " << itr->second->data << std::endl;
      }
    }
    
};

int main()
{
    Node a;
    Node b = a;
  //  (*a.value[1]->at(2)->data) = 1;
  //  (*b.value->at(2)->data) = 2;
    std::cout <<"Before modification\n";
    a.print();

    for(int i =0; i < 2; ++i) {
        if(i == 0) {
            std::thread t(&Node::change,&a,2,5,3,1);
            t.detach();
        }else { 
            std::thread t(&Node::change,&b,1,1,10,2);
            t.detach();
        }
    }
  

    std::this_thread::sleep_for(std::chrono::milliseconds(5000));

    std::cout << "After modified\n";
    a.print();
}