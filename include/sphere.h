/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bditte <bditte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/18 20:47:44 by bditte            #+#    #+#             */
/*   Updated: 2020/06/27 21:20:43 by bditte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPHERE_H
# define SPHERE_H

# include "minirt.h"

typedef struct	s_sphere
{
	t_vector	c;
	t_vector	albedo;
	float		r;
	int			mirror;
	int			transparent;
}				t_sphere;
t_sphere		create_sphere(t_vector c, float r, t_vector albedo);
int				get_size(t_sphere *list);
#endif
