/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bditte <bditte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 11:48:24 by bditte            #+#    #+#             */
/*   Updated: 2019/11/18 14:49:52 by bditte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*dst;
	size_t	slen;
	size_t	index;

	if (!(dst = malloc(sizeof(char) * (len + 1))))
		return (NULL);
	slen = 0;
	while (s[slen++])
		;
	s += start;
	index = 0;
	while (len-- && index + start < slen)
	{
		dst[index] = s[index];
		index++;
	}
	dst[index] = 0;
	return (dst);
}
