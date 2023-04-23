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