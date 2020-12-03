/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bditte <bditte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/18 20:41:03 by bditte            #+#    #+#             */
/*   Updated: 2020/11/28 21:39:03 by bditte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_H
# define VECTOR_H

# include "minirt.h"

typedef struct	s_vector
{
	float x;
	float y;
	float z;

}				t_vector;

typedef struct	s_ray
{
	t_vector	o;
	t_vector	dir;
	int			type;
}				t_ray;

t_vector		vec_create(float x, float y, float z);
t_ray			ray_init(t_vector a, t_vector b);
t_vector		point_at_param(t_ray ray, float t);
t_vector		vec_init(float x, float y, float z);
t_vector		vec_add(t_vector vec1, t_vector vec2);
t_vector		vec_multiply_t(float t, t_vector vec);
t_vector		vec_multi(t_vector a, t_vector b);
void			vec_display(t_vector vec);
int				vec_cmp(t_vector v1, t_vector v2);
t_vector		make_unit_vec(t_vector vec);
float			dot(t_vector vec1, t_vector vec2);
t_vector		vec_sub(t_vector vec1, t_vector vec2);
t_vector		vec_normalize(t_vector vec);
float			getnorme2(t_vector vec);
t_vector		cross(t_vector a, t_vector b);
#endif
