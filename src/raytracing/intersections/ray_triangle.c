/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   triangle_color.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bditte <bditte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 15:50:55 by bditte            #+#    #+#             */
/*   Updated: 2020/11/28 21:49:17 by bditte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int		is_inside_tr(t_triangle tr, t_vector n, t_vector p)
{
	t_vector	edges[3];
	t_vector	c[3];

	edges[0] = vec_sub(tr.b, tr.a);
	edges[1] = vec_sub(tr.c, tr.b);
	edges[2] = vec_sub(tr.a, tr.c);
	c[0] = vec_sub(p, tr.a);
	c[1] = vec_sub(p, tr.b);
	c[2] = vec_sub(p, tr.c);
	if (dot(n, cross(edges[0], c[0])) >= 0 &&
		dot(n, cross(edges[1], c[1])) >= 0 &&
		dot(n, cross(edges[2], c[2])) >= 0)
		return (1);
	return (0);
}

int		hit_tr(t_ray r, t_triangle tr, t_inter *inter)
{
	float		d;

	inter->n = tr.n;
	d = dot(inter->n, tr.a);
	if (fabs(dot(inter->n, r.dir)) < EPSILON)
		return (-1);
	inter->t = dot(vec_sub(tr.a, r.o), inter->n) / dot(inter->n, r.dir);
	if (inter->t < 0)
		return (-1);
	inter->p = vec_add(r.o, vec_multiply_t(inter->t, r.dir));
	if (!is_inside_tr(tr, inter->n, inter->p) &&
		!is_inside_tr(tr, vec_multiply_t(-1, inter->n), inter->p))
		return (-1);
	return (1);
}

int		tr_inter(t_scene s, t_inter *inter)
{
	int		res;
	t_inter	local;

	res = 0;
	local.i = 0;
	while (local.i < s.nbtriangles)
	{
		if (hit_tr(s.r, s.triangles[local.i], &local) == 1)
		{
			res = 1;
			if (local.t < inter->t || inter->t == -1)
			{
				*inter = local;
			}
		}
		local.i++;
	}
	return (res);
}

t_inter	ray_triangle(t_scene s)
{
	t_inter		inter;

	inter.t = -1;
	if (tr_inter(s, &inter))
	{
		inter.color = s.triangles[inter.i].color;
		inter.type = 2;
		inter.point = s.triangles[inter.i].a;
	}
	return (inter);
}
