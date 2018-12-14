# include <iostream>
# include <vector>
# include <cstdlib>

using namespace std;

class Solution {
public:
  int threeSumClosest(vector<int>& nums, int target) {
    sort(nums.begin(), nums.end());
    int delta = nums[0] + nums[1] + nums[3] - target;
    int abs_delta = abs(delta);

    for(int i=0;i<nums.size();i++){
      if(i > 0 && (nums[i] == nums[i-1])) continue;
      int left = i + 1, right = nums.size() - 1;
      int temp = target - nums[i];

      while(left < right){ // 核心就是让 sum 和 temp 不断靠近，让 delta 的绝对值尽可能小
        int sum = nums[left] + nums[right];
        if(sum == temp) return target;
        if(sum > temp){
          right--;
        }else if(sum < temp){
          left++;
        }
        if(abs(sum - temp) < abs_delta){
          delta = sum - temp;
          abs_delta = abs(delta);
        }
      }
    }
    return target + delta;
  }
};

int main(int argc, char ** argv){
  vector<int> v = {0, 0, 0};
  cout<<"The closest sum is : "<<Solution().threeSumClosest(v, 1)<<endl;
  return 0;
}
