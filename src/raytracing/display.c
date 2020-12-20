/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bditte <bditte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/28 21:54:31 by bditte            #+#    #+#             */
/*   Updated: 2020/12/20 19:10:58 by bditte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void		display(t_scene *s)
{
	int			x;
	int			y;
	float		rand1;
	float		rand2;
	t_vector	pixel;

	srand(time(NULL));
	s->r.o = s->cams[s->current_cam].pos;
	y = 0;
	while (y < s->data.height)
	{		
		x = 0;
		while (x < s->data.width)
		{
			pixel = vec_init(0, 0, 0);
			if (s->anti_aliasing)
			{
				for (int i = 0; i < AA_COUNT; i++)
				{
					rand1 = x + (float)(rand() % 10) / 10;
					rand2 = y + (float)(rand() % 10) / 10;
					s->r.dir = get_dir(*s, rand1, rand2, s->cams[s->current_cam]);
					pixel = vec_add(pixel, trace_ray(*s));
				}
				pixel = vec_divide_t(AA_COUNT, pixel);
			}
			else
			{
				s->r.dir = get_dir(*s, x, y, s->cams[s->current_cam]);
				pixel = trace_ray(*s);
			}
			pixel.x = (int)ft_min(255, ft_max(0, pixel.x));
			pixel.y = (int)ft_min(255, ft_max(0, pixel.y));
			pixel.z = (int)ft_min(255, ft_max(0, pixel.z));
			my_pixel_put(&s->data, x, y, create_rgb(pixel));
			x++;
		}
		y++;
	}
}
