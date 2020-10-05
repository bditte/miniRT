/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bditte <bditte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/25 19:04:57 by bditte            #+#    #+#             */
/*   Updated: 2020/10/01 13:39:07 by bditte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_cam	create_cam(t_vector pos, t_vector axis, int fov)
{
	t_cam res;

	res.pos = pos;
	res.axis = axis;
	res.fov = fov;
	res.forward = vec_multiply_t(-1, vec_normalize(axis));
	return (res);
}

t_cam   cam_update_forward(t_cam cam)
{
        t_vector base;

        if (cam.forward.y == -1)
                base = vec_init(1,0,0);
        else
                base = vec_init(0,1,0);
        cam.right = vec_normalize(cross(base, cam.forward));
        cam.up = vec_normalize(cross(cam.forward, cam.right));
	cam.axis = vec_multiply_t(-1, cam.forward);
	return (cam);
}
