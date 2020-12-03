/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bditte <bditte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/18 20:45:10 by bditte            #+#    #+#             */
/*   Updated: 2020/11/26 17:36:51 by bditte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CYLINDER_H
# define CYLINDER_H

# include "minirt.h"

typedef	struct	s_cylinder
{
	t_vector	c;
	t_vector	axis;
	float		r;
	float		h;
	t_vector	color;
}				t_cylinder;

t_cylinder		create_cy(t_vector c, t_vector a, float r, float h, t_vector b);
#endif
