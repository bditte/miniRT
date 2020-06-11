#ifndef RAYTRACING_H
# define RAYTRACING_H

# include "miniRT.h"

t_inter		cylinder_color(t_ray r, t_scene s, int nbRebonds);
t_inter		plane_color(t_ray, t_scene s, int nbRebonds);
int		pl_inter(t_ray r, t_scene s, t_inter *inter);
int		sp_inter(t_scene s, t_ray r, t_inter *inter);
t_vector        get_color(t_ray r, t_scene s, int nbRebonds);
t_inter		triangle_color(t_ray r, t_scene s, int nbRebonds);
t_inter sphere_color(t_ray r, t_scene s, int nbRebonds);
void		assign_inter(t_inter src, t_inter *dst);
float		hit_sp(t_sphere s, t_ray r, t_inter *local);
t_inter         intersections(t_ray r, t_scene s, int nbRebonds);
# endif
