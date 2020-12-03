/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_square.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bditte <bditte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/23 19:03:46 by bditte            #+#    #+#             */
/*   Updated: 2020/11/30 16:11:41 by bditte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int		hit_sq(t_ray r, t_square sq, t_inter *inter)
{
	t_vector	sol;
	t_vector	d;
	float		t1;
	float		t2;

	sol.x = dot(vec_sub(r.o, sq.c), sq.axis);
	sol.y = dot(r.dir, sq.axis);
	if (sol.y == 0 || (sol.x < 0 && sol.y < 0) || (sol.x > 0 && sol.y > 0))
		return (0);
	t1 = -sol.x / sol.y;
	d = vec_sub(vec_add(vec_multiply_t(t1, r.dir), r.o), sq.c);
	t2 = sq.height / 2;
	if (fabs(d.x) > t2 || fabs(d.y) > t2 || fabs(d.z) > t2)
		return (0);
	if (t1 > 0)
	{
		inter->t = t1;
		inter->n = sq.axis;
		inter->p = vec_add(r.o, vec_multiply_t(t1, r.dir));
		return (1);
	}
	return (0);
}

int		sq_inter(t_scene s, t_inter *inter)
{
	int		res;
	t_inter	local;

	local.i = 0;
	while (local.i < s.nbsquares)
	{
		if (hit_sq(s.r, s.squares[local.i], &local))
		{
			res = 1;
			if (local.t < inter->t || inter->t == -1)
				*inter = local;
		}
		local.i++;
	}
	return (res);
}

t_inter	ray_square(t_scene s)
{
	t_inter	inter;

	inter.t = -1;
	inter.i = 0;
	if (sq_inter(s, &inter))
	{
		inter.color = s.squares[inter.i].color;
		inter.type = SQUARE;
	}
	return (inter);
}
