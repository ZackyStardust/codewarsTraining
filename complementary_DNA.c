#include <stdlib.h>
#include <string.h>

char *dna_strand(const char *dna)
{
  int   len = strlen(dna);
  int   i = -1;
  char *ret;
  
  if (!dna)
    return NULL;
  ret = malloc((len + 1) * sizeof(char));
  if (!ret)
    return NULL;
  while (dna[++i])
  {
    if (dna[i] == 'T')
      ret[i] = 'A';
    else if (dna[i] == 'A')
      ret[i] = 'T';
    else if (dna[i] == 'C')
      ret[i] = 'G';
    else if (dna[i] == 'G')
      ret[i] = 'C';
  }
  ret[i] = 0;
  return (ret);
}