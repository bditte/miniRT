/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bditte <bditte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/25 18:57:12 by bditte            #+#    #+#             */
/*   Updated: 2020/10/09 17:24:53 by bditte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAM_H
# define CAM_H

# include "vector.h"

typedef	struct	s_cam
{
	t_vector	pos;
	t_vector	axis;
	t_vector	forward;
	t_vector	up;
	t_vector	right;
	int			fov;
}		t_cam;

t_cam	create_cam(t_vector pos, t_vector axis, int fov);
#endif
