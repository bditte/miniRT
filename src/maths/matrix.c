/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bditte <bditte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/30 14:34:58 by bditte            #+#    #+#             */
/*   Updated: 2020/10/09 17:53:18 by bditte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_vector	mult_point_mat(t_vector v, float m[4][4])
{
	t_vector	r;

	r.x = v.x * m[0][0] + v.y * m[1][0] + v.z + m[2][0] + m[3][0];
	r.y = v.x * m[0][1] + v.y * m[1][1] + v.z + m[2][1] + m[3][1];
	r.z = v.x * m[0][2] + v.y * m[1][2] + v.z + m[2][2] + m[3][2];
	return (r);
}

t_vector	mult_vec_mat(t_vector v, float m[4][4])
{
	t_vector	r;

	r.x = v.x * m[0][0] + v.y * m[1][0] + v.z + m[2][0];
	r.y = v.x * m[0][1] + v.y * m[1][1] + v.z + m[2][1];
	r.z = v.x * m[0][2] + v.y * m[1][2] + v.z + m[2][2];
	return (r);
}

void		get_camtoworld(t_cam cam, float m[4][4])
{

	m[0][0] = cam.right.x;
	m[0][1] = cam.right.y;
	m[0][2] = cam.right.z;
	m[0][3] = 0;
	m[1][0] = cam.up.x;
	m[1][1] = cam.up.y;
	m[1][2] = cam.up.z;
	m[1][3] = 0;
	m[2][0] = cam.forward.x;
	m[2][1] = cam.forward.y;
	m[2][2] = cam.forward.z;
	m[2][3] = 0;
	m[3][0] = cam.pos.x;
	m[3][1] = cam.pos.y;
	m[3][2] = cam.pos.z;
	m[3][3] = 1;
}
