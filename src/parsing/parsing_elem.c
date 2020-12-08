/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_elem.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bditte <bditte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/22 17:12:05 by bditte            #+#    #+#             */
/*   Updated: 2020/11/28 18:47:42 by bditte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

float		ft_atof(char *str)
{
	int		neg;
	float	res;
	int		i;
	int		j;

	j = 1;
	i = 0;
	neg = 1;
	res = 0;
	if (str[0] == '-')
	{
		neg = -1;
		i++;
	}
	while (str[i] != '.' && str[i])
		res = res * 10 + (str[i++] - 48);
	if (str[i] == '.')
	{
		while (str[++i])
		{
			res = res + ((str[i] - 48) / pow(10, j));
			j++;
		}
	}
	return (res * neg);
}

t_vector	parse_vec(char *line)
{
	t_vector	result;
	char		**tab;

	tab = ft_split(line, 1, ',');
	result.x = ft_atof(tab[0]);
	result.y = ft_atof(tab[1]);
	result.z = ft_atof(tab[2]);
	ft_free(tab);
	return (result);
}
