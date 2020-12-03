/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_args.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bditte <bditte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/23 01:23:11 by bditte            #+#    #+#             */
/*   Updated: 2020/11/28 18:52:07 by bditte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	check_file_extension(char *s)
{
	int i;

	i = 0;
	while (s[i])
		i++;
	if (s[i - 1] != 't' || s[i - 2] != 'r'
		|| s[i - 3] != '.')
		error(-5);
}

int		get_fd(int ac, char **av, t_scene *s)
{
	int	fd;

	if (ac == 1)
		error(-4);
	check_file_extension(av[1]);
	fd = open(av[1], O_RDONLY);
	s->save_bmp = 0;
	if (ac == 3)
	{
		if (!ft_strcmp(av[2], "-save"))
			s->save_bmp = 1;
		else
			error(-8);
	}
	if (fd < 0)
		error(-1);
	return (fd);
}
