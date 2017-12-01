#include <iostream>
#include <vector>
using namespace std;

double findKthSortedArrays(vector<int>& nums1, vector<int>& nums2, int k) {
  int result;
  int m = nums1.size();
  int n = nums2.size();
  int comp_nums1, comp_nums2;
  /* make nums1's length is longer than nums2 to simplify the code */
  if(m < n) {
    return findKthSortedArrays(nums2, nums1, k);
  }
  if(n == 0) { // first we consider the condition when nums2 is empty
    if(k == 0) {
      result = nums1[0];
    } else {
      result = nums1[k-1];
    }
  } else if(k == 1) {
    result = nums1[0] > nums2[0] ? nums2[0] : nums1[0];
  } else if((k-1)/2 >= n) { // why use (k-1)/2 to compare, because we need to consider the start of indice is 0
    comp_nums1 = nums1[k-n-1];
    comp_nums2 = nums2[n-1]; // (k-1)/2 > n, so we need to choose the last element of nums2 to compare
    if(comp_nums1 == comp_nums2) {
      // here there are k-2 elements which are smaller then comp_nums1(comp_nums2), so ...
      result = comp_nums1;
    } else if (comp_nums1 > comp_nums2) {
      // at most k-n-1+n-1=k-2 elements are smaller than comp_nums2, so delete nums2 and find the (k-n)th element
      nums2.clear();
      result = findKthSortedArrays(nums1, nums2, k-n);
    } else {
      // at most k-n-1+n-1=k-2 elements are smaller than comp_nums1, so delete the first k-n elements to find the (k-(k-n)) = nth element
      nums1.erase(nums1.begin(), nums1.begin()+(k-n)) ;
      result = findKthSortedArrays(nums1, nums2, n);
    }
  } else {
    comp_nums1 = nums1[(k-1)/2];
    comp_nums2 = nums2[(k-1)/2];
    if(comp_nums1 == comp_nums2) {
      // here there are k-1 elements which are smaller then comp_nums1(comp_nums2), so ...
      result = comp_nums1;
    } else if (comp_nums1 > comp_nums2) {
      if(k % 2 == 0) {
        nums1.erase(nums1.begin()+((k-1)/2+1),nums1.end());
        nums2.erase(nums2.begin(), nums2.begin()+((k-1)/2+1));
        result = findKthSortedArrays(nums1, nums2, k-(k-1)/2-1);
      } else {
        nums1.erase(nums1.begin()+((k-1)/2),nums1.end());
        nums2.erase(nums2.begin(), nums2.begin()+((k-1)/2));
        result = findKthSortedArrays(nums1, nums2, k-(k-1)/2);
      }
    } else {
      if(k % 2 == 0) {
        nums1.erase(nums1.begin(), nums1.begin()+((k-1)/2+1));
        nums2.erase(nums2.begin()+((k-1)/2+1),nums2.end());
        result = findKthSortedArrays(nums1, nums2, k-(k-1)/2-1);
      } else {
        nums1.erase(nums1.begin(), nums1.begin()+((k-1)/2));
        nums2.erase(nums2.begin()+((k-1)/2),nums2.end());
        result = findKthSortedArrays(nums1, nums2, k-(k-1)/2);
      }
    }
  }
  return result;
}

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
  int m = nums1.size();
  int n = nums2.size();
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

int main(int argc, char ** argv) {
  //test code here
  vector<int> a;
  vector<int> b;
  a.push_back(2);
  b.push_back(1);
  b.push_back(3);
  b.push_back(4);

  double res = findMedianSortedArrays(a, b);
  cout<<res<<endl;
  return 0;
}
