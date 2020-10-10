/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bditte <bditte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/17 20:41:42 by bditte            #+#    #+#             */
/*   Updated: 2020/10/10 19:18:47 by bditte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include "mlx.h"
# include <math.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <float.h>

# include "vector.h"
# include "color.h"
# include "comparison.h"
# include "matrix.h"
# include "intersection.h"
# include "lighting.h"
# include "image.h"
# include "key.h"

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

# define INT_MAX 2147486647
# define SPHERE 0
# define PLANE 1
# define TRIANGLE 2
# define CYLINDER 3
# define SQUARE 4
typedef struct	s_color
{
	int r;
	int g;
	int b;
}				t_color;

void	ft_image(void *mlx_ptr, void *win_ptr);
#endif
