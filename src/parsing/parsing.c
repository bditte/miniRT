/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bditte <bditte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/22 00:47:20 by bditte            #+#    #+#             */
/*   Updated: 2020/10/05 16:09:18 by bditte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	set_to_zero(t_scene *scene)
{
	scene->nbspheres = 0;
	scene->nbplanes = 0;
	scene->nbtriangles = 0;
	scene->nbcylinders = 0;
	scene->nblights = 0;
	scene->nbsquares = 0;
	scene->nbcams = 0;
	scene->data.r = 0;
	scene->data.a = 0;
}

void	count_objects(char *file, t_scene *scene)
{
	int		fd;
	char	*line;

	set_to_zero(scene);
	fd = open(file, O_RDONLY);
	if (fd < 0)
		error(-1);
	while (get_next_line(fd, &line))
	{
		if (line[0] == 's')
		{
			if (line[1] == 'p')
				scene->nbspheres++;
			if (line[1] == 'q')
				scene->nbsquares++;
		
		}
		if (line[0] == 'p' && line[1] == 'l')
			scene->nbplanes++;
		if (line[0] == 't' && line[1] == 'r')
			scene->nbtriangles++;
		if (line[0] == 'c' )
		{
			if (line[1] == 'y')
				scene->nbcylinders++;
			if (ft_isspace(line[1]))
				scene->nbcams++;
		}
		if (line[0] == 'l' && ft_isspace(line[1]))
			scene->nblights++;
		free(line);
	}
	free(line);
	close(fd);
}

void	scene_init(t_scene *scene)
{
	if (!(scene->spheres = malloc(sizeof(t_sphere) * scene->nbspheres)))
		error(-3);
	if (!(scene->planes = malloc(sizeof(t_plane) * scene->nbplanes)))
		error(-3);
	if (!(scene->triangles = malloc(sizeof(t_triangle) * scene->nbtriangles)))
		error(-3);
	if (!(scene->cylinders = malloc(sizeof(t_cylinder) * scene->nbcylinders)))
		error(-3);
	if (!(scene->lights = malloc(sizeof(t_light) * scene->nblights)))
		error(-3);
	if (!(scene->squares = malloc(sizeof(t_square) * scene->nbsquares)))
		error(-3);
	if (!(scene->cams = malloc(sizeof(t_cam) * scene->nbcams)))
		error(-3);
}

void	check_flags(char *line, t_scene *scene)
{
	if (line[0] == 'R' && ft_isspace(line[1]))
		parse_r(line, scene);
	else if(line[0] == 'A' && ft_isspace(line[1]))
		parse_a(line, scene);
	else if (line[0] == 'l' && ft_isspace(line[1]))
		parse_l(line, scene);
	else if (line[0] == 's')
	{
		if (line[1] == 'p' && ft_isspace(line[2]))
			parse_sp(line, scene);
		if (line[1] == 'q' && ft_isspace(line[2]))
			parse_sq(line, scene);
	}
	else if (line[0] == 'p' && line[1] == 'l' && ft_isspace(line[2]))
		parse_pl(line, scene);
	else if (line[0] == 't' && line[1] == 'r' && ft_isspace(line[2]))
		parse_tr(line, scene);
	else if (line[0] == 'c' )
	{
		if (line[1] == 'y' && ft_isspace(line[2]))
			parse_cy(line, scene);
		if (ft_isspace(line[1]))
			parse_c(line, scene);
	}
	free(line);
}

int		parse(int ac, char **av, t_scene *scene)
{
	int		fd;
	char	*line;

	fd = get_fd(ac, av, scene);
	count_objects(av[1], scene);
	scene_init(scene);
	while (get_next_line(fd, &line) == 1)
		check_flags(line, scene);
	free(line);
	if (!scene->data.a || !scene->data.r)
		error(-14);
	if (!scene->nbcams)
		error(-16);	
	scene->spheres -= scene->nbspheres;
	scene->planes -= scene->nbplanes;
	scene->triangles -= scene->nbtriangles;
	scene->cylinders -= scene->nbcylinders;
	scene->squares -= scene->nbsquares;
	scene->lights -= scene->nblights;
	scene->cams -= scene->nbcams;
	return (1);
}
