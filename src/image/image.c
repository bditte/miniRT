/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bditte <bditte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/25 02:14:00 by bditte            #+#    #+#             */
/*   Updated: 2020/10/05 16:00:50 by bditte           ###   ########.fr       */
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

int     close_window(int keycode, t_scene *s)
{
	if (keycode == 65307)
	{
		if (s->nblights > 0)
			free(s->lights);
		if (s->nbtriangles > 0)
			free(s->triangles);
		if (s->nbplanes > 0)
			free(s->planes);
		if (s->nbspheres > 0)
			free(s->spheres);
		if (s->nbcylinders > 0)
			free(s->cylinders);
		if (s->nbsquares > 0)
			free(s->squares);
		if (s->nbcams > 0)
			free(s->cams);
		mlx_destroy_window(s->data.mlx, s->data.win);
		exit(1);
	}
	return (0);
}

int     exit_rt(t_scene *s)
{
	if (s->nblights > 0)
		free(s->lights);
	if (s->nbtriangles > 0)
		free(s->triangles);
	if (s->nbplanes > 0)
		free(s->planes);
	if (s->nbspheres > 0)
		free(s->spheres);
	if (s->nbcylinders > 0)
		free(s->cylinders);
	if (s->nbsquares > 0)
		free(s->squares);
	if (s->nbcams > 0)
		free(s->cams);
	mlx_destroy_window(s->data.mlx, s->data.win);
	exit(1);
	return (1);
}

