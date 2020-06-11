#include "miniRT.h"

int     create_rgb(t_vector pixel)
{
	int color;

	color = (int)pixel.x;
	color = (int)(color << 8) + (int)pixel.y;
	color = (int)(color << 8) + (int)pixel.z;
        return (color);
}

