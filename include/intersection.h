/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersection.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bditte <bditte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/18 15:19:53 by bditte            #+#    #+#             */
/*   Updated: 2020/11/26 17:38:10 by bditte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERSECTION_H
# define INTERSECTION_H

typedef struct	s_inter
{
	float		t;
	int			i;
	int			type;
	t_vector	point;
	t_vector	n;
	t_vector	p;
	t_vector	color;
	t_vector	offset;
}				t_inter;

#endif
