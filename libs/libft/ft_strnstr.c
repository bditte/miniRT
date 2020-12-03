/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bditte <bditte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 11:44:01 by bditte            #+#    #+#             */
/*   Updated: 2019/11/18 14:44:54 by bditte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	index;
	size_t	index1;

	if (!*needle)
		return ((char*)haystack);
	index = 0;
	while (haystack[index] && len - index)
	{
		if (haystack[index] == *needle)
		{
			index1 = 0;
			while (haystack[index + index1] == needle[index1]
				&& len - index - index1)
			{
				index1++;
				if (!needle[index1])
					return ((char*)haystack + index);
			}
			index += index1;
		}
		else
			index++;
	}
	return (NULL);
}
