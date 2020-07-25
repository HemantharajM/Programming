#include <chrono>
#include <iostream>
#include <memory>
#include <mutex>
#include <thread>
#include <unordered_map>
#include <vector>

template <class T>
class lock_data
{
  public:
    //Default constructor
    lock_data(T val) {
      std::lock_guard<std::mutex> lcx(mtx);
      data = val;
    }
    //read = not a thread safe
    T read() {
      return data;
    }

    //safe read - lock the data before read
    virtual T sread() {
      std::lock_guard<std::mutex> lcx(mtx);
      return data;
    }
    
    //safe write - lock the data before write[thread-safe]
    virtual void swrite(T val) {
      std::lock_guard<std::mutex> lck(mtx);
      data = val;
    }

    //safe write - try to for certain milliseconds lock the data before write(thread-safe)
    bool swrite(T val, int ms) {
      std::unique_lock<std::mutex> lck(mtx, std::defer_lock);

      //Try to lock object for certain millisecond
      if(!lck.try_lock_for(std::chrono::milliseconds(ms))) {
        data = val;
        return true;  
      } else {
        return false;
      }
    }

    //safe read and write
   // virtual void sread_write(T val)  = 0;

    //data type
    T data;
    //lock thread-safe read and write
    std::mutex mtx;
};



class int_data : public lock_data<int>
{
  public:
    void sread_write_reserve(int id) {
      //hold the data before read and write
      std::lock_guard<std::mutex> lck(mtx);
      //unreserved then reserve
      if(data == 0) {
          data = id;
      }  
    }

    void sread_write_unreserve(int id) {
        //hold the data before read and write
        std::lock_guard<std::mutex> lck(mtx);
        //reserved with id, unreserve
        if(data == id) {
          data = 0;
        }
    }

    bool sread_write_reserve(int id, int ms) {
      //try to hold the data for certain time limit millisecond
      std::unique_lock<std::mutex> lck(mtx,std::defer_lock);

      if(!lck.try_lock_for(std::chrono::milliseconds(ms))) {
          //after locked

          if(data == id) {
            data = 0;
          }

          return true;
      }else {
          return false;
      }
    }
};

class  reservation_table
{
  public:
    //constructor
    reservation_table() {
      int_data a(0);

      (*reservation).emplace_back(int_data(0));
    }
    ~ reservation_table();

    std::shared_ptr<std::vector<int_data>> reservation; 
};

