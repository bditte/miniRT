/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_options.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bditte <bditte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/20 18:43:50 by bditte            #+#    #+#             */
/*   Updated: 2020/12/20 19:28:00 by bditte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	parse_aa(char **line, t_scene *scene)
{
	if (nb_elem(line) != 2)
		error(-17);
	if (ft_strlen(line[1]) != 1)
		error(-17);
	if (line[1][0] == '1')
		scene->anti_aliasing += AA_COUNT + 1;
	else if (line[1][0] == '0')
		scene->anti_aliasing += 1;
	else
		error(-17);
}
