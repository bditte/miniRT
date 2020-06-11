#include "miniRT.h"

t_vector	vec_create(float x, float y, float z)
{
	t_vector vec;

	vec.x = x;
        vec.y = y;
        vec.z = z;
        return (vec);
}

t_vector	vec_init(float x, float y, float z)
{
	t_vector *vec;

	vec = malloc(sizeof(vec));			
	vec->x = x;	
	vec->y = y;
	vec->z = z;
	return (*vec);
}

t_ray		ray_init(t_vector a, t_vector b)
{
	t_ray *ray;

	ray = malloc(sizeof(ray));
	ray->o.x = a.x;
	ray->o.y = a.y;
	ray->o.z = a.z;
	ray->dir.x = b.x;
	ray->dir.y = b.y;
	ray->dir.z = b.z;
	return (*ray);
}

t_vector	make_unit_vec(t_vector vec)
{
	float k;
	t_vector result;
	
	k = 1.0 / sqrt(vec.x * vec.x + vec.y * vec.y + vec.z * vec.z);
	result.x = vec.x * k;
	result.y = vec.y * k;
	result.z = vec.z * k;
	return (result);
}

