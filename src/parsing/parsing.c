#include "miniRT.h"

void	count_objects(char *file, t_scene *scene)
{
	int     fd;
        char    *line;

	scene->nbSpheres = 0;
	scene->nbPlanes = 0;
	scene->nbTriangles = 0;
	scene->nbCylinders = 0;
        fd = open(file, O_RDONLY);
        if (fd < 0)
                error(-1);
	while (get_next_line(fd, &line))
	{
                if (line[0] == 's')
                        if (line[1] == 'p')
				scene->nbSpheres++;
		if (line[0] == 'p' && line[1] == 'l')
			scene->nbPlanes++;
		if (line[0] == 't' && line[1] == 'r')
			scene->nbTriangles++;
		if (line[0] == 'c' && line[1] == 'y')
			scene->nbCylinders++;
	}
	close(fd);
}

void	scene_init(t_scene *scene)
{
	if (!(scene->spheres = malloc(sizeof(t_sphere) * scene->nbSpheres)))
		error(-3);
	if (!(scene->planes = malloc(sizeof(t_plane) * scene->nbPlanes)))
		error(-3);
	if (!(scene->triangles = malloc(sizeof(t_triangle) * scene->nbTriangles)))
                error(-3);
	if (!(scene->cylinders = malloc(sizeof(t_triangle) * scene->nbCylinders)))
                error(-3);
}

int	parse(int ac, char **av, t_scene *scene)
{
	int	fd;
	char	*line;

	fd = open(av[1], O_RDONLY);
	if (fd < 0)
		error(-1);
	count_objects(av[1], scene);
	scene_init(scene);
	while (get_next_line(fd, &line) == 1)
	{
		if (line[0] == 'R')
			parse_r(line, scene);
		if (line[0] == 's')
			if (line[1] == 'p')											parse_sp(line, scene);
		if (line[0] == 'p')
			parse_pl(line, scene);
		if (line[0] == 't')
			parse_tr(line, scene);
		if (line[0] == 'c' && line[1] == 'y')
			parse_cy(line, scene);
	}
	scene->spheres -= scene->nbSpheres;
	scene->planes -= scene->nbPlanes;
	scene->triangles -= scene->nbTriangles;
	scene->cylinders -= scene->nbCylinders;
	printf("here\n");
}
