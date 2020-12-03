/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bditte <bditte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/05 12:50:25 by bditte            #+#    #+#             */
/*   Updated: 2020/11/28 21:39:58 by bditte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	*ft_calloc(size_t count, size_t size)
{
	unsigned char	*tab;

	if (!(tab = malloc(count * size)))
		return (NULL);
	count *= size;
	while (count--)
		tab[count] = 0;
	return (tab);
}
