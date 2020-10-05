/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bditte <bditte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/18 12:33:50 by bditte            #+#    #+#             */
/*   Updated: 2020/06/19 13:10:46 by bditte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLOR_H
# define COLOR_H

# include "minirt.h"
# include "sphere.h"

t_vector	color_average(t_vector color1, t_vector color2);
int			create_rgb(t_vector pixel);
t_vector	ray_color(t_ray r, t_sphere s);
#endif
