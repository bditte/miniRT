/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bditte <bditte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 11:26:35 by bditte            #+#    #+#             */
/*   Updated: 2019/11/18 14:23:48 by bditte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char		*udst;
	const unsigned char	*usrc;
	unsigned char		temp;
	size_t				index;

	if (dst == NULL && src == NULL)
		return (NULL);
	udst = dst;
	usrc = src;
	index = len;
	if (usrc > udst)
		while (index--)
		{
			temp = *usrc++;
			*udst++ = temp;
		}
	else
		while (index--)
		{
			temp = usrc[index];
			udst[index] = temp;
		}
	return (dst);
}
