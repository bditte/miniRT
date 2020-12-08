/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   triangle.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bditte <bditte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/17 20:32:58 by bditte            #+#    #+#             */
/*   Updated: 2020/11/22 02:05:14 by bditte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TRIANGLE_H
# define TRIANGLE_H

typedef struct	s_triangle
{
	t_vector a;
	t_vector b;
	t_vector c;
	t_vector color;
	t_vector edges[3];
	t_vector n;
}				t_triangle;

t_triangle		create_tr(t_vector x, t_vector y, t_vector z, t_vector color);
#endif
