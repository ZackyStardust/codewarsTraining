/*
Name: Playing with Digits
Kata: 6 kyu
Link: https://www.codewars.com/kata/5552101f47fc5178b1000050

Description: Some numbers have funny properties. For example:

89 --> 8¹ + 9² = 89 * 1

695 --> 6² + 9³ + 5⁴= 1390 = 695 * 2

46288 --> 4³ + 6⁴+ 2⁵ + 8⁶ + 8⁷ = 2360688 = 46288 * 51

Given a positive integer n written as abcd... (a, b, c, d... being digits) and a positive integer p

we want to find a positive integer k, if it exists, such that the sum of the digits of n taken to
the successive powers of p is equal to k * n.
In other words:

Is there an integer k such as : (a ^ p + b ^ (p+1) + c ^(p+2) + d ^ (p+3) + ...) = n * k

If it is the case we will return k, if not return -1.

Note: n and p will always be given as strictly positive integers.

dig_pow(89, 1) should return 1 since 8¹ + 9² = 89 = 89 * 1
dig_pow(92, 1) should return -1 since there is no k such as 9¹ + 2² equals 92 * k
dig_pow(695, 2) should return 2 since 6² + 9³ + 5⁴= 1390 = 695 * 2
dig_pow(46288, 3) should return 51 since 4³ + 6⁴+ 2⁵ + 8⁶ + 8⁷ = 2360688 = 46288 * 51
*/

#include <stdlib.h>
#include <stdio.h>

// Using my own itoa functions gives me more control over what is being done.

char	*changer(char *ret, int nf, int alg)
{
	if (nf == 0)
	{
		ret = (char *)malloc(2);
		if (!ret)
			return (0);
		ret[0] = '0';
		ret[1] = '\0';
		return (ret);
	}
	ret = (char *)malloc(alg + 1);
	if (!ret)
		return (0);
	ret[alg--] = '\0';
	while (nf > 0)
	{
		ret[alg--] = nf % 10 + '0';
		nf /= 10;
	}
	return (ret);
}

char	*ft_itoa(int n)
{
	long	nf;
	size_t alg;
	char *ret = 0;

	alg = 0;
	nf = n;
	while (n)
	{
		n /= 10;
		alg++;
	}
	return (changer (ret, nf, alg));
}

// 48 = 0

int digPow(int n, int p)
{
  char  *num = 0; // Turning n into a string makes it easier to process each digit.
  int   sum = 0; // This will be the final sum, in which I will iterate k to find k's value.
  int   temp = 0; // Temporary number to iterate the digit over the power.
  
  num = ft_itoa(n);
  if (!num)
    return -1;
  for (int i = 0; num[i]; i++)
  {
    temp = num[i] - 48;
    for (int temp_p = 1; temp_p < p + i; temp_p++)
      temp *= (num[i] - 48);
    sum += temp;
  }
  if (sum < n)
  {
    free(num);
    return (-1);
  }
  for (int k = 1; n * k <= sum; k++)  
  {
    if ((n * k) == sum)
    {
      free(num);
      return (k);
    }
  }
  free(num);
  return (-1);
}
