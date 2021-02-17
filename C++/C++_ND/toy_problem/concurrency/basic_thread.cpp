#include <thread>
#include <vector>
#include <algorithm>

int main()
{
  std::vector<std::thread> threads;

  int n_thread = 4;

  //Run thread
  for(int i = 0;  i < n_thread; ++i) {
    threads.emplace_back(std::thread([](){while(true);}));
  }
  
  //wait for threads to finish before leaving
  std::for_each(threads.begin(), threads.end(), [](std::thread &t) {
      t.join();
  });

}
