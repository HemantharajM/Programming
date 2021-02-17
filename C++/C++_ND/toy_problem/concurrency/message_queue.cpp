//Implementing message queue 
#include <chrono>
#include <iostream>
#include <thread>
#include <future>
#include <mutex>
#include <deque>
#include <memory>
#include <algorithm>

template <class T>
class MessageQueue 
{
  public:
      T receive()
      {
        //perform queue modification under the lock
        std::unique_lock<std::mutex> ulock(_mtx);
        _cond.wait(ulock,[this] { return !_message.empty();}); //pass unique lock to condition variable

        //remove last element from message
        T msg = std::move(_message.back());
        _message.pop_back();
        
        return msg; //will not copied
      }

      void send(T &&msg)
      {
        //simulate work
        std::this_thread::sleep_for(std::chrono::milliseconds(10));
        
        //perform lock
        std::unique_lock<std::mutex> ulock(_mtx);
        _message.emplace_back(msg);

        _cond.notify_one(); //notify client after pushing new vehicle into vector

      }
  private:
    std::mutex _mtx;
    std::condition_variable _cond;
    std::deque<T> _message;
};


int main()
{
  std::shared_ptr<MessageQueue<int>> queue(new MessageQueue<int>);

  std::cout << "Spawing threads\n";
  std::vector<std::future<void>> futures;

  for(int i = 0; i < 10; ++i) 
  {
    int message = i;
    futures.emplace_back(std::async(std::launch::async, &MessageQueue<int>::send, queue, std::move(message)));
  }

  std::cout <<"Collecting message\n";
  while(true) {
    int message = queue->receive();
    std::cout << "Message is " << message << std::endl;
  }

  std::for_each(futures.begin(), futures.end(), [](std::future<void> &ftr) { ftr.wait();});

  std::cout << "Finished\n";

  return 0;
}
