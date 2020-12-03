/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bditte <bditte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/30 14:50:01 by bditte            #+#    #+#             */
/*   Updated: 2020/12/02 14:59:53 by bditte           ###   ########.fr       */
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
	get_mlx_vars(&s);
	display(&s);
	if (s.save_bmp)
	{
		save_bmp(&(s.data));
		exit_rt(&s);
	}
	else
		create_window(&s);
	return (0);
}
