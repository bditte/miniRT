/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_objects.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bditte <bditte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/22 01:13:09 by bditte            #+#    #+#             */
/*   Updated: 2020/12/08 14:46:31 by bditte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	parse_pl(char **line, t_scene *scene)
{
	t_plane	pl;

	if (nb_elem(line) != 4)
		error(-20);
	if (!ft_isvec(line[1]) || !ft_isvec(line[2])
		|| !ft_iscolor(line[3]))
		error(-20);
	pl.c = parse_vec(line[1]);
	pl.n = parse_vec(line[2]);
	pl.color = conv_color(parse_vec(line[3]));
	*scene->planes = pl;
	scene->planes++;
}

void	parse_tr(char **line, t_scene *scene)
{
	t_triangle	tr;

	if (nb_elem(line) != 5)
		error(-21);
	if (!ft_isvec(line[1]) || !ft_isvec(line[2])
		|| !ft_isvec(line[3]) || !ft_iscolor(line[4]))
		error(-21);
	tr.a = parse_vec(line[1]);
	tr.b = parse_vec(line[2]);
	tr.c = parse_vec(line[3]);
	tr.color = conv_color(parse_vec(line[4]));
	tr.n = vec_normalize(cross(vec_sub(tr.b, tr.a), vec_sub(tr.c, tr.a)));
	*scene->triangles = tr;
	scene->triangles++;
}

void	parse_cy(char **line, t_scene *scene)
{
	t_cylinder	cyl;

	if (nb_elem(line) != 6)
		error(-22);
	if (!ft_isvec(line[1]) || !ft_isvec(line[2])
		|| !ft_isfloat(line[3]) || !ft_isfloat(line[4])
		|| !ft_iscolor(line[5]))
		error(-22);
	cyl.c = parse_vec(line[1]);
	cyl.axis = parse_vec(line[2]);
	cyl.r = ft_atof(line[3]) / 2;
	cyl.h = ft_atof(line[4]);
	if (cyl.h < 0 || cyl.r < 0)
		error(-22);
	cyl.color = conv_color(parse_vec(line[5]));
	*scene->cylinders = cyl;
	scene->cylinders++;
}

void	parse_sp(char **line, t_scene *scene)
{
	t_sphere	sp;

	if (nb_elem(line) != 4)
		error(-23);
	if (!ft_isvec(line[1]) || !ft_isfloat(line[2])
		|| !ft_iscolor(line[3]))
		error(-23);
	sp.c = parse_vec(line[1]);
	sp.r = ft_atof(line[2]) / 2;
	sp.albedo = conv_color(parse_vec(line[3]));
	if (sp.r <= 0)
		error(-23);
	*scene->spheres = sp;
	scene->spheres++;
}

void	parse_sq(char **line, t_scene *scene)
{
	t_square	sq;

	if (nb_elem(line) != 5)
		error(-24);
	if (!ft_isvec(line[1]) || !ft_isvec(line[2])
		|| !ft_isfloat(line[3]) || !ft_iscolor(line[4]))
		error(-24);
	sq.c = parse_vec(line[1]);
	sq.axis = parse_vec(line[2]);
	sq.height = ft_atof(line[3]);
	if (sq.height < 0)
		error(-24);
	sq.color = conv_color(parse_vec(line[4]));
	*scene->squares = sq;
	scene->squares++;
}

void	parse_ds(char **line, t_scene *scene)
{
	t_disk	ds;
	
	if (nb_elem(line) != 5)
		error(-25);
	if (!ft_isvec(line[1]) || !ft_isvec(line[2])
		|| !ft_isfloat(line[3]) || !ft_iscolor(line[4]))
		error(-25);
	ds.c = parse_vec(line[1]);
	ds.n = parse_vec(line[2]);
	ds.r = ft_atof(line[3]);
	ds.color = conv_color(parse_vec(line[4]));
	if (ds.r < 0)
		error(-25);
	*scene->disks = ds;
	scene->disks++;
}

