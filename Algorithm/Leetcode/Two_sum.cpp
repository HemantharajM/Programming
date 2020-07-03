//Given an array of integers, return indices of the two numbers such that they add up to a specific target.
//
//You may assume that each input would have exactly one solution, and you may not use the same element twice.

#include <iostream>
#include <vector>
#include <unordered_map>

int main()
{
  std::vector<int> nums {2,7,11,15};
  int target = 9;

  int sum, diff = 0;
  std::unordered_map<int,int> difference;

  //store all the difference between number zero and all others
  for(int i =1; i < nums.size(); ++i) {
    sum = nums[0] + nums[i];
    diff = target - sum;

    if(!diff) {
      std::cout << "The solution is 0," << i << std::endl;
    }else {
      difference[diff] = i; //store respective number
    }
  }

  //search the difference
  for(int i=1; i < nums.size(); ++i) {
   // auto index = difference.find(nums[i] - nums[0]);
    if(difference.find(nums[i] -nums[0]) != difference.end()) {
      int index = difference[nums[i] - nums[0]];
      
      if(i != index) {
        std::cout << "The solution is " << i << ", " << index << std::endl;
      }
    }
  }

}
