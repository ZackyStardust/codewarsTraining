/*
Name: Complementary DNA
Kata: 7 kyu
Link: https://www.codewars.com/kata/554e4a2f232cdd87d9000038

Description: Deoxyribonucleic acid (DNA) is a chemical found in the nucleus of cells and carries
the "instructions" for the development and functioning of living organisms.

If you want to know more: http://en.wikipedia.org/wiki/DNA

In DNA strings, symbols "A" and "T" are complements of each other, as "C" and "G". Your function
receives one side of the DNA (string, except for Haskell); you need to return the other complementary side.
DNA strand is never empty or there is no DNA at all (again, except for Haskell).

More similar exercise are found here: http://rosalind.info/problems/list-view/ (source)

Example: (input --> output)

"ATTGC" --> "TAACG"
"GTAT" --> "CATA"
*/

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