#include "minirt.h"

t_light create_light(t_vector pos, float ratio, t_vector color)
{
	t_light light;

	light.pos = pos;
	light.ratio = ratio;//* 500000000;
	light.color = color;
	return (light);
}
