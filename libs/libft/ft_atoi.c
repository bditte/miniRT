/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bditte <bditte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 11:20:12 by bditte            #+#    #+#             */
/*   Updated: 2020/11/20 17:35:05 by bditte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		getnbr(const char *str, int multiply)
{
	long	nbr;

	nbr = 0;
	while (*str)
	{
		if (*str >= '0' && *str <= '9')
		{
			nbr *= 10;
			nbr += *str - '0';
			if (nbr < 0)
			{
				if (multiply == 1)
					return (-1);
				return (0);
			}
		}
		else
			return (nbr * multiply);
		str++;
	}
	return (nbr * multiply);
}

int		ft_atoi(const char *str)
{
	int	multiply;

	multiply = 1;
	while (*str == '\t' || *str == '\n' || *str == '\v'
		|| *str == '\f' || *str == '\r' || *str == ' ')
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			multiply = -1;
		str++;
	}
	return (getnbr(str, multiply));
}
