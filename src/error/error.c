/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bditte <bditte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/23 00:09:50 by bditte            #+#    #+#             */
/*   Updated: 2020/12/17 16:05:06 by bditte           ###   ########.fr       */
/*   Updated: 2020/11/22 16:43:24 by bditte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	scene_error(int n)
{
	if (n == -10)
		ft_putstr("Error -10: Invalid resolution.\n");
	if (n == -111)
		ft_putstr("Error -111: Resolution has to be declared only once.\n");
	if (n == -112)
		ft_putstr("Error -112: Ambient light has to be declared once only.\n");
	if (n == -12)
		ft_putstr("Error -12: Invalid ambient light.\n");
	if (n == -13)
		ft_putstr("Error -13: Invalid light.\n");
	if (n == -14)
		ft_putstr("Error -14: Unique element missing.\n");
	if (n == -15)
		ft_putstr("Error -15: Invalid camera.\n");
	if (n == -16)
		ft_putstr("Error -16: Atleast one camera is required.\n");
}

void	objects_error(int n)
{
	if (n == -20)
		ft_putstr("Error -20: Invalid plane\n");
	if (n == -21)
		ft_putstr("Error -21: Invalid triangle\n");
	if (n == -22)
		ft_putstr("Error -22: Invalid cylinder\n");
	if (n == -23)
		ft_putstr("Error -23: Invalid sphere\n");
	if (n == -24)
		ft_putstr("Error -24: Invalid square\n");
	if (n == -25)
		ft_putstr("Error -25: Invalid disk\n");
}

int		error(int n)
{
	if (-30 < n && n < -19)
		objects_error(n);
	if (n <= -10)
		scene_error(n);
	if (n == -1)
		ft_putstr("Error -1: Can not find scene file.\n");
	if (n == -2)
		ft_putstr("Error -2: Invalid element identifier.\n");
	if (n == -3)
		ft_putstr("Error -3: Memory allocation issue.\n");
	if (n == -4)
		ft_putstr("Error -4: Scene file is missing.\n");
	if (n == -5)
		ft_putstr("Error -5: Scene extension is not \".rt\".\n");
	if (n == -6)
		ft_putstr("Error -6: MiniLibX failure.\n");
	if (n == -7)
		ft_putstr("Error -7: Could not create .bmp file.\n");
	if (n == -8)
		ft_putstr("Error -8: Wrong second argument.\n");
	exit(n);
}
