# include <iostream>
# include <vector>

using namespace std;

class Solution {
public:
  vector<vector<int>> threeSum(vector<int>& nums) {
    vector<vector<int>> output;
    int temp, start_num = 100; // start_num 只要大于0即可
    int len_nums = nums.size();
    int i = 0, j = len_nums-1;

    sort(nums.begin(), nums.end());

    if(len_nums < 3 || nums[i] > 0 || nums[j] < 0){
      return output;
    }else{
      for(i=0;i<len_nums;i++){
        if(nums[i] > 0){
          break;
        }
        if(nums[i] == start_num){
          continue;
        }
        int left = i+1, right = len_nums-1;

        while(left < right){
          int sum = nums[left] + nums[right];
          if(sum > (- nums[i])){
            right--;
          }else if(sum < (- nums[i])){
            left++;
          }else{
            output.push_back({nums[i], nums[left], nums[right]});
            left++;
            right--;
          }
        }
        start_num = nums[i];
      }
      sort(output.begin(), output.end());
      output.erase(unique(output.begin(),output.end()), output.end());
      return output;
    }
  }
};

int main(int argc, char ** argv){
  vector<int> v = {-1, 0, 1, 4, 2, -3, -4, 2, 7};
  vector<vector<int>> t = Solution().threeSum(v);
  cout<<"["<<endl;
  for(int i=0;i<t.size();i++){
    cout<<"["<<t[i][0]<<", "<<t[i][1]<<", "<<t[i][2]<<"]";
    if(i == t.size()-1){
      cout<<endl;
    }else{
      cout<<","<<endl;
    }
  }
  cout<<"]"<<endl;
  return 0;
}
