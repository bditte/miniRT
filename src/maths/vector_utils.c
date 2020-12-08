/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bditte <bditte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 18:02:08 by bditte            #+#    #+#             */
/*   Updated: 2020/12/02 16:11:59 by bditte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_vector	vec_init(float x, float y, float z)
{
	t_vector vec;

	vec.x = x;
	vec.y = y;
	vec.z = z;
	return (vec);
}

int			vec_cmp(t_vector v1, t_vector v2)
{
	if (v1.x == v2.x && v1.y == v2.y && v1.z == v2.z)
		return (1);
	return (0);
}
