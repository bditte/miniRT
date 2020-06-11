#include "miniRT.h"

t_cylinder	create_cy(t_vector c, t_vector a, float r, float h, t_vector b)
{
	t_cylinder res;

	res.c = c;
	res.axis = a;
	res.r = r / 2.0;
	res.h = h;
	res.color = b;
	res.x1 = -1;
	res.x2 = -1;
	return (res);
}
