/*
Name: Binary Addition
Kata: 7 kyu
Link: https://www.codewars.com/kata/551f37452ff852b7bd000139

Description: Implement a function that adds two numbers together and returns their sum in binary.
The conversion can be done before, or after the addition.

The binary number returned should be a string.

Examples:(Input1, Input2 --> Output (explanation)))

1, 1 --> "10" (1 + 1 = 2 in decimal or 10 in binary)
5, 9 --> "1110" (5 + 9 = 14 in decimal or 1110 in binary)
*/

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