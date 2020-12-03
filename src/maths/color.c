/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bditte <bditte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 17:59:22 by bditte            #+#    #+#             */
/*   Updated: 2020/11/26 17:59:58 by bditte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	create_rgb(t_vector pixel)
{
	int color;

	color = (int)pixel.x;
	color = (int)(color << 8) + (int)pixel.y;
	color = (int)(color << 8) + (int)pixel.z;
	return (color);
}
