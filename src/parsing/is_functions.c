/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_functions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bditte <bditte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/21 23:42:54 by bditte            #+#    #+#             */
/*   Updated: 2020/11/28 18:51:49 by bditte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int		ft_isint(char *s)
{
	int i;

	if (!s)
		return (0);
	i = 0;
	while (ft_isdigit(s[i]))
		i++;
	if (!s[i])
		return (1);
	return (0);
}

int		ft_isfloat(char *s)
{
	int	i;
	int	nb;

	if (!ft_isdigit(s[0]) && s[0] != '-')
		return (0);
	if (!ft_isdigit(s[0]))
	{
		if (s[0] == '-' && !ft_isdigit(s[1]))
			return (0);
		else if (s[0] != '-')
			return (0);
	}
	nb = 0;
	i = 1;
	while (s[i])
	{
		if (s[i] == '.')
			nb++;
		else if (!ft_isdigit(s[i]))
			return (0);
		i++;
	}
	if (nb > 1)
		return (0);
	return (1);
}

int		ft_isvec(char *s)
{
	char	**vec;

	vec = ft_split(s, 1, ',');
	if (nb_elem(vec) != 3)
	{
		free(vec);
		return (0);
	}
	if (!ft_isfloat(vec[0]) || !ft_isfloat(vec[1])
			|| !ft_isfloat(vec[2]))
	{
		free(vec);
		return (0);
	}
	ft_free(vec);
	return (1);
}

int		ft_iscolor(char *s)
{
	char	**color;
	int		nb;
	int		i;

	i = -1;
	if (!ft_isvec(s))
		return (0);
	color = ft_split(s, 1, ',');
	while (color[++i])
	{
		nb = ft_atoi(color[i]);
		if (!(0 <= nb && nb <= 255))
			return (0);
	}
	ft_free(color);
	return (1);
}
