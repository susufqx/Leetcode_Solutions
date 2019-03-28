#include <stdio.h>

int removeElement(int *nums, int numsSize, int val)
{
  if (numsSize == 0)
  {
    return 0;
  }

  if (numsSize == 1)
  {
    if (nums[0] == val)
    {
      return 0;
    }
    else
    {
      return 1;
    }
  }

  int i, n = 0;
  for (i = 0; i < numsSize; i++)
  {
    if (nums[i] != val)
    {
      if (i > n)
      {
        nums[n] = nums[i];
      }
      n++;
    }
  }

  return n;
}