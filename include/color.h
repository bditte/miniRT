#ifndef COLOR_H
# define COLOR_H

# include "miniRT.h"
# include "sphere.h"

int     create_rgb(t_vector pixel);
t_vector ray_color(t_ray r, t_sphere s);
# endif
