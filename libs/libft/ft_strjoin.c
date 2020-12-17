/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bditte <bditte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 11:39:35 by bditte            #+#    #+#             */
/*   Updated: 2019/11/18 14:30:27 by bditte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*dst;
	size_t	s1len;
	size_t	s2len;

	if (!s1 && !s2)
		return (NULL);
	s1len = 0;
	while (s1[s1len])
		s1len++;
	s2len = 0;
	while (s2[s2len])
		s2len++;
	if (!(dst = malloc(sizeof(char) * (s1len + s2len + 1))))
		return (NULL);
	while (*s1)
		*dst++ = *s1++;
	while (*s2)
		*dst++ = *s2++;
	*dst = 0;
	return (dst - s1len - s2len);
}
