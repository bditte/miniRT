/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_scene.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bditte <bditte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/21 23:55:59 by bditte            #+#    #+#             */
/*   Updated: 2020/10/10 19:45:12 by bditte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	parse_r2(t_scene *scene, int *tab)
{
	mlx_get_screen_size(scene->data.mlx, &tab[2], &tab[3]);
	if (scene->data.width > tab[2])
		scene->data.width = tab[2];
	if (scene->data.height > tab[3])
		scene->data.height = tab[3];
	scene->data.r = 1;	
}

void	parse_r(char *line, t_scene *scene)
{
	int	i;
	int	n;
	int	tab[4];

	n = 0;
	i = 0;
	while (line[++i] && n < 2)
	{
		if (!ft_isspace(line[i]))
		{
			if (48 <= line[i] && line[i] <= 57)
			{	
				tab[n] = parse_int(line, &i);
				if (n == 0)
					scene->data.width = tab[n];
				else if (n == 1)
					scene->data.height = tab[n];
				n++;
			}
			else
				error(-10);
		}
	}
	parse_r2(scene, tab);
}

void	parse_a(char *line, t_scene *scene)
{
	int n;
	int i;

	i = 0;
	n = 0;
	while (line[++i] && n < 2)
	{
		if (!ft_isspace(line[i]))
		{
			if (48 <= line[i] && line[i] <= 57)
			{
				if (n == 0)
					scene->ambient_int = parse_float(line, &i);
				else if (n == 1)
					scene->ambient_color = conv_color(parse_vec(line, &i));
				n++;
			}
			else
				error(-12);
		}
	}
	if (check_ratio(scene->ambient_int 
				|| check_color(scene->ambient_color)))
		error(-12);
	scene->data.a = 1;
}

void	parse_l(char *line, t_scene *scene)
{
	int			n;
	int			i;
	t_vector	tab[2];
	float		ratio;

	n = 0;
	i = 0;
	while (line[i] && n < 3)
	{
		if (ft_iscoord(line[i]))
		{
			if (n == 0)
				tab[0] = parse_vec(line, &i);
			else if (n == 2 && ft_isdigit(line[i]))
				tab[1] = conv_color(parse_vec(line, &i));
			else if (n == 1 && ft_isdigit(line[i]))
				ratio = parse_float(line, &i);
			else
				error(-13);
			n++;
		}
		i++;
	}
	if (check_ratio(ratio || check_color(tab[1])))
		error(-13);
	*scene->lights = create_light(tab[0], ratio, tab[1]);
	scene->lights++;
}

void	parse_c(char *line, t_scene *scene)
{
	int 		i;
	int		n;
	int		fov;
	t_vector	vec[2];

	i = 0;
	n = 0;
	while (line[++i])
	{
		if (ft_iscoord(line[i]) && n < 2)
		{
			vec[n] = parse_vec(line, &i);
			n++;
		}
		else if (ft_isdigit(line[i]))
		{
			fov = parse_int(line, &i);
			n++;
		}
	}
	if (fov > 180 || n != 3 || fov < 0)
		error(-15);
	*scene->cams = create_cam(vec[0], vec[1], fov);
	//*scene->cams = create_cam(vec[0], vec[1], fov);
	scene->cams++;
}
