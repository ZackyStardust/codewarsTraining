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