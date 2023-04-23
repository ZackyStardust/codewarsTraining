#include <stdbool.h>
#include <unistd.h>
#include <stdio.h>

bool solution(const char *string, const char *ending)
{
  int i = 0;
  int j = 0;
  
  if (!*ending)
    return true;
  while (string[i])
    i++;
  while (ending[j])
    j++;
  i--;
  j--;
  while (j >= 0 || i >= 0)
  {
    if (string[i] == ending[j])
    {
      j--;
      i--;
      if (j == -1)
        return true;
      if (i == -1)
        return false;
    }
    else
      return false;
  }
  if (j == 0)
    return true;
  else
    return false;
}