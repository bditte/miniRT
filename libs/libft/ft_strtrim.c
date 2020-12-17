/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bditte <bditte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 11:47:49 by bditte            #+#    #+#             */
/*   Updated: 2019/11/18 14:48:30 by bditte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		contain(char c, char const *set)
{
	while (*set)
		if (*set++ == c)
			return (1);
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	len;
	size_t	lencpy;
	char	*dst;

	while (contain(*s1++, set))
		;
	len = ft_strlen(s1);
	s1 += len;
	while (contain(*--s1, set))
		len--;
	len++;
	if (!(dst = malloc(sizeof(char) * (len + 1))))
		return (NULL);
	s1 -= len - 1;
	lencpy = len;
	while (lencpy--)
		*dst++ = *s1++;
	*dst = 0;
	return (dst - len);
}
