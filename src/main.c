/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bditte <bditte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/30 14:50:01 by bditte            #+#    #+#             */
/*   Updated: 2020/10/10 19:58:01 by bditte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	main(int ac, char **av)
{
	t_scene		s;

	s.data.mlx = mlx_init();
	if (!s.data.mlx)
		error(-6);
	parse(ac, av, &s);
	get_mlx(&s);
	display(&s);
	if (s.save_bmp)
		save_bmp(&(s.data));
	mlx_put_image_to_window(s.data.mlx, s.data.win, s.data.img, 0, 0);
	mlx_hook(s.data.win, 2, 1L << 0, close_window, &s);
	mlx_hook(s.data.win, 17, 1L << 17, exit_rt, &s);
	mlx_loop(s.data.mlx);
}
