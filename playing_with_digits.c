#include <stdlib.h>

// Using my own itoa functions gives me more control over what is being done.

char	*changer(char *ret, int nf, int sign, int alg)
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
	if (sign)
		ret[0] = '-';
	return (ret);
}

char	*ft_itoa(int n)
{
	long	nf;
	size_t alg;
	int sign;
	char *ret = 0;

	alg = 0;
	if (n < 0)
	{
		sign = 1;
		n *= -1;
		alg++;
	}
	nf = n;
	while (n)
	{
		n /= 10;
		alg++;
	}
	return (changer (ret, nf, sign, alg));
}

// 48 = 0

int digPow(int n, int p)
{
  char  *num = 0; // Turning n into a string makes it easier to process each digit.
  int   k = 1; // Final value to be returned.
  int   sum = 0; // This will be the final sum, in which I will iterate k to find k's value.
  int   i = -1; // The index on the string.
  int   temp; // Temporary number to iterate the digit over the power.
  int   temp_p; // Temporary power to keep track on the iteration.
  
  num = ft_itoa(n);
  if (!num)
    return -1;
  while (num[++i])
  {
    temp = num[i] - 48;
    temp_p = 0;
    while (++temp_p < p + i)
      temp = temp * (num[i] - 48);
    sum += temp;
  }
  if (sum < n)
    return (-1);
  while ((n * k) <= sum)
  {
    if ((n * k) == sum)
      return (k);
    k++;
  }
  return (-1);
}
