#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int exsistInArray(char *w, char **words, int n)
{
  int i;
  for (i = 0; i < n; i++)
  {
    if (strcmp(w, words[i]) == 0)
    {
      words[i] = "";
      return 1;
    }
  }
  return 0;
}

char **cpWords(char **words, int wordsSize)
{
  char **cpwords = (char **)malloc(sizeof(char *) * wordsSize);
  int i;

  for (i = 0; i < wordsSize; i++)
  {
    cpwords[i] = words[i];
  }

  return cpwords;
}

int *findSubstring(char *s, char **words, int wordsSize, int *returnSize)
{
  if (strcmp(s, "") == 0)
  {
    return NULL;
  }

  if (wordsSize == 0)
  {
    return NULL;
  }

  int lenw = strlen(words[0]);
  int lens = strlen(s);
  int lentotal = lenw * wordsSize;

  if (lentotal > lens)
  {
    return NULL;
  }

  int lenres = lens - lentotal + 1;
  int *res = (int *)malloc(sizeof(int) * lenres);
  int i = 0, j = 0;
  int ok = 1;
  int n = 1;
  int nsize = 0;
  char *w = (char *)malloc(sizeof(char) * (lenw + 1));
  w[lenw] = '\0';
  char **cpwords = cpWords(words, wordsSize);

  for (i = 0; i < lenres; i++)
  {
    j = n * lenw - 1;
    n++;
    strncpy(w, &s[j - lenw + 1 + i], lenw);
    int e = exsistInArray(w, cpwords, wordsSize);

    if (e == 0)
    {
      ok = 0;
    }

    if (j == lentotal - 1)
    {
      if (ok == 1)
      {
        res[nsize++] = i;
      }
      cpwords = cpWords(words, wordsSize);
      ok = 1;
      j = 0;
      n = 1;
    }
    else if (ok == 0)
    {
      cpwords = cpWords(words, wordsSize);
      ok = 1;
      j = 0;
      n = 1;
    }
    else
    {
      i--;
    }
  }
  *returnSize = nsize;
  return res;
}