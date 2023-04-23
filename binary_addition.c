#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdint.h>

size_t	binarylen(int32_t num)
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
  //char *bin = 0;
  int32_t temp = a + b;
  int i = 0;
  
  if (a + b == 0)
  {
    binary[0] = '0';
    binary[1] = 0;
    return(binary);
  }
  digits = binarylen(temp);
  printf("Sum: %d\nDigits: %zu\n", a+b, digits);
  //binary = malloc(digits + 1);
  temp = a + b;
  binary[digits] = 0;
  while (digits--)
  {
    if ((temp >> i & 1) == 1)
      binary[digits] = '1';
    else
      binary[digits] = '0';
    i++;
  }
  //printf("%d, %d --> \"%s\" (%d + %d = %d in decimal or %s in binary)\n", a, b, binary, a, b, a+b, binary);
  //binary = int_to_bin(a + b);
	return (binary);
}
