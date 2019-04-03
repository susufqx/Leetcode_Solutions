#include <stdio.h>

int divide(int dividend, int divisor)
{
  int max = 2147483647;
  int sign = (dividend < 0) ^ (divisor < 0) ? -1 : 1;
  long res = 0;
  long dd = (long)dividend, ds = (long)divisor;
  long t;

  if (dd < 0)
  {
    dd = -dd;
  }

  if (ds < 0)
  {
    ds = -ds;
  }

  while (dd >= ds)
  {
    long i = 1;
    t = ds;
    while ((t << 1) < dd)
    {
      t <<= 1;
      i <<= 1;
    }
    dd -= t;
    res += i;
  }

  if (sign < 0)
  {
    return -res;
  }
  return res > max ? max : res;
}