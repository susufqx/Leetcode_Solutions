#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    int m = nums1.size();
    int n = nums2.size();
    /*
      when m+n is the even number, after using findKthSortedArrays function, original nums1 and nums2 could change,
      so here we use other variables to store them
    */
    vector<int> nums1Copy(nums1);
    vector<int> nums2Copy(nums2);
    double median;
    if((m+n) % 2 == 0) {
      median = (findKthSortedArrays(nums1, nums2, (m+n)/2) + findKthSortedArrays(nums1Copy, nums2Copy, (m+n)/2+1)) / 2.0;
    } else {
      median = findKthSortedArrays(nums1, nums2, (m+n)/2+1);
    }
    return median;
  }
  /* this function to find the k'th small number */
  double findKthSortedArrays(vector<int>& nums1, vector<int>& nums2, int k) {
    int result;
    int m = nums1.size();
    int n = nums2.size();
    int comp_nums1, comp_nums2;
    int k_nums1, k_nums2;
    /* make nums1's length is longer than nums2 to simplify the code */
    if(m < n) {
      return findKthSortedArrays(nums2, nums1, k);
    }
    if(n == 0) { // first we consider the condition when nums2 is empty
      result = nums1[k-1];
    } else if(k == 1) {
      result = nums1[0] > nums2[0] ? nums2[0] : nums1[0];
    } else {
      k_nums2 = min(k/2, n);
      k_nums1 = k - k_nums2;
      comp_nums1 = nums1[k_nums1-1];
      comp_nums2 = nums2[k_nums2-1];

      if(comp_nums1 == comp_nums2) {
        result = comp_nums1;
      } else if(comp_nums1 > comp_nums2) {
        nums2.erase(nums2.begin(), nums2.begin()+k_nums2);
        result = findKthSortedArrays(nums1, nums2, k_nums1);
      } else {
        nums1.erase(nums1.begin(), nums1.begin()+k_nums1);
        result = findKthSortedArrays(nums1, nums2, k_nums2);
      }
    }
    return result;
  }
};

int main(int argc, char ** argv) {
  //test code here
  vector<int> a;
  vector<int> b;
  a.push_back(1);
  a.push_back(4);
  a.push_back(6);
  a.push_back(8);
  b.push_back(2);
  b.push_back(3);
  b.push_back(4);
  b.push_back(5);
  Solution solu;

  double res = solu.findMedianSortedArrays(a, b);
  cout<<res<<endl;
  return 0;
}
