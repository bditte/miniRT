/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   square.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bditte <bditte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/23 17:46:43 by bditte            #+#    #+#             */
/*   Updated: 2020/11/22 15:52:38 by bditte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SQUARE_H
# define SQUARE_H

# include "vector.h"

typedef	struct	s_square
{
	t_vector	c;
	t_vector	axis;
	float		height;
	t_vector	color;
}				t_square;

t_square		create_sq(t_vector a, t_vector b, float h, t_vector c);
#endif
