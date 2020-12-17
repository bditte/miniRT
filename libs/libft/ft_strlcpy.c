/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bditte <bditte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 11:40:57 by bditte            #+#    #+#             */
/*   Updated: 2019/11/18 14:31:43 by bditte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	len;

	len = 0;
	while (src[len])
		len++;
	if (dstsize <= 0)
		return (len);
	if (dstsize > len)
		dstsize = len + 1;
	while (*src && dstsize-- - 1)
		*dst++ = *src++;
	*dst = '\0';
	return (len);
}
