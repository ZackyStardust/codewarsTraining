#include <stdint.h>
#include <stdlib.h>

size_t	binarylen(int64_t num)
{
	size_t	len;

	len = 0;
	while (num)
	{
		num >>= 1;
		len++;
	}
	return (len);
}


char *binary_add (unsigned a, unsigned b, char *binary)
{ 
  size_t digits = 0;
  uint64_t temp = (uint64_t)a + (uint64_t)b;
  
  if (a + b == 0)
  {
    binary[0] = '0';
    binary[1] = 0;
    return binary;
  }
  digits = binarylen(temp);
  binary[digits--] = 0;
  while (temp > 0)
  {
    binary[digits] = (temp % 2) + 48;
    temp /= 2;
    digits--;
  }
 	return binary;
}