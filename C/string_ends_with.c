/*
Name: String ends with?
Kata: 7 kyu
Link: https://www.codewars.com/kata/51f2d1cafc9c0f745c00037d

Description: Complete the solution so that it returns true if the first argument(string)
passed in ends with the 2nd argument (also a string).

Examples:

solution('abc', 'bc') // returns true
solution('abc', 'd') // returns false
*/

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