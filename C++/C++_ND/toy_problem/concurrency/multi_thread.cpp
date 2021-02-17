#include <iostream>
#include <thread>
#include <vector>

//int arr[] = {1,2,3,4,5,6,7,8,9,10,11,12};

void search(int start,int end, int value, std::vector<int> *arr)
{
  //std::cout << "start " << start << " end " << end << " value " << value << std::endl;
  for(int i= start; i < end; ++i) {
    if((*arr)[i] == value) {
      std::cout <<"Found " << " thread id = " << std::this_thread::get_id() << " i = " << i << std::endl;
    }
  }
}


int main()
{

  //Initialize array
  std::vector<int> v(1000,10);
  for(int i = 0; i < v.size(); ++i) {
    v[i] = i;
  }
  std::cout << "vector size is " << v.size() << "\n";
  std::vector<std::thread> threads;

  auto start_time = std::chrono::system_clock::now();
  for(int i =0; i < 8; ++i) {
    threads.emplace_back(std::thread(search,i*0, (i+1) * 125, 999, &v));
    //std::this_thread::sleep_for(std::chrono::milliseconds(100));
  }

  for(auto &t: threads)
    t.join();
  
  auto end_time = std::chrono::system_clock::now();
  std::cout << "Total time difference is " << std::chrono::duration_cast<std::chrono::microseconds>(end_time - start_time).count() << " in microsec \n";
}
