/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_objects.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bditte <bditte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/22 01:13:09 by bditte            #+#    #+#             */
/*   Updated: 2020/10/10 15:49:26 by bditte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	parse_pl(char *line, t_scene *scene)
{
	int			i;
	int			n;
	t_vector	c;
	t_vector	normal;
	t_vector	color;

	n = 0;
	i = 0;
	while (line[i] && n < 3)
	{
		if (ft_iscoord(line[i]))
		{
			if (n == 0)
				c = parse_vec(line, &i);
			else if (n == 1)
				normal = parse_vec(line, &i);
			else
				color = conv_color(parse_vec(line, &i));
			n++;
		}
		i++;
	}
	*scene->planes = create_plane(c, normal, color);
	scene->planes++;
}

void	parse_tr(char *line, t_scene *scene)
{
	int			i;
	int			n;
	t_vector	tab[4];

	n = 0;
	i = 0;
	while (line[i] && n < 4)
	{
		if (ft_iscoord(line[i]))
		{
			if (n < 4)
				tab[n] = parse_vec(line, &i);
			else
				error(-2);
			n++;
		}
		i++;
	}
	*scene->triangles = create_tr(tab[0], tab[1], tab[2], conv_color(tab[3]));
	scene->triangles++;
}

void	parse_cy(char *line, t_scene *scene)
{
	t_vector	vec[3];
	float		nb[2];
	int			n;
	int			i;

	i = 0;
	n = 0;
	while (line[i])
	{
		if (ft_iscoord(line[i]))
		{
			if (n < 2)
				vec[n] = parse_vec(line, &i);
			else if (n < 4)
				nb[n - 2] = parse_float(line, &i);
			else if (n == 4)
				vec[2] = conv_color(parse_vec(line, &i));
			else
				error(-2);
			n++;
		}
		i++;
	}
	*scene->cylinders = create_cy(vec[0], vec[1], nb[0], nb[1], vec[2]);
	scene->cylinders++;
}

void	parse_sp(char *line, t_scene *scene)
{
	int			i;
	int			n;
	t_vector	c;
	t_vector	color;
	float		r;

	n = 0;
	i = 0;
	while (line[i] && n < 3)
	{
		if (ft_iscoord(line[i]))
		{
			if (n == 0)
				c = parse_vec(line, &i);
			else if (n == 1)
				r = parse_float(line, &i) / 2;
			else if (n == 2)
				color = conv_color(parse_vec(line, &i));
			n++;
		}
		i++;
	}
	*scene->spheres = create_sphere(c, r, color);
	scene->spheres++;
}

void                    parse_sq(char *line, t_scene *scene)
{
	t_vector	tab[3];
	float		height;
	int			i;
	int 			n;

	n = 0;
	i = 1;
	while (line[++i])
	{
		if (ft_iscoord(line[i]))
		{
			if (n < 2)
				tab[n] = parse_vec(line, &i);
			if (n == 2)
				height = parse_float(line, &i);
			else
				tab[2] = parse_vec(line, &i);
			n++;	
		}
	}
	*scene->squares = create_sq(tab[0], tab[1], height, conv_color(tab[2]));
	scene->squares++;
}
