/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahallain <ahallain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 20:13:27 by ahallain          #+#    #+#             */
/*   Updated: 2019/11/26 18:48:06 by ahallain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	verify(char **memory, int ret)
{
	if (!ret)
	{
		free(*memory);
		*memory = 0;
	}
}

int		get_next_line(int fd, char **line)
{
	static char	*memory[256];
	char		*buffer;
	int			ret;
	int			read_value;

	if (!line || BUFFER_SIZE <= 0 || !(fd + 1)
		|| (!memory[fd] && (!(memory[fd] = malloc(1))
		|| (*memory[fd] = 0)))
		|| !(buffer = malloc(BUFFER_SIZE + 1)))
		return (-1);
	while (!ft_strcchr(memory[fd], '\n')
		&& (read_value = read(fd, buffer, BUFFER_SIZE)) > 0)
	{
		buffer[read_value] = 0;
		ft_stradd(&memory[fd], buffer);
	}
	*line = ft_firstchr(memory[fd], '\n');
	ret = ft_strcchr(memory[fd], '\n');
	ft_chrmove(&memory[fd], '\n');
	free(buffer);
	if (read_value == -1)
		return (-1);
	verify(&memory[fd], ret);
	return (ret);
}
