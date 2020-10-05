/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bditte <bditte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/21 12:23:53 by bditte            #+#    #+#             */
/*   Updated: 2020/09/24 17:13:51 by bditte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	update_orient(t_camera *cam)
{
	cam->orient = vec_multiply_t(cam->forward, -1);
}

t_cam	cam_update_forward(t_camera *cam)
{
	t_vector base;

	if (cam->forward.y == -1)
		base = vec_new(1,0,0);
	else
		base = vec_new(0,1,0);
	cam->right = vec_normalize(cross(base, cam->forward));
	cam->up = vec_normlaize(cross(cam->forward, cam->right));
	update_orient(cam);
	return (*cam);
}
