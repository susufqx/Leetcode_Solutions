#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
      int len_nums = nums.size();
      vector<vector<int>> res;
      int sum;

      if (len_nums<4) return res; // 如果少于4个数，那么就返回
      sort(nums.begin(), nums.end());
      for (int i = 0; i < len_nums-3; i++) { // i 为有序的第一个数，所以i最大是倒数第四个数的下标
        if (i > 0 && nums[i] == nums[i-1]) continue; // 去重
        for (int j = i+1; j < len_nums-2; j++) { // j为有序的第二个数，所以j最大是倒数第三个数的下标
          if (j > i+1 && nums[j] == nums[j-1]) continue; // 去重
          int l = j+1, r = len_nums-1; // r是最大的那个下标，l就是倒数第二大的那个下标
          while(l < r) { // 保证左边小于右边就对了
            sum = nums[i] + nums[j] + nums[l] + nums[r];
            if (sum == target) {
              res.push_back({nums[i], nums[j], nums[l], nums[r]});
              while(l < r && nums[l] == nums[l+1]) l++;
              while(l < r && nums[r] == nums[r-1]) r--;
              l++;
              r--;
            } else if (sum > target) {
              r--;
            } else if (sum < target) {
              l++;
            }
          }
        }
      }
      return res;
    }
};

int main(int argc, char ** argv) {

  return 0;
}
