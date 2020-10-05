/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bditte <bditte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/23 00:43:25 by bditte            #+#    #+#             */
/*   Updated: 2020/06/23 01:04:59 by bditte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	check_ratio(float ratio)
{
	if (ratio < 0 || ratio > 1)
		return (1);
	return (0);
}

int	check_color(t_vector color)
{
	if (check_ratio(color.x))
		return (1);
	if (check_ratio(color.y))
		return (1);
	if (check_ratio(color.z))
		return (1);
	return (0);
}
