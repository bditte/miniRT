#ifndef PLANE_H
# define PLANE_H

# include "miniRT.h"

typedef	struct	s_plane
{
	t_vector c;
	t_vector n;
	t_vector color;
}		t_plane;

t_plane create_plane(t_vector c, t_vector n, t_vector color);
int     hit_pl(t_plane pl, t_ray r, t_inter *inter);
# endif
