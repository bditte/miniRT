/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bditte <bditte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/25 02:14:00 by bditte            #+#    #+#             */
/*   Updated: 2020/10/10 19:16:40 by bditte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void    my_pixel_put(t_data *data, int x, int y, int color)
{
	char    *dst;

	dst = data->addr + (y * data->line_length + x * (data->bpp / 8));
	*(unsigned int *)dst = color;
}

int	get_mlx(t_scene *s)
{
	s->data.win = mlx_new_window(s->data.mlx, s->data.width, s->data.height, "minirt");
	if (!s->data.win)
		error(-6);
	s->data.img = mlx_new_image(s->data.mlx, s->data.width, s->data.height);
	if (!s->data.img)
		error(-6);
	s->data.addr = mlx_get_data_addr(s->data.img, &s->data.bpp, &s->data.line_length, &s->data.endian);
	mlx_put_image_to_window(s->data.mlx, s->data.win, s->data.img, 0,0);

	return (0);
}

