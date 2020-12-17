/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bditte <bditte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 11:26:15 by bditte            #+#    #+#             */
/*   Updated: 2019/11/18 14:23:11 by bditte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char	*str;

	if (dst == NULL && src == NULL)
		return (dst);
	str = dst;
	while (n--)
	{
		str[n] = ((char*)src)[n];
	}
	return (dst);
}
