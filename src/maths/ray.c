/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bditte <bditte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/26 17:57:11 by bditte            #+#    #+#             */
/*   Updated: 2020/11/30 18:41:35 by bditte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_ray		ray_init(t_vector a, t_vector b)
{
	t_ray r;

	r.o = a;
	r.dir = b;
	return (r);
}

t_vector	get_dir(t_scene s, float x, float y, t_cam cam)
{
	float		fov;
	float		h;
	float		w;
	t_ray		ray;
	t_vector	tmp;

	fov = tan(cam.fov / 2 * (M_PI / 180));
	w = s.data.width;
	h = s.data.height;
	tmp = vec_init((2 * (x + 0.5) / w - 1) * fov,
		(1 - 2 * (y + 0.5) / h) * fov,
		-1);
	if (w > h)
		tmp.x *= w / h;
	else
		tmp.y *= h / w;
	ray.dir = mult_vec_mat(tmp, cam.camtoworld);
	return (vec_normalize(ray.dir));
}
