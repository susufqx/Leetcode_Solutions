/*
  Here we need to add -std=c++11 to complier the code
  Because we use vector initial list
 */
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
      int num = height.size();
      int area = 0;
      int short_height;
      int temp_area;

      for (int i = 0; i < num; i++) {
        for (int j = i+1; j < num; j++) {
          short_height = min(height[i], height[j]);
          temp_area = short_height * (j-i);
          area = max(area, temp_area);
        }
      }
      return area;
    }
};
/*  */
int main(int argc, char ** argv) {
  Solution solution = Solution();
  vector<int> height = {1, 8, 6, 2, 5, 4, 8, 3, 7};
  int maxArea = solution.maxArea(height);
  cout<<"Max area is : "<<maxArea<<endl;
  return 0;
}
