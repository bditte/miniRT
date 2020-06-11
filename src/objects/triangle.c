#include "miniRT.h"

t_triangle	create_triangle(t_vector x, t_vector y, t_vector z, t_vector color)
{
	t_triangle result;

	result.a = x;
	result.b = y;
	result.c = z;
	result.color = color;
	return (result);
}
