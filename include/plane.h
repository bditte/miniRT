/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bditte <bditte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/18 21:16:45 by bditte            #+#    #+#             */
/*   Updated: 2020/06/18 21:18:46 by bditte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLANE_H
# define PLANE_H

# include "minirt.h"

typedef	struct	s_plane
{
	t_vector	c;
	t_vector	n;
	t_vector	color;
}				t_plane;

t_plane			create_plane(t_vector c, t_vector n, t_vector color);
int				hit_pl(t_plane pl, t_ray r, t_inter *inter);
#endif
