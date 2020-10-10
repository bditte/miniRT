/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lighting.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bditte <bditte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/20 16:50:07 by bditte            #+#    #+#             */
/*   Updated: 2020/10/10 18:32:00 by bditte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_vector	get_plane_n(t_vector vec_l, t_vector n)
{
	float norm1;

	norm1 = getnorme2(vec_l);
	if (getnorme2(vec_add(vec_l, vec_multiply_t(0.01, n))) < norm1)
		return (vec_multiply_t(-1, n));
	return (vec_multiply_t(1, n));
}

void		get_shadows(t_scene s, t_inter inter, t_vector vec_l, t_inter *l_inter)
{
	t_vector	offset;

	if (inter.type == PLANE || inter.type == SQUARE)
		inter.n = get_plane_n(vec_l, inter.n);
	offset = vec_multiply_t(0.01, inter.n);
	s.r = ray_init(vec_add(inter.p, offset), vec_normalize(vec_l));
	*l_inter = intersections(s);
}

t_vector	apply_ambient(t_scene s, t_inter inter)
{
	t_vector	color;
	t_vector	tmp;
	
	tmp = vec_multiply_t(s.ambient_int / 100000, s.ambient_color);
	color = vec_multi(inter.color, tmp);
	return (color);
}
t_vector	get_color(t_scene s, t_inter inter, t_vector color, t_inter *l_inter)
{
	int		i;
	float		ratio;
	float		d_light2;
	t_vector	l_color;
	t_vector	vec_l;
	
	i = -1;
	color = apply_ambient(s, inter);
	while (++i < s.nblights)
	{
		vec_l = vec_sub(s.lights[i].pos, inter.p);
		d_light2 = getnorme2(vec_l);
		get_shadows(s, inter, vec_l, l_inter);
		if (l_inter->t > 0 && (l_inter->t * l_inter->t < d_light2))
		{
			//printf("1st pl : %d  t %f 2nd pl %d\n", inter.i, l_inter->t, l_inter->i);
			//printf("l_type :%d l_i : %d type : %d i : %d\n", l_inter->type, l_inter->i, inter.type, inter.i);
			continue;
		}
		l_color = vec_multi(s.lights[i].color, inter.color); 
		ratio = ft_max(0, dot(vec_normalize(vec_l), inter.n)) / d_light2;
		color = vec_add(vec_multiply_t(ratio * s.lights[i].ratio, l_color), color);
	}
	color = vec_multiply_t(500000000, color);
	return (color);
}

t_vector	lighting(t_scene s, t_inter inter)
{	t_inter		light_inter;
	t_vector 	color;

	if (inter.type == CYLINDER)
	color = vec_init(0,0,0);
	return (get_color(s, inter, color, &light_inter));
}
