/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bditte <bditte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 16:21:26 by bditte            #+#    #+#             */
/*   Updated: 2020/12/02 16:23:56 by bditte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# include <stdlib.h>
# include <unistd.h>

int		ft_strcchr(char *src, int c);
size_t	ft_strlenc(char *src, int c);
char	*ft_stradd(char **dst, char *str);
char	*ft_firstchr(char *src, int c);
char	*ft_chrmove(char **dst, int c);
int		get_next_line(int fd, char **line);

#endif
