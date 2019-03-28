#include <stdio.h>
#include <string.h>

int strStr(char *haystack, char *needle)
{
  if (haystack == NULL || needle == NULL || strlen(haystack) < strlen(needle))
  {
    return -1;
  }

  if (strlen(needle) == 0)
  {
    return 0;
  }

  int l1, l2, i, j;
  l1 = strlen(haystack);
  l2 = strlen(needle);

  for (i = 0; i < l1; i++)
  {
    if (haystack[i] == needle[0])
    {
      if (l1 - i < l2)
      {
        return -1;
      }
      for (j = 0; j < l2; j++)
      {
        if (needle[j] != haystack[i + j])
        {
          break;
        }
        if (j == l2 - 1)
        {
          return i;
        }
      }
    }
  }
  return -1;
}