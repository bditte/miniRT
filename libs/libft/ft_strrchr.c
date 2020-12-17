/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bditte <bditte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 11:44:15 by bditte            #+#    #+#             */
/*   Updated: 2019/11/18 14:47:47 by bditte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*us;
	char	*last;

	us = (char *)s;
	last = NULL;
	while (*us || !c)
	{
		if (!*us)
			return (us);
		if (*us == (char)c)
			last = us;
		us++;
	}
	return (last);
}
