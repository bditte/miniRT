#include "miniRT.h"

t_plane	create_plane(t_vector c, t_vector n, t_vector color)
{
	t_plane result;

	result.c = c;
	result.n = n;
	result.color = color;

	return (result);
}

