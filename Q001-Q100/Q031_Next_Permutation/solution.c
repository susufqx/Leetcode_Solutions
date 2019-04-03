#include <stdio.h>

void nextPermutation(int *nums, int numsSize)
{
  if (numsSize == 1)
  {
    return;
  }
  int temp, i, j, r;
  int ok = 0;

  if (numsSize == 2)
  {
    temp = nums[0];
    nums[0] = nums[1];
    nums[1] = temp;
    return;
  }

  if (nums[numsSize - 1] > nums[numsSize - 2])
  {
    temp = nums[numsSize - 1];
    nums[numsSize - 1] = nums[numsSize - 2];
    nums[numsSize - 2] = temp;
    return;
  }

  for (i = numsSize - 1; i >= 2; i--)
  {
    if (nums[i - 1] >= nums[i] && nums[i - 1] >= nums[i - 2])
    {
      int p = i - 2;
      for (j = numsSize - 1; j > p; j--)
      {
        if (nums[j] > nums[p])
        {
          printf("%d==%d\n", j, p);
          temp = nums[p];
          nums[p] = nums[j];
          nums[j] = temp;
          ok = 1;
          break;
        }
      }
      if (ok == 1)
      {
        r = i - 1;
        break;
      }
    }
    else
    {
      r = 0;
    }
  }

  for (i = r; i < numsSize; i++)
  {
    for (j = i + 1; j < numsSize; j++)
    {
      if (nums[j] < nums[i])
      {
        temp = nums[j];
        nums[j] = nums[i];
        nums[i] = temp;
      }
    }
  }
}