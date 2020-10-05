#include "minirt.h"

t_vector	cross(t_vector a, t_vector b)
{
	t_vector result;

	result.x = a.y*b.z - a.z*b.y;
	result.y = a.z*b.x - a.x*b.z;
	result.z = a.x*b.y - a.y*b.x;
	return (result);
}

t_vector	vec_multi(t_vector a, t_vector b)
{
	t_vector result;

	result.x = a.x * b.x;
	result.y = a.y * b.y;
	result.z = a.z * b.z;

	return (result);
}
