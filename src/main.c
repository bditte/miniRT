/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bditte <bditte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/30 14:50:01 by bditte            #+#    #+#             */
/*   Updated: 2020/10/05 16:20:50 by bditte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int main(int ac, char **av)
{
	t_vector pixel;
	int x;
	int y;
	t_vector direction;
	t_vector i_pixel;
	t_scene		s;

	s.data.mlx = mlx_init();
	if (!s.data.mlx)
		error(-6);
	parse(ac, av, &s);
	get_mlx(&s);
	y = 0;
	while (y < s.data.height)
	{
		x = 0;
		while (x < s.data.width)
		{
			s.r = get_dir(s, x, y, s.cams[0]);
			//vec_create(x-s.data.width/2, y-s.data.height/2, (-s.data.width)/(2*tan(fov/2)));
			//s.r = ray_init(s.cams[0].pos, get_dir(s, x, y, s.cams[0]));
		//	vec_display(s.r.dir);
		/*	printf("%f\n", s.r.dir.x);
			printf("%f\n", s.r.dir.y);
			printf("%f\n", s.r.dir.z);
		*/	i_pixel = raytrace(s);
			pixel.x = (int)ft_min(255, ft_max(0, pow(i_pixel.x, 1/2.2)));
			pixel.y = (int)ft_min(255, ft_max(0, pow(i_pixel.y, 1/2.2)));
			pixel.z = (int)ft_min(255, ft_max(0, pow(i_pixel.z, 1/2.2)));
				
			my_pixel_put(&s.data, x, s.data.height - y - 1, create_rgb(pixel));
			x++;
		}
		y++;
	}
	if (s.save_bmp)
		save_bmp(&(s.data));
	mlx_put_image_to_window(s.data.mlx, s.data.win, s.data.img, 0,0);
	mlx_hook(s.data.win, 2,1L<<0,close_window, &s);
	mlx_hook(s.data.win, 17,1L<<17,exit_rt, &s);
	mlx_loop(s.data.mlx);
}
