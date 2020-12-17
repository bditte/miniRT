/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bditte <bditte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/22 00:47:20 by bditte            #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2020/12/16 18:39:55 by bditte           ###   ########.fr       */
=======
/*   Updated: 2020/11/30 19:59:19 by bditte           ###   ########.fr       */
>>>>>>> 8b13f38c897270853813f46c33c7461b645fb91f
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	count_objects(int fd, t_scene *scene)
{
	char	*l;

	while (get_next_line(fd, &l))
	{
		if (l[0] == 's' && l[1] == 'p' && ft_isspace(l[2]))
			scene->nbspheres++;
		else if (l[0] == 's' && l[1] == 'q' && ft_isspace(l[2]))
			scene->nbsquares++;
		else if (l[0] == 'p' && l[1] == 'l' && ft_isspace(l[2]))
			scene->nbplanes++;
		else if (l[0] == 't' && l[1] == 'r' && ft_isspace(l[2]))
			scene->nbtriangles++;
<<<<<<< HEAD
		else if (l[0] == 'd' && l[1] == 's' && ft_isspace(l[2]))
			scene->nbdisks++;
=======
>>>>>>> 8b13f38c897270853813f46c33c7461b645fb91f
		else if (l[0] == 'c' && l[1] == 'y' && ft_isspace(l[2]))
			scene->nbcylinders++;
		else if (l[0] == 'c' && ft_isspace(l[1]))
			scene->nbcams++;
		else if (l[0] == 'l' && ft_isspace(l[1]))
			scene->nblights++;
		if (check_id(l))
			error(-2);
		free(l);
	}
	free(l);
	close(fd);
}

void	scene_init(t_scene *s)
{
	if (s->nbspheres)
		if (!(s->spheres = malloc(sizeof(t_sphere) * s->nbspheres)))
			error(-3);
	if (s->nbplanes)
		if (!(s->planes = malloc(sizeof(t_plane) * s->nbplanes)))
			error(-3);
	if (s->nbtriangles)
		if (!(s->triangles = malloc(sizeof(t_triangle) * s->nbtriangles)))
			error(-3);
	if (s->nbcylinders)
		if (!(s->cylinders = malloc(sizeof(t_cylinder) * s->nbcylinders)))
			error(-3);
	if (s->nblights)
		if (!(s->lights = malloc(sizeof(t_light) * s->nblights)))
			error(-3);
	if (s->nbsquares)
		if (!(s->squares = malloc(sizeof(t_square) * s->nbsquares)))
			error(-3);
<<<<<<< HEAD
	if (s->nbdisks)
		if (!(s->disks = malloc(sizeof(t_disk) * s->nbdisks)))
			error(-3);
=======
>>>>>>> 8b13f38c897270853813f46c33c7461b645fb91f
	if (s->nbcams)
		if (!(s->cams = malloc(sizeof(t_cam) * s->nbcams)))
			error(-3);
}

void	check_flags(char *line, t_scene *scene)
{
	char **tab;

	tab = ft_split(line, 2, '\t', ' ');
	if (line[0] == 'R' && ft_isspace(line[1]))
		parse_r(tab, scene);
	else if (line[0] == 'A' && ft_isspace(line[1]))
		parse_a(tab, scene);
	else if (line[0] == 'l' && ft_isspace(line[1]))
		parse_l(tab, scene);
	else if (line[0] == 's' && line[1] == 'p' && ft_isspace(line[2]))
		parse_sp(tab, scene);
	else if (line[0] == 's' && line[1] == 'q' && ft_isspace(line[2]))
		parse_sq(tab, scene);
	else if (line[0] == 'p' && line[1] == 'l' && ft_isspace(line[2]))
		parse_pl(tab, scene);
	else if (line[0] == 't' && line[1] == 'r' && ft_isspace(line[2]))
		parse_tr(tab, scene);
	else if (line[0] == 'c' && line[1] == 'y' && ft_isspace(line[2]))
		parse_cy(tab, scene);
<<<<<<< HEAD
	else if (line[0] == 'd' && line[1] == 's' && ft_isspace(line[2]))
		parse_ds(tab, scene);
=======
>>>>>>> 8b13f38c897270853813f46c33c7461b645fb91f
	else if (line[0] == 'c' && ft_isspace(line[1]))
		parse_c(tab, scene);
	ft_free(tab);
	free(line);
}

int		parse(int ac, char **av, t_scene *scene)
{
	int		fd;
	char	*line;

	fd = get_fd(ac, av, scene);
	set_to_zero(scene);
	count_objects(fd, scene);
	fd = get_fd(ac, av, scene);
	scene_init(scene);
	while (get_next_line(fd, &line) == 1)
		check_flags(line, scene);
	close(fd);
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
	scene->disks -= scene->nbdisks;
	scene->lights -= scene->nblights;
	scene->cams -= scene->nbcams;
	return (1);
}
