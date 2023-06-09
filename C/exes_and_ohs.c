/*
Name: Exes and Ohs
Kata: 7 kyu
Link: https://www.codewars.com/kata/55908aad6620c066bc00002a

Description: Check to see if a string has the same amount of 'x's and 'o's.
The method must return a boolean and be case insensitive. The string can contain any char.

Examples input/output:

XO("ooxx") => true
XO("xooxx") => false
XO("ooxXm") => true
XO("zpzpzpp") => true // when no 'x' and 'o' is present should return true
XO("zzoo") => false
*/

#include <stdbool.h>

bool xo (const char* str)
{
  int xcount = 0;
  int ocount = 0;
  
  for (int i = 0; str[i]; i++)
  {
    if (str[i] == 'x' || str[i] == 'X')
      xcount++;
    if (str[i] == 'o' || str[i] == 'O')
      ocount++;
  }
  if (xcount == ocount || (xcount == 0 && ocount == 0))
    return true;
  else
    return false;
}
