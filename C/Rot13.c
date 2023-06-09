/*
Name: Rot13
Kata: 5 kyu
Link: https://www.codewars.com/kata/530e15517bc88ac656000716

Description: ROT13 is a simple letter substitution cipher that replaces a letter with the letter 13 letters
after it in the alphabet. ROT13 is an example of the Caesar cipher.

Create a function that takes a string and returns the string ciphered with Rot13. If there are numbers or
special characters included in the string, they should be returned as they are. Only letters from
the latin/english alphabet should be shifted, like in the original Rot13 "implementation".
*/

#include <string.h>
#include <stddef.h>

char *rot13(const char *src)
{
  char *ret = strdup(src);
  
  for (int i = 0; ret[i]; i++)
  {
    if (ret[i] >= 'a' && ret[i] <= 'z')
    {
      if (ret[i] >= 'n')
        ret[i] -= 13;
      else
        ret[i] += 13;
    }
    if (ret[i] >= 'A' && ret[i] <= 'Z')
    {
      if (ret[i] >= 'N')
        ret[i] -= 13;
      else
        ret[i] += 13;
    }
  }
  return ret;
}
