#ifndef VECTOR_H
# define VECTOR_H

# include "miniRT.h"

typedef struct	s_vector
{
	float x;
	float y;
	float z;

}		t_vector;

typedef struct  s_ray
{
        t_vector o;
        t_vector dir;
}               t_ray;

t_vector        vec_create(float x, float y, float z);
t_ray           ray_init(t_vector a, t_vector b);
t_vector        point_at_param(t_ray ray, float t);
t_vector	vec_init(float x, float y, float z);
t_vector	vec_add(t_vector vec1, t_vector vec2);
t_vector        vec_multiply_t(float t, t_vector vec);
void		vec_display(t_vector vec);
t_vector        make_unit_vec(t_vector vec);
float           dot(t_vector vec1, t_vector vec2);
t_vector        vec_sub(t_vector vec1, t_vector vec2);
t_vector	vec_normalize(t_vector vec);
float		getNorme2(t_vector vec);
t_vector        cross(t_vector a, t_vector b);
# endif
