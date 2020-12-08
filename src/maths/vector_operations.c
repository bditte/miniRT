/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_operations.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bditte <bditte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 18:03:43 by bditte            #+#    #+#             */
/*   Updated: 2020/11/28 20:00:19 by bditte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_vector	vec_add(t_vector vec1, t_vector vec2)
{
	t_vector result;

	result.x = vec1.x + vec2.x;
	result.y = vec1.y + vec2.y;
	result.z = vec1.z + vec2.z;
	return (result);
}

t_vector	vec_multiply_t(float t, t_vector vec)
{
	t_vector result;

	result.x = t * vec.x;
	result.y = t * vec.y;
	result.z = t * vec.z;
	return (result);
}

t_vector	vec_sub(t_vector vec1, t_vector vec2)
{
	t_vector result;

	result.x = vec1.x - vec2.x;
	result.y = vec1.y - vec2.y;
	result.z = vec1.z - vec2.z;
	return (result);
}

t_vector	vec_multi(t_vector a, t_vector b)
{
	t_vector	result;

	result.x = a.x * b.x;
	result.y = a.y * b.y;
	result.z = a.z * b.z;
	return (result);
}
