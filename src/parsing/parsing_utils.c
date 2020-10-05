/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bditte <bditte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/22 01:26:09 by bditte            #+#    #+#             */
/*   Updated: 2020/10/05 16:09:26 by bditte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int			ft_iscoord(char c)
{
	if (48 <= c && c <= 57)
		return (1);
	else if (c == '-' || c == '.' || c == ',')
		return (1);
	return (0);
}

float		parse_float(char *l, int *i)
{
	int		j;
	char	tmp[10];

	j = 0;
	while (((48 <= l[*i] && l[*i] <= 57) || l[*i] == '.') && !ft_isspace(l[*i]))
	{
		tmp[j++] = l[*i];
		*i += 1;
	}
	tmp[j] = '\0';
	return (ft_atof(tmp));
}

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

t_vector	parse_vec(char *line, int *i)
{
	t_vector	result;
	int			j;
	int			n;
	char		tmp[100];

	n = 0;
	while (ft_iscoord(line[*i]) && n < 3)
	{
		j = 0;
		while (line[*i] != ',' && !ft_isspace(line[*i]) && line[*i])
			tmp[j++] = line[(*i)++];
		tmp[j] = '\0';
		if (n == 0)
			result.x = ft_atof(tmp);
		else if (n == 1)
			result.y = ft_atof(tmp);
		else
			result.z = ft_atof(tmp);
		n++;
		if (ft_iscoord(line[*i]))
			*i += 1;
	}
	return (result);
}

t_vector	conv_color(t_vector color)
{
	color.x /= 255;
	color.y /= 255;
	color.z /= 255;
	return (color);
}
