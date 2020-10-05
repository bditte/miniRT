/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bditte <bditte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/21 23:42:54 by bditte            #+#    #+#             */
/*   Updated: 2020/10/05 16:09:34 by bditte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	ft_isdigit(char c)
{
	if (48 <= c && c <= 57)
		return (1);
	return (0);
}

int	parse_int(char *line, int *i)
{
	int		j;
	char	*res;

	j = 0;
	while (48 <= line[*i] && line[(*i)++] <= 57)
		j++;
	if (!(res = malloc(sizeof(char) * j + 1)))
		return (error(-3));
	*i -= j;
	j = 0;
	while (48 <= line[*i] && line[*i] <= 57)
		res[j++] = line[(*i)++];
	res[j] = '\0';
	j = ft_atoi(res);
	free(res);
	return (j);
}
