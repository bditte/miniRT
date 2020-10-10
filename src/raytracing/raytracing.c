/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bditte <bditte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/25 01:59:07 by bditte            #+#    #+#             */
/*   Updated: 2020/10/10 19:44:54 by bditte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void		inter2(t_scene s, t_inter last, t_inter *res)
{
	if (s.nbtriangles > 0)
	{
		last = triangle_color(s);
		if ((last.t < res->t && last.t > 0) || res->t == -1)
			*res = last;
	}
	if (s.nbcylinders > 0)
	{
		last = cylinder_color(s);
		if (last.t < res->t && last.t > 0)
			*res = last;
	}
	if (s.nbsquares > 0)
	{
		last = square_color(s);
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
		last_inter = sphere_color(s);
		if (last_inter.t > 0)
			res = last_inter;
	}
	if (s.nbplanes > 0)
	{
		last_inter = plane_color(s);
		if ((last_inter.t < res.t && last_inter.t > 0) || res.t == -1)
			res = last_inter;
	}
	inter2(s, last_inter, &res);
	return (res);
}

t_vector	raytrace(t_scene s)
{
	t_inter inter;
	
	inter = intersections(s);
	if (inter.t > 0)
	{
		return (lighting(s, inter));
	}
	return (vec_init(0, 0, 0));
}

void		display(t_scene *s)
{
	int		x;
	int		y;
	t_vector	direction;
	t_vector	pixel;

	y = 0;
	while (y < s->data.height)
	{
		x = 0;
		while (x < s->data.width)
		{
			s->r = get_dir(*s, x, y, s->cams[s->current_cam]);
			pixel = raytrace(*s);
			pixel.x = (int)ft_min(255, ft_max(0, pow(pixel.x, 1/2.2)));
			pixel.y = (int)ft_min(255, ft_max(0, pow(pixel.y, 1/2.2)));
			pixel.z = (int)ft_min(255, ft_max(0, pow(pixel.z, 1/2.2)));
			my_pixel_put(&s->data, x, y, create_rgb(pixel));
			x++;
		}
		y++;
	}

}
