/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bditte <bditte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/28 21:54:31 by bditte            #+#    #+#             */
/*   Updated: 2020/11/30 22:19:39 by bditte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void		display(t_scene *s)
{
	int			x;
	int			y;
	t_vector	pixel;

	s->r.o = s->cams[s->current_cam].pos;
	y = 0;
	while (y < s->data.height)
	{
		x = 0;
		while (x < s->data.width)
		{
			s->r.dir = get_dir(*s, x, y, s->cams[s->current_cam]);
			pixel = trace_ray(*s);
			pixel.x = (int)ft_min(255, ft_max(0, pixel.x));
			pixel.y = (int)ft_min(255, ft_max(0, pixel.y));
			pixel.z = (int)ft_min(255, ft_max(0, pixel.z));
			my_pixel_put(&s->data, x, y, create_rgb(pixel));
			x++;
		}
		y++;
	}
}
