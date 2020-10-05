/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   square.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bditte <bditte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/23 17:57:33 by bditte            #+#    #+#             */
/*   Updated: 2020/06/23 17:58:54 by bditte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_square	create_sq(t_vector a, t_vector b, float h, t_vector c)
{
	t_square res;

	res.c = a;
	res.axis = b;
	res.height = h;
	res.color = c;

	return (res);
}
