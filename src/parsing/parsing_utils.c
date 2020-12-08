/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bditte <bditte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/22 01:26:09 by bditte            #+#    #+#             */
/*   Updated: 2020/12/08 14:44:23 by bditte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int			nb_elem(char **line)
{
	int res;

	res = 0;
	while (line[res])
		res++;
	return (res);
}

void		set_to_zero(t_scene *scene)
{
	scene->nbspheres = 0;
	scene->nbplanes = 0;
	scene->nbtriangles = 0;
	scene->nbcylinders = 0;
	scene->nblights = 0;
	scene->nbsquares = 0;
	scene->nbdisks = 0;
	scene->nbcams = 0;
	scene->data.r = 0;
	scene->data.a = 0;
	scene->current_cam = 0;
}

int			check_id(char *l)
{
	if (l[0] == '\n' || !l[0])
		return (0);
	if (l[0] == 'R' && ft_isspace(l[1]))
		return (0);
	if (l[0] == 'A' && ft_isspace(l[1]))
		return (0);
	if (l[0] == 'c' && ft_isspace(l[1]))
		return (0);
	if (l[0] == 'l' && ft_isspace(l[1]))
		return (0);
	if (l[0] == 's' && l[1] == 'p' && ft_isspace(l[2]))
		return (0);
	if (l[0] == 't' && l[1] == 'r' && ft_isspace(l[2]))
		return (0);
	if (l[0] == 's' && l[1] == 'q' && ft_isspace(l[2]))
		return (0);
	if (l[0] == 'p' && l[1] == 'l' && ft_isspace(l[2]))
		return (0);
	if (l[0] == 'c' && l[1] == 'y' && ft_isspace(l[2]))
		return (0);
	if (l[0] == 'd' && l[1] == 's' && ft_isspace(l[2]))
		return (0);
	return (1);
}

void		ft_free(char **tab)
{
	int i;

	i = nb_elem(tab);
	while (--i >= 0)
		free(tab[i]);
	free(tab);
}

t_vector	conv_color(t_vector color)
{
	color.x /= 255;
	color.y /= 255;
	color.z /= 255;
	return (color);
}
