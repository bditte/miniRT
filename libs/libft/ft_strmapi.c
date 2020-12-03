/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bditte <bditte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 11:41:27 by bditte            #+#    #+#             */
/*   Updated: 2019/11/18 14:37:53 by bditte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*str;
	size_t	len;

	len = ft_strlen(s);
	if (!(str = malloc(sizeof(char) * (len + 1))))
		return (NULL);
	str[len] = 0;
	while (len--)
		str[len] = f(len, s[len]);
	return (str);
}
