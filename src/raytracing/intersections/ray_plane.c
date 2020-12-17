/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_plane.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bditte <bditte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/28 22:17:08 by bditte            #+#    #+#             */
/*   Updated: 2020/12/17 16:03:28 by bditte           ###   ########.fr       */
/*   Updated: 2020/11/30 15:36:26 by bditte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int		hit_pl(t_plane pl, t_ray r, t_inter *inter)
{
	float	denom;
	float	t;
	float	a;

	denom = dot(r.dir, pl.n);
	a = dot(vec_sub(r.o, pl.c), pl.n);
	if (denom == 0 || (a < 0 && denom < 0) || (a > 0 && denom > 0))
		return (0);
	t = -a / denom;
	if (t > 0)
	{
		inter->n = pl.n;
		inter->p = vec_add(r.o, vec_multiply_t(t, vec_normalize(r.dir)));
		inter->t = t;
		return (1);
	}
	return (0);
}

int		pl_inter(t_scene s, t_inter *inter)
{
	t_inter	local_inter;
	int		has_inter;

	if (inter->type == -3)
		local_inter.type = -3;
	has_inter = 0;
	local_inter.i = 0;
	while (local_inter.i < s.nbplanes)
	{
		if (hit_pl(s.planes[local_inter.i], s.r, &local_inter))
		{
			has_inter = 1;
			if (local_inter.t < inter->t || inter->t == -1)
				*inter = local_inter;
		}
		local_inter.i++;
	}
	return (has_inter);
}

t_inter	ray_plane(t_scene s)
{
	t_inter	inter;
	int		has_inter;

	inter.t = -1;
	has_inter = pl_inter(s, &inter);
	if (has_inter)
	{
		inter.color = s.planes[inter.i].color;
		inter.type = 1;
	}
	return (inter);
}
