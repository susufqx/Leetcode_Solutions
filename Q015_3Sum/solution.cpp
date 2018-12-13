# include <iostream>
# include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
      int len_nums = nums.size();
      vector<vector<int>> output;
      vector<vector<int>> getTwoSum;
      int start;

      if(len_nums < 3){
        return output;
      }else{
        for(int i=0;i<len_nums;i++){
          start = nums[0]; // 我们把每一步需要考虑的元素都安排在第一个
          nums.erase(nums.begin()); // 删除掉第一个元素
          getTwoSum = this->twoSum(nums, -start);
          nums.push_back(start); // 再把之前删除的第一个元素放在最后，这样下一次的第一个元素就是当前的第二个元素，以此类推
          for(int i=0;i<getTwoSum.size();i++){
            getTwoSum[i].push_back(start);
            sort(getTwoSum[i].begin(), getTwoSum[i].end());
            output.push_back(getTwoSum[i]);
          }
        }
        sort(output.begin(), output.end());
        output.erase(unique(output.begin(),output.end()), output.end());
        return output;
      }
    }

private:
  vector<vector<int>> twoSum(vector<int> nums, int target) {
    vector<vector<int>> res;
    vector<int> temp(2);
    int numsSize = nums.size();
    for (int i=0;i<numsSize;i++) {
        for(int j=i+1;j<numsSize;j++) {
            if(nums[i] + nums[j] == target) {
              temp[0] = nums[i];
              temp[1] = nums[j];
              res.push_back(temp);
            }
        }
    }
    return res;
  }
};

int main(int argc, char ** argv){
  vector<int> v = {-1, 0, 1, 2, -1, -4};
  vector<vector<int>> t = Solution().threeSum(v);
  return 0;
}
