/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bditte <bditte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/26 17:57:11 by bditte            #+#    #+#             */
/*   Updated: 2020/10/09 17:55:02 by bditte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_vector	look_at(t_cam cam, t_vector ray_origin)
{

	t_vector	res;

	res.x = ray_origin.x * cam.right.x + ray_origin.y *
		cam.up.x + ray_origin.z * cam.forward.x;
	res.y = ray_origin.x * cam.right.y + ray_origin.y *
		cam.up.y + ray_origin.z * cam.forward.y;
	res.z = ray_origin.x * cam.right.z + ray_origin.y *
		cam.up.z + ray_origin.z * cam.forward.z;
	return (res);
}

t_ray        get_dir(t_scene s, float x, float y, t_cam cam)
{

        float   fov;
        float	h;
	float	w;
	float	m[4][4];
	t_ray   ray;
	t_vector	tmp;
		
	ray.dir.x = 0;
	ray.dir.z = 0;
	ray.dir.y = 0;
        fov = tan(cam.fov / 2 * (M_PI / 180));
        w = s.data.width;
	h = s.data.height;
	tmp = vec_create(
		(2 * (x + 0.5) / w - 1)  * fov,
		(1 - 2 * (y + 0.5) / h) * fov,
		-1);
        if (w > h)
                tmp.x *= w / h;
	else
		tmp.y *= h / w;
	get_camtoworld(cam, m);
	ray.o = mult_vec_mat(vec_create(0,0,0), m);
	ray.dir = mult_vec_mat(tmp, m);
	ray.dir = vec_sub(ray.dir, ray.o);
	ray.dir = vec_normalize(ray.dir);
/*	ray.o = look_at(cam, ray.o);
	ray.o = vec_add(ray.o, cam.pos);
	ray.dir = vec_normalize(vec_sub(cam.pos, ray.o));
	ray.o = cam.pos;*/
	return (ray);
}
