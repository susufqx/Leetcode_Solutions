# include <iostream>
# include <vector>
#include <cstdlib>

using namespace std;

class Solution {
public:
  int threeSumClosest(vector<int>& nums, int target) {
    sort(nums.begin(), nums.end());
    int abs_delta = abs(target);
    int delta = target;

    for(int i=0;i<nums.size();i++){
      if(i > 0 && (nums[i] == nums[i-1])) continue;
      int r = i + 1, l = nums.size() - 1;
      int temp = target - nums[i];

      while(r < l){
        int sum = nums[r] + nums[l];
        if(sum == temp) return target;
        if(sum > temp){
          l--;
        }else if(sum < temp){
          r++;
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
