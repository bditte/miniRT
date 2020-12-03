/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bditte <bditte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 11:39:20 by bditte            #+#    #+#             */
/*   Updated: 2019/11/18 14:30:00 by bditte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*s2;
	size_t	index;
	size_t	len;

	len = 0;
	while (s1[len])
		len++;
	if (!(s2 = malloc(sizeof(char) * (len + 1))))
		return (NULL);
	index = 0;
	while (s1[index])
	{
		s2[index] = s1[index];
		index++;
	}
	s2[index] = 0;
	return (s2);
}
