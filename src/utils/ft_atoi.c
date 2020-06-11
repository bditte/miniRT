#include "miniRT.h"

int	ft_atoi(char *str)
{
	int	res;
	int	sign;
	int 	i;

	res = 0;
	i = 0;
	sign = 1;
	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	while (str[i])
	{
		res = res * 10 + (str[i] - 48);
		i++;
	}
	return (res * sign);

}
