/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bditte <bditte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/30 14:34:58 by bditte            #+#    #+#             */
/*   Updated: 2020/07/07 17:00:50 by bditte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_vector	mult_vec_mat(t_vector v, float m[4][4])
{
	t_vector	r;
	//float		w;

	r.x = v.x * m[0][0] + v.y * m[1][0] + v.z + m[2][0];// + m[3][0];
	r.y = v.x * m[0][1] + v.y * m[1][1] + v.z + m[2][1];// + m[3][1];
	r.z = -1;//v.x * m[0][2] + v.y * m[1][2] + v.z + m[2][2];// + m[3][2];
	//w = v.x * m[0][3] + v.y * m[1][3] + v.z * m[2][3]; + m[3][3];
	/*if (w != 1 && w != 0)
	{
		r.x = r.x / w;
		r.y = r.y / w;
		r.z = r.z / w;
	}*/
	//printf("%f\n", r.z);
	return (r);
}

void		get_camtoworld(t_vector pos, t_vector dir, float m[4][4])
{
	t_vector	forward;
	t_vector	right;
	t_vector	up;

	//vec_display(pos);
	forward = vec_multiply_t(-1, dir);
	right = cross(vec_normalize(vec_init(0, 1, 0)), forward);
	up = cross(forward, right);
/*	printf("forward\n");
	vec_display(forward);
	printf("rigth\n");
	vec_display(right);
	printf("up\n");
	vec_display(up);*/
	m[0][0] = right.x;
	m[0][1] = right.y;
	m[0][2] = right.z;
	m[0][3] = 0;
	m[1][0] = up.x;
	m[1][1] = up.y;
	m[1][2] = up.z;
	m[1][3] = 0;
	m[2][0] = forward.x;
	m[2][1] = forward.y;
	m[2][2] = forward.z;
	m[2][3] = 0;
	m[3][0] = pos.x;
	m[3][1] = pos.y;
	m[3][2] = pos.z;
	m[3][3] = 1;
}
