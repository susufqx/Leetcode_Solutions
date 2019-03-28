#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    int i = 0, j = 0, k = 0;
    vector<int>tempVector(nums1); // create a new vector to store the data of nums1

    while(i < m && j < n) {
      if (tempVector[i] < nums2[j]) {
        nums1[k] = tempVector[i];
        i++;
      } else {
        nums1[k] = nums2[j];
        j++;
      }
      k++;
    }
    if (i == m) {
      while(j < n) {
        nums1[k] = nums2[j];
        j++;
        k++;
      }
    } else if (j == n) {
      while(i < m) {
        nums1[k] = tempVector[i];
        i++;
        k++;
      }
    }
  }
};

int main(int argc, char ** argv) {
  vector<int> v1;
  vector<int> v2;
  v1.push_back(1);
  v1.push_back(2);
  v1.push_back(3);
  v1.push_back(0);
  v1.push_back(0);
  v1.push_back(0);
  v2.push_back(2);
  v2.push_back(5);
  v2.push_back(6);
  Solution solu;
  solu.merge(v1, 3, v2, 3);
  for (int i = 0; i < v1.size(); i++) {
    cout<<v1[i]<<" ";
  }
  cout<<endl;
  return 0;
}
