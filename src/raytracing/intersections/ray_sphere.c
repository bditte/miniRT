/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_sphere.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bditte <bditte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/28 22:16:40 by bditte            #+#    #+#             */
/*   Updated: 2020/12/01 16:47:43 by bditte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

float	hit_sp(t_sphere s, t_ray r, t_inter *local)
{
	t_vector	oc;
	t_vector	abc;
	t_vector	t;
	float		discriminant;

	oc = vec_sub(r.o, s.c);
	abc.x = 1;
	abc.y = 2.0 * dot(r.dir, oc);
	abc.z = getnorme2(oc) - s.r * s.r;
	discriminant = abc.y * abc.y - 4 * abc.x * abc.z;
	t.y = ((abc.y * -1) - sqrt(discriminant)) / (2 * abc.x);
	t.z = ((abc.y * -1) + sqrt(discriminant)) / (2 * abc.x);
	if (discriminant < 0)
		return (-1.0);
	if (t.z < 0)
		return (-1.0);
	if (t.y > 0)
		t.x = t.y;
	else
		t.x = t.z;
	local->p = vec_add(r.o, vec_multiply_t(t.x, r.dir));
	local->n = vec_normalize(vec_sub(local->p, s.c));
	return (t.x);
}

int		sp_inter(t_scene s, t_inter *inter)
{
	t_inter local;
	int		has_inter;

	local.i = 0;
	has_inter = 0;
	while (local.i < s.nbspheres)
	{
		local.t = hit_sp(s.spheres[local.i], s.r, &local);
		if (local.t > 0.0)
		{
			has_inter = 1;
			if (local.t < inter->t || inter->t == -1)
				*inter = local;
		}
		local.i++;
	}
	return (has_inter);
}

t_inter	ray_sphere(t_scene s)
{
	t_inter inter;
	int		has_inter;

	inter.t = -1;
	has_inter = sp_inter(s, &inter);
	if (has_inter)
	{
		inter.color = s.spheres[inter.i].albedo;
		inter.type = 0;
	}
	else
		inter.t = -1;
	return (inter);
}
