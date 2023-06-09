/*
Name: Isograms
Kata: 7 kyu
Link: https://www.codewars.com/kata/54ba84be607a92aa900000f1

Description: An isogram is a word that has no repeating letters, consecutive or non-consecutive.
Implement a function that determines whether a string that contains only letters is an isogram.
Assume the empty string is an isogram. Ignore letter case.

Example: (Input --> Output)

"Dermatoglyphics" --> true "aba" --> false "moOse" --> false (ignore letter case)

isIsogram "Dermatoglyphics" = true
isIsogram "moose" = false
isIsogram "aba" = false
*/

#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

char  *ft_strcpy(const char *string)
{
  int   i = -1;
  int   len = strlen(string) + 1;
  char  *ret = malloc(len * sizeof(char));
  
  while(string[++i])
    ret[i] = string[i];
  ret[i] = 0;
  return (ret);
}

bool IsIsogram (const char *string) 
{
  int   i = 0;
  int   j = 0;
  char  *temp = 0;
  
  if (!string)
    return true;
  temp = ft_strcpy(string);
  while (temp[i])
  {
    if (temp[i] >= 'A' && temp[i] <= 'Z')
      temp[i] += 32;
    i++;
  }
  i = -1;
  while (temp[++i])
  {
    j = i;
    while (temp[++j])
    {
      if (temp[i] == temp[j])
      {
        free(temp);
        return false;
      }
    }
  }
  free(temp);
  return true;
}
