#include "miniRT.h"

t_sphere	create_sphere(t_vector c, float r, t_vector albedo)
{
	t_sphere result;

	result.c = c;
	result.r = r;
	result.albedo = albedo;
	result.mirror = 0;
	result.transparent = 0;
	return (result);
}
