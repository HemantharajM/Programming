//pass runtime error from thread to main
#include <chrono>
#include <iostream>
#include <future>


double divide_by_num(double num, double dem) {
    
  if(dem == 0)
    throw std::runtime_error("Exception from thread: division by zero!");
  
  return num / dem;
}


int main()
{

  //start a thread 
  double num = 42.0, dem = 0.0;
  //crete future
  std::future<double> ftr = std::async(divide_by_num, num, dem);

  try
  {
    double result = ftr.get();
    std::cout << "Division of " << num << "/ " << dem << " = " << result << std::endl;
  }
  catch(std::runtime_error e)
  {
    std::cout << e.what() << std::endl;
  }

}
