/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bditte <bditte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/25 19:04:57 by bditte            #+#    #+#             */
/*   Updated: 2020/12/01 16:43:33 by bditte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	look_at(t_cam *cam)
{
	t_vector	tmp;

	cam->forward = vec_multiply_t(-1, cam->axis);
	if (vec_cmp(cam->forward, vec_init(0, 1, 0))
		|| vec_cmp(cam->forward, vec_init(0, -1, 0)) == 1)
		tmp = vec_init(0, 0, 1);
	else
		tmp = vec_init(0, 1, 0);
	cam->right = vec_normalize(cross(tmp, cam->forward));
	cam->up = vec_normalize(cross(cam->forward, cam->right));
	get_camtoworld(*cam, cam->camtoworld);
}

t_cam	create_cam(t_vector pos, t_vector axis, int fov)
{
	t_cam		res;

	res.pos = pos;
	res.axis = axis;
	res.fov = fov;
	look_at(&res);
	return (res);
}
