/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_scene.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bditte <bditte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/21 23:55:59 by bditte            #+#    #+#             */
/*   Updated: 2020/12/20 18:43:41 by bditte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	parse_r(char **line, t_scene *scene)
{
	int	tab[4];

	if (scene->data.r)
		error(-111);
	if (nb_elem(line) != 3)
		error(-10);
	if (!ft_isint(line[1]) || !ft_isint(line[2]))
		error(-10);
	tab[0] = ft_atoi(line[1]);
	tab[1] = ft_atoi(line[2]);
	scene->data.width = tab[0];
	scene->data.height = tab[1];
	mlx_get_screen_size(scene->data.mlx, &tab[2], &tab[3]);
	if (scene->data.width > tab[2])
		scene->data.width = tab[2];
	if (scene->data.height > tab[3])
		scene->data.height = tab[3];
	scene->data.r = 1;
}

void	parse_a(char **line, t_scene *scene)
{
	if (scene->data.a)
		error(-112);
	if (nb_elem(line) != 3)
		error(-12);
	if (!ft_isfloat(line[1]) || !ft_iscolor(line[2]))
		error(-12);
	scene->ambient_int = ft_atof(line[1]);
	scene->ambient_color = conv_color(parse_vec(line[2]));
	if (!check_ratio(scene->ambient_int))
		error(-12);
	scene->data.a = 1;
}

void	parse_l(char **line, t_scene *scene)
{
	t_light		res;

	if (nb_elem(line) != 4)
		error(-13);
	if (!ft_isvec(line[1]) || !ft_isfloat(line[2])
		|| !ft_iscolor(line[3]))
		error(-13);
	res.pos = parse_vec(line[1]);
	res.ratio = ft_atof(line[2]);
	res.color = conv_color(parse_vec(line[3]));
	if (!check_ratio(res.ratio))
		error(-13);
	*scene->lights = res;
	scene->lights++;
}

void	parse_c(char **line, t_scene *scene)
{
	int			fov;
	t_vector	vec[2];

	if (nb_elem(line) != 4)
		error(-15);
	if (!ft_isvec(line[1]) || !ft_isvec(line[2])
		|| !ft_isint(line[3]))
		error(-15);
	vec[0] = parse_vec(line[1]);
	vec[1] = parse_vec(line[2]);
	fov = ft_atoi(line[3]);
	if (fov > 180 || fov < 0)
		error(-15);
	*scene->cams = create_cam(vec[0], vec[1], fov);
	scene->cams++;
}
