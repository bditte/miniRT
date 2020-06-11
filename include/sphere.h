#ifndef SPHERE_H
# define SPHERE_H

# include "miniRT.h"


typedef struct	s_sphere
{
	t_vector	c;
	t_vector	albedo;
	float		r;
	int		mirror;
	int		transparent;
}		t_sphere;

t_sphere	create_sphere(t_vector c, float r, t_vector albedo);
int		get_size(t_sphere *list);
# endif
