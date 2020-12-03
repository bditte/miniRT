/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_cylinder.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bditte <bditte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 18:05:48 by bditte            #+#    #+#             */
/*   Updated: 2020/11/30 15:37:27 by bditte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int		quadratic_solve(t_ray r, t_cylinder cyl, float *t)
{
	float		delta;
	float		abc[2];
	t_vector	c[2];

	c[0] = vec_sub(r.dir, vec_multiply_t(dot(r.dir, cyl.axis), cyl.axis));
	c[1] = vec_sub(vec_sub(r.o, cyl.c), vec_multiply_t(dot(vec_sub(r.o, cyl.c),
		cyl.axis), cyl.axis));
	abc[0] = 2.0 * dot(c[0], c[1]);
	abc[1] = getnorme2(c[1]) - pow(cyl.r, 2);
	delta = pow(abc[0], 2) - 4.0 * getnorme2(c[0]) * abc[1];
	if (delta < 0)
		return (0);
	if (delta < EPSILON)
	{
		t[0] = -0.5 * abc[0] / getnorme2(c[0]);
		t[1] = t[0];
	}
	else
	{
		t[0] = (-abc[0] + sqrt(delta)) / (2.0 * getnorme2(c[0]));
		t[1] = (-abc[0] - sqrt(delta)) / (2.0 * getnorme2(c[0]));
	}
	return (1);
}

void	get_cyl_base(t_cylinder cyl, t_vector *p)
{
	p[0] = vec_sub(cyl.c, vec_multiply_t(cyl.h / 2, cyl.axis));
	p[1] = vec_add(cyl.c, vec_multiply_t(cyl.h / 2, cyl.axis));
}

int		hit_cy(t_ray r, t_cylinder cyl, t_inter *inter)
{
	t_vector	p[2];
	t_vector	tmp;
	float		t[2];

	get_cyl_base(cyl, p);
	if (quadratic_solve(r, cyl, t))
	{
		tmp = vec_add(r.o, vec_multiply_t(t[0], r.dir));
		if (t[0] > EPSILON && dot(cyl.axis, vec_sub(tmp, p[0])) > 0
			&& dot(cyl.axis, vec_sub(tmp, p[1])) < 0)
			inter->t = t[0];
		tmp = vec_add(r.o, vec_multiply_t(t[1], r.dir));
		if (t[1] > EPSILON && dot(cyl.axis, vec_sub(tmp, p[0])) > 0
			&& dot(cyl.axis, vec_sub(tmp, p[1])) < 0)
			inter->t = (inter->t != -1) ? fmin(t[0], t[1]) : t[1];
		if (inter->t > 0)
			return (1);
	}
	return (-1);
}

int		cy_inter(t_scene s, t_inter *inter)
{
	int		res;
	t_inter	local;

	local.t = -1;
	local.i = 0;
	res = 0;
	while (local.i < s.nbcylinders)
	{
		if (hit_cy(s.r, s.cylinders[local.i], &local) && local.t > 0)
		{
			res = 1;
			if (local.t < inter->t || inter->t == -1)
				*inter = local;
		}
		local.i++;
	}
	return (res);
}

t_inter	ray_cylinder(t_scene s)
{
	t_inter	inter;

	inter.t = -1;
	if (cy_inter(s, &inter))
	{
		inter.color = s.cylinders[inter.i].color;
		inter.type = 3;
		inter.p = vec_add(s.r.o, vec_multiply_t(inter.t, s.r.dir));
		inter.n = vec_sub(inter.p, s.cylinders[inter.i].c);
	}
	else
		inter.t = -1;
	return (inter);
}
