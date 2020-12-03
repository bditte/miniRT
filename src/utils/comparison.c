/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   comparison.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bditte <bditte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 15:50:28 by bditte            #+#    #+#             */
/*   Updated: 2020/11/28 21:38:34 by bditte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

float	ft_min(float a, float b)
{
	if (b > a)
		return (a);
	return (b);
}

float	ft_max(float a, float b)
{
	if (b < a)
		return (a);
	return (b);
}

float	sqr(float t)
{
	return (t * t);
}

int		ft_isspace(int c)
{
	c = (unsigned char)c;
	if (c == '\t' || c == '\n' || c == '\v' || c == '\f' || c == '\r'
			|| c == ' ')
		return (1);
	return (0);
}
