/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bditte <bditte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/17 20:42:32 by bditte            #+#    #+#             */
/*   Updated: 2020/11/20 17:58:33 by bditte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

int			ft_strcmp(char *s1, char *s2);
int			ft_isspace(int c);
float		ft_min(float a, float b);
float		ft_max(float a, float b);
float		sqr(float t);
void		*ft_calloc(size_t count, size_t size);
#endif
