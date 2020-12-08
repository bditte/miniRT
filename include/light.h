/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bditte <bditte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/18 20:37:25 by bditte            #+#    #+#             */
/*   Updated: 2020/11/30 16:14:18 by bditte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIGHT_H
# define LIGHT_H

# include "minirt.h"

typedef struct	s_light
{
	t_vector	color;
	t_vector	pos;
	t_vector	intensity;
	float		ratio;
}				t_light;

t_light			create_light(t_vector pos, float ratio, t_vector color);
#endif
