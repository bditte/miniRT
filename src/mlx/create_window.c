/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_window.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bditte <bditte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/25 02:14:00 by bditte            #+#    #+#             */
/*   Updated: 2020/12/01 16:48:08 by bditte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	get_mlx_vars(t_scene *s)
{
	if (!s->save_bmp)
		s->data.win = mlx_new_window(s->data.mlx, s->data.width,
			s->data.height, "minirt");
	if (!s->data.win && !s->save_bmp)
		error(-6);
	s->data.img = mlx_new_image(s->data.mlx, s->data.width, s->data.height);
	if (!s->data.img)
		error(-6);
	s->data.addr = mlx_get_data_addr(s->data.img, &s->data.bpp,
			&s->data.line_length, &s->data.endian);
	return (0);
}

int	ft_put_img_to_window(t_scene *s)
{
	mlx_put_image_to_window(s->data.mlx, s->data.win, s->data.img, 0, 0);
	return (0);
}

int	create_window(t_scene *s)
{
	mlx_loop_hook(s->data.mlx, ft_put_img_to_window, s);
	mlx_key_hook(s->data.win, handle_key, s);
	mlx_hook(s->data.win, 33, 1L << 17, exit_rt, s);
	mlx_loop(s->data.mlx);
	return (0);
}
