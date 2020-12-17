/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bditte <bditte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 11:25:36 by bditte            #+#    #+#             */
/*   Updated: 2019/11/18 14:21:50 by bditte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c,
		size_t n)
{
	unsigned char		*udst;
	const unsigned char *usrc;

	udst = dst;
	usrc = src;
	while (n--)
	{
		if (*usrc == (unsigned char)c)
		{
			*udst++ = *usrc++;
			return (udst);
		}
		*udst++ = *usrc++;
	}
	return (NULL);
}
