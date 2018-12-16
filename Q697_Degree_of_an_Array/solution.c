#include <stdio.h>

int findShortestSubArray(int* nums, int numsSize) {
  int array1[50000] = {0};
  int array2[50000] = {0};
  int array3[50000] = {0};
  int i;
  int temp=0;
  int res = numsSize;

  if (numsSize < 2) {
    return numsSize;
  }
  for (i = 0; i < numsSize; i++) {
    if (array1[nums[i]] == 0) {
      array2[nums[i]] = i;
    }
    array1[nums[i]] += 1;
    if (array1[nums[i]] > temp) {
      temp = array1[nums[i]];
    }
    array3[nums[i]] = i;
  }
  for (i = 0; i < 5000; i++) {
    if (array1[i] == temp) {
      if (res > array3[i] - array2[i] + 1) {
        res = array3[i] - array2[i] + 1;
      }
    }
  }
  return res;
}

int main(int argc, char ** argv) {
  int a[7] = {1,2,2,3,1,4,2};
  int b = findShortestSubArray(a, 7);
  printf("%d\n", b);
  return 0;
}
