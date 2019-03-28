#include <stdio.h>

int removeDuplicates(int *nums, int numsSize)
{
  if (numsSize == 0)
  {
    return 0;
  }

  if (numsSize == 1)
  {
    return 1;
  }

  int i, n = 1;
  for (i = 0; i < numsSize - 1; i++)
  {
    if (nums[i] < nums[i + 1])
    {
      nums[n] = nums[i + 1];
      n++;
    }
  }

  return n;
}