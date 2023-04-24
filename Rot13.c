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
