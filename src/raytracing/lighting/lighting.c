/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lighting.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bditte <bditte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/20 16:50:07 by bditte            #+#    #+#             */
/*   Updated: 2020/12/02 16:11:41 by bditte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int			is_shadow(t_scene s, t_inter inter, t_vector vec_l,
				float dist)
{
	t_inter		l_inter;

	s.r = ray_init(vec_add(inter.p, vec_multiply_t(0.01, inter.n))
			, vec_normalize(vec_l));
	l_inter = intersections(s);
	if (l_inter.t > 0 && l_inter.t < dist)
		return (1);
	return (0);
}

t_vector	apply_ambient(t_scene s, t_inter inter)
{
	t_vector	color;

	color = vec_multiply_t(s.ambient_int / 6, s.ambient_color);
	color = vec_multi(inter.color, color);
	return (color);
}

t_vector	apply_light(t_scene s, t_light l, t_inter inter)
{
	t_vector	res;
	t_vector	vec_l;
	float		dist;
	float		ratio;

	vec_l = vec_sub(l.pos, inter.p);
	dist = sqrt(getnorme2(vec_l));
	vec_normalize(vec_l);
	if (is_shadow(s, inter, vec_l, dist))
		return (vec_init(0, 0, 0));
	ratio = dot(vec_l, inter.n);
	if (inter.type == SQUARE)
		ratio = fabs(ratio);
	if (ratio < 0)
		return (vec_init(0, 0, 0));
	ratio *= l.ratio * 10;
	ratio /= 2 * PI * powf(dist, 2);
	res = vec_multi(l.color, inter.color);
	res = vec_multiply_t(ratio, res);
	return (res);
}

t_vector	get_color(t_scene s, t_inter inter)
{
	int			i;
	t_vector	color;

	i = -1;
	color = vec_init(0, 0, 0);
	color = apply_ambient(s, inter);
	while (++i < s.nblights)
		color = vec_add(color, apply_light(s, s.lights[i], inter));
	color = vec_multiply_t(255, color);
	return (color);
}
