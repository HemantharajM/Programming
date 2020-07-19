//using promise and future to one time pass msg between threads
#include <chrono>
#include <iostream>
#include <future>
#include <string>


void modify_message(std::promise<std::string> &&prms, std::string message) {
  std::this_thread::sleep_for(std::chrono::milliseconds(1000)); 
  std::string modified_message = message + " modified inside thread";
  prms.set_value(modified_message);
}

int main() {
  //define message
  std::string message_to_thread = "My message";

  //create promise and future
  std::promise<std::string> prms;
  std::future<std::string> ftr = prms.get_future();

  //create thread
  std::thread t(modify_message, std::move(prms), message_to_thread);

  std::cout <<"Message from main " << message_to_thread << std::endl;

  //take modified value
  std::string message_from_thread = ftr.get();

  std::cout <<"Message from main about future " << message_from_thread << std::endl;

  //join thread
  t.join();
  return 0;
}
