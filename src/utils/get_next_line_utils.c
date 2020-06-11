/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahallain <ahallain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 20:13:58 by ahallain          #+#    #+#             */
/*   Updated: 2019/11/26 18:37:25 by ahallain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		ft_strcchr(char *src, int c)
{
	while (*src)
		if (*src++ == c)
			return (1);
	return (0);
}

size_t	ft_strlen(char *src, int c)
{
	size_t len;

	len = 0;
	while (src[len] && src[len] != c)
		len++;
	return (len);
}

char	*ft_stradd(char **dst, char *str)
{
	char	*res;
	size_t	index;
	size_t	len;

	if (!(res = malloc(ft_strlen(*dst, 0) + ft_strlen(str, 0) + 1)))
		return (NULL);
	len = 0;
	while ((*dst)[len])
	{
		res[len] = (*dst)[len];
		len++;
	}
	index = 0;
	while (str[index])
	{
		res[index + len] = str[index];
		index++;
	}
	res[index + len] = 0;
	free(*dst);
	*dst = res;
	return (res);
}

char	*ft_firstchr(char *src, int c)
{
	char	*res;
	size_t	len;

	len = ft_strlen(src, c);
	if (!(res = malloc(len + 1)))
		return (NULL);
	res[len] = 0;
	while (len--)
		res[len] = src[len];
	return (res);
}

char	*ft_chrmove(char **dst, int c)
{
	char	*res;
	size_t	index;
	size_t	len;

	index = ft_strlen(*dst, c);
	if (!(res = malloc(ft_strlen(*dst, 0) - index + 1)))
		return (NULL);
	len = ft_strlen(*dst, 0) - index;
	res[len] = 0;
	while (len--)
		res[len] = (*dst)[index + 1 + len];
	free(*dst);
	*dst = res;
	return (res);
}
