/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_key.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bditte <bditte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/10 19:14:51 by bditte            #+#    #+#             */
/*   Updated: 2020/12/01 16:15:29 by bditte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	switch_cam(t_scene *s, int keycode)
{
	if (keycode == 65363)
	{
		if (s->current_cam < s->nbcams - 1)
		{
			s->current_cam++;
			display(s);
			mlx_put_image_to_window(s->data.mlx,
				s->data.win, s->data.img, 0, 0);
		}
	}
	else
	{
		if (s->current_cam > 0)
		{
			s->current_cam--;
			display(s);
			mlx_put_image_to_window(s->data.mlx,
				s->data.win, s->data.img, 0, 0);
		}
	}
	return (0);
}

int	handle_key(int keycode, t_scene *s)
{
	if (keycode == 65307)
		exit_rt(s);
	if (s->nbcams > 1 && (keycode == 65363 || keycode == 65361))
		switch_cam(s, keycode);
	return (0);
}
