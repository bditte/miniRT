#ifndef MINIRT_H
# define MINIRT_H

# include "mlx.h"
# include <math.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>

# include "vector.h"
# include "color.h"
# include "comparison.h"
# include "matrix.h"
# include "intersection.h"
# include "lighting.h"

# include "plane.h"
# include "sphere.h"
# include "scene.h"
# include "triangle.h"
# include "cylinder.h"

# include "raytracing.h"

# include "parsing.h"
# include "error.h"

# include "get_next_line.h"

# define PI 3.1415926535897932


typedef struct s_color
{
	int r;
	int g;
	int b;
}		t_color;

void	ft_image(void *mlx_ptr, void *win_ptr);
# endif
