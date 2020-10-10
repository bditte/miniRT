/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bditte <bditte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/25 19:04:57 by bditte            #+#    #+#             */
/*   Updated: 2020/10/10 18:10:29 by bditte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_cam	create_cam(t_vector pos, t_vector axis, int fov)
{
	t_cam		res;
	t_vector	tmp;

	res.pos = pos;
	res.axis = axis;
	res.fov = fov;
	res.forward = vec_normalize(vec_multiply_t(-1, axis));
        if (res.forward.y == -1 || res.forward.y == 1)
                tmp = vec_init(1,0,0);
        else
                tmp = vec_init(0,1,0);
        res.right = vec_normalize(cross(tmp, res.forward));
        res.up = vec_normalize(cross(res.forward, res.right));
	return (res);
}
