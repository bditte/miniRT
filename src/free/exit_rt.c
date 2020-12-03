/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_rt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bditte <bditte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 15:15:47 by bditte            #+#    #+#             */
/*   Updated: 2020/12/01 16:13:59 by bditte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	exit_rt(t_scene *s)
{
	free_scene(s);
	mlx_destroy_image(s->data.mlx, s->data.img);
	if (!s->save_bmp)
		mlx_destroy_window(s->data.mlx, s->data.win);
	exit(1);
	return (1);
}
