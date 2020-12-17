/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bditte <bditte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 17:12:00 by ahallain          #+#    #+#             */
/*   Updated: 2020/11/30 19:52:17 by bditte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*get_chars(va_list args, int n)
{
	char	*chars;
	
	if (!(chars = malloc(sizeof(char) * n + 1)))
		return (NULL);
	chars[n] = 0;
	while (--n >= 0)
		chars[n] = va_arg(args, int);
	return (chars);
}

int	ft_is_c(char c, char *chars)
{
	int i;

	i = -1;
	while (chars[++i])
	{
		if (c == chars[i])
			return (1);
	}
	return (0);
}

size_t		ft_count(char const *s, char *c)
{
	size_t	index;
	size_t	len;
	size_t	count;

	index = 0;
	len = 0;
	count = 0;
	while (s[index + len])
	{
		if (ft_is_c(s[index + len], c))
			if (len)
			{
				count++;
				index += len;
				len = 0;
			}
			else
				index++;
		else
			len++;
	}
	if (len)
		return (count + 1);
	return (count);
}

char		*ft_write(char const *s, size_t index, size_t len)
{
	char	*str;
	size_t	index1;

	if (!(str = malloc(sizeof(char) * (len + 1))))
		return (NULL);
	index1 = 0;
	while (s[index] && len--)
		str[index1++] = s[index++];
	str[index1] = 0;
	return (str);
}

char		**ft_set(char const *s, char *c, char **tab)
{
	size_t	index;
	size_t	index1;
	size_t	len;

	index = 0;
	index1 = 0;
	len = 0;
	while (s[index + len])
	{
		if (ft_is_c(s[index + len], c))
			if (len)
			{
				tab[index1++] = ft_write(s, index, len);
				index += len;
				len = 0;
			}
			else
				index++;
		else
			len++;
	}
	if (len)
		tab[index1++] = ft_write(s, index, len);
	tab[index1] = 0;
	return (tab);
}

char		**ft_split(char const *s, int n, ...)
{
	char	**tab;
	char	*c;
	va_list	args;

	va_start(args, n);
	c = get_chars(args, n);
	if (!(tab = malloc(sizeof(char*) * (ft_count(s, c) + 1))))
		return (NULL);
	tab = ft_set(s, c, tab);
	va_end(args);
	free(c);
	return (tab);
}
