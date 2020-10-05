/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bditte <bditte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/25 02:14:45 by bditte            #+#    #+#             */
/*   Updated: 2020/10/05 16:12:50 by bditte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMAGE_H
# define IMAGE_H
#include "scene.h"

void	my_pixel_put(t_data *data, int x, int y, int color);
int     get_mlx(t_scene *s);
int     close_window(int keycode, t_scene *s);
int     exit_rt(t_scene *s);
int     save_bmp(t_data *data);

#endif
