/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bditte <bditte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/18 20:45:10 by bditte            #+#    #+#             */
/*   Updated: 2020/06/18 20:47:08 by bditte           ###   ########.fr       */
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
	float		x1;
	float		x2;
}				t_cylinder;

typedef	struct	s_cyl_vars
{
	t_vector	abc;
	t_vector	p;
	t_vector	v;
	t_vector	pa;
	t_vector	va;
	t_vector	oc;
	t_vector	utils1;
	t_vector	utils2;
	t_vector	vec1;
	t_vector	vec2;
}				t_cyl_vars;
t_cylinder		create_cy(t_vector c, t_vector a, float r, float h, t_vector b);
#endif
