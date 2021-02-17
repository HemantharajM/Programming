//pass runtime error from thread to main
#include <chrono>
#include <iostream>
#include <future>
#include <cmath>
#include <memory>


void divide_by_num(std::promise<double> &&prms, double num, double dem) {
  std::this_thread::sleep_for(std::chrono::milliseconds(100));

  try
  {
    if(dem == 0){
      throw std::runtime_error("Exception from thread: division by zero!");
    }else {
      prms.set_value(num / dem);
    }
  } 
  catch(...)
  {
    prms.set_exception(std::current_exception());
  }
}


int main()
{
  //create promise and future
  std::promise<double> prms;
  std::future<double> ftr = prms.get_future();

  //start a thread 
  double num = 42.0, dem = 0.0;

  std::thread t(divide_by_num, std::move(prms), num, dem);

  try
  {
    double result = ftr.get();
    std::cout << "Division of " << num << "/ " << dem << " = " << result << std::endl;
  }
  catch(std::runtime_error e)
  {
    std::cout << e.what() << std::endl;
  }

  t.join();
}
