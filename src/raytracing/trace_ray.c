/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trace_ray.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bditte <bditte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/25 01:59:07 by bditte            #+#    #+#             */
/*   Updated: 2020/11/28 21:57:42 by bditte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void		inter2(t_scene s, t_inter last, t_inter *res)
{
	if (s.nbtriangles > 0)
	{
		last = ray_triangle(s);
		if ((last.t < res->t && last.t > 0) || res->t == -1)
			*res = last;
	}
	if (s.nbcylinders > 0)
	{
		last = ray_cylinder(s);
		if ((last.t < res->t && last.t > 0) || res->t == -1)
			*res = last;
	}
	if (s.nbsquares > 0)
	{
		last = ray_square(s);
		if ((last.t < res->t && last.t > 0) || res->t == -1)
			*res = last;
	}
}

t_inter		intersections(t_scene s)
{
	t_inter		res;
	t_inter		last_inter;

	res.t = -1;
	res.type = -1;
	if (s.nbspheres > 0)
	{
		last_inter = ray_sphere(s);
		if (last_inter.t > 0)
			res = last_inter;
	}
	if (s.nbplanes > 0)
	{
		last_inter = ray_plane(s);
		if ((last_inter.t < res.t && last_inter.t > 0) || res.t == -1)
			res = last_inter;
	}
	inter2(s, last_inter, &res);
	return (res);
}

t_vector	trace_ray(t_scene s)
{
	t_inter	inter;

	inter = intersections(s);
	if (inter.t > 0)
	{
		return (get_color(s, inter));
	}
	return (vec_init(0, 0, 0));
}
