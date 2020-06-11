#include "miniRT.h"

t_vector	positive(t_vector vec)
{
	if (vec.x < 0)
		vec.x *= -1;
	if (vec.y < 0)
		vec.y *= -1;
	if (vec.z < 0)
		vec.z *= -1;
	return (vec);
}

t_vector	lighting(t_ray r, t_scene s, t_inter inter)
{
	t_inter		light_inter;
	t_ray		ray_light;
	t_vector	vec_l;
	float		d_light2;
	t_vector	offset;
	int		has_inter;
	t_vector color;
	float		scalar;

	vec_l = vec_sub(s.l_position, inter.p);
	//vec_display(inter.p);
	offset = vec_multiply_t(0.01, inter.n);
	ray_light = ray_init(vec_add(inter.p, offset), vec_normalize(vec_l));
	light_inter = intersections(ray_light,s, 5);
	d_light2 = getNorme2(vec_l);
	if (inter.type == 1)
	{
		printf("%f\n", dot(vec_normalize(vec_l), inter.n));	
	}
	if (light_inter.t > 0 && (light_inter.t * light_inter.t < d_light2))
		return (vec_init(0,0,0));
	else
		return (vec_multiply_t(s.l_int * ft_max(0, dot(vec_normalize(vec_l), inter.n)) /d_light2, inter.color));
	if (inter.type == 3)
		printf("here\n");
/*	if (inter.type == 1)	{
		return (vec_create(255,0,0));
		vec_display(vec_l);
		printf("\n");
	}	//printf("%d\n", light_inter.type);
*/		//return (vec_init(0,0,0));
	scalar = dot(vec_normalize(vec_l), inter.n);
	color = vec_multiply_t(s.l_int * ft_max(0, scalar) /d_light2, inter.color);
//	vec_display(color);
//	printf("%f\n",dot(vec_normalize(vec_l), inter.n));
	return (vec_multiply_t(s.l_int, inter.color));
}
