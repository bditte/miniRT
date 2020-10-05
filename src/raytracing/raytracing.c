/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bditte <bditte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/25 01:59:07 by bditte            #+#    #+#             */
/*   Updated: 2020/09/25 18:45:27 by bditte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void		inter2(t_scene s, t_inter last, t_inter *res)
{
	if (s.nbtriangles > 0)
	{
		last = triangle_color(s);
		if (last.t < res->t && last.t > 0)
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
		if (last.t < res->t && last.t > 0)
			*res = last;
	}
}

t_inter		intersections(t_scene s)
{
	t_inter		res;
	t_inter		last_inter;

	res.t = 1000000000;
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
		if (last_inter.t < res.t && last_inter.t > 0)
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
/*
void		display(t_scene s)
{
	int		x;
	int		y;
	t_vector	direction;
	t_vector	pixel;

	y = 0;
	while (y < s.data.height)
	{
		x = 0;
		while (x < s.data.width)
		{
			direction = vec_create(x-s.data.width/2, y-s.data.height/2, (s.data.width * -1)/(2*tan(fov/2)));
			r = ray_init(origin, vec_normalize(direction));
			i_pixel = raytrace(s);
			pixel.x = (int)ft_min(255, ft_max(0, pow(i_pixel.x, 1/2.2)));
			pixel.y = (int)ft_min(255, ft_max(0, pow(i_pixel.y, 1/2.2)));
			pixel.z = (int)ft_min(255, ft_max(0, pow(i_pixel.z, 1/2.2)));

			my_pixel_put(&s.data, x, s.data.height - y - 1, create_rgb(pixel));
			x++;
		}
		y++;
	}

}*/
