/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bditte <bditte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 14:14:22 by bditte            #+#    #+#             */
/*   Updated: 2019/11/18 14:14:29 by bditte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

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
