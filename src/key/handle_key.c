/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_key.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bditte <bditte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/10 19:14:51 by bditte            #+#    #+#             */
/*   Updated: 2020/10/10 19:59:33 by bditte           ###   ########.fr       */
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

int	close_window(int keycode, t_scene *s)
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
	if (s->nbcams > 1 && (keycode == 65363 || keycode == 65361))
		switch_cam(s, keycode);
	return (0);
}

int	exit_rt(t_scene *s)
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
