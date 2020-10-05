/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bditte <bditte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/18 12:34:49 by bditte            #+#    #+#             */
/*   Updated: 2020/09/24 13:53:53 by bditte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_vector        color_average(t_vector color1, t_vector color2)
{
        t_vector result;

        result.x = color1.x * color2.x;
        result.y = color1.y * color2.y;
        result.z = color1.z * color2.z;
        return (result);
}
