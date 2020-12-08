/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bditte <bditte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/25 02:14:45 by bditte            #+#    #+#             */
/*   Updated: 2020/11/30 22:20:11 by bditte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMAGE_H
# define IMAGE_H
# include "scene.h"

void	my_pixel_put(t_data *data, int x, int y, int color);
int		get_mlx_vars(t_scene *s);
int		save_bmp(t_data *data);
int		ft_put_img_to_window(t_scene *s);
int		create_window(t_scene *s);
#endif
